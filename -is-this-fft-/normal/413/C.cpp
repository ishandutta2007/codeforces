#include <iostream>
#include <algorithm>

const int MAX_QUEST = 105;

typedef long long llong;

using namespace std;

struct question {
  llong price, auct;
} questions [MAX_QUEST];

bool operator< (question p, question q) {
  if (p.auct == q.auct) {
    if (!p.auct) {
      return p.price < q.price;
    } else {
      return p.price > q.price;
    }
  } else {
    return p.auct < q.auct;
  }
}

int main () {
  int questc, auctc;
  cin >> questc >> auctc;

  for (int i = 0; i < questc; i++) {
    cin >> questions[i].price;
  }

  for (int i = 0; i < auctc; i++) {
    int quest;
    cin >> quest;

    questions[quest - 1].auct = true;
  }

  sort(questions, questions + questc);
  
  llong ans = 0;
  for (int i = 0; i < questc; i++) {
    if (!questions[i].auct) {
      ans += questions[i].price;
    } else if (ans > questions[i].price) {
      ans *= 2;
    } else {
      ans += questions[i].price;
    }
  }

  cout << ans << endl;
}