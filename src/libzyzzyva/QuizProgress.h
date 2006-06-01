//---------------------------------------------------------------------------
// QuizProgress.h
//
// A class to represent quiz progress.
//
// Copyright 2005, 2006 Michael W Thelen <mthelen@gmail.com>.
//
// This file is part of Zyzzyva.
//
// Zyzzyva is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// Zyzzyva is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//---------------------------------------------------------------------------

#ifndef ZYZZYVA_QUIZ_PROGRESS_H
#define ZYZZYVA_QUIZ_PROGRESS_H

#include <QDomElement>
#include <QMap>
#include <set>

class QuizProgress
{
    public:
    QuizProgress() : question (0), correct (0), incorrect (0), missed (0),
                     questionComplete (false) { }
    ~QuizProgress() { }

    bool isEmpty() const;

    void setQuestion (int q) { question = q; }
    void setCorrect (int c) { correct = c; }
    void addIncorrect (const QString& word);
    void addIncorrect (const QString& word, int count);
    void addMissed (const QString& word);
    void addMissed (const QString& word, int count);
    void addQuestionCorrect (const QString& word);
    void clearQuestionCorrect() { questionCorrectWords.clear(); }
    void setQuestionComplete (bool b) { questionComplete = b; }

    int getQuestion() const { return question; }
    int getNumCorrect() const { return correct; }
    int getNumIncorrect() const { return incorrect; }
    int getNumMissed() const { return missed; }
    bool getQuestionComplete() const { return questionComplete; }

    std::set<QString> getQuestionCorrect() const {
        return questionCorrectWords; }
    QMap<QString, int> getIncorrect() const { return incorrectWords; }
    QMap<QString, int> getMissed() const { return missedWords; }

    QDomElement asDomElement() const;
    bool fromDomElement (const QDomElement& element);

    private:
    int question;
    int correct;
    int incorrect;
    int missed;
    bool questionComplete;
    std::set<QString> questionCorrectWords;
    QMap<QString, int> incorrectWords;
    QMap<QString, int> missedWords;
};

#endif // ZYZZYVA_QUIZ_PROGRESS_H
