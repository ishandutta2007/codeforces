#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

deque<char> alpha [2];

int main () {
  ios::sync_with_stdio(false);

  string oleg, igor;
  cin >> oleg >> igor;
  
  for (int i = 0; i < (int) oleg.size(); i++) {
    alpha[0].push_back(oleg[i]);
    alpha[1].push_back(igor[i]);
  }

  sort(alpha[0].begin(), alpha[0].end(), less<char> ());
  sort(alpha[1].begin(), alpha[1].end(), greater<char> ());

  while ((int) alpha[0].size() > ((int) oleg.size() + 1) / 2) {
    alpha[0].pop_back();
  }

  while ((int) alpha[1].size() > (int) oleg.size() / 2) {
    alpha[1].pop_back();
  }

  deque<char> leftc, rightc;
  for (int i = 0; i < (int) oleg.size(); i++) {
    if (i % 2 == 0) {
      if (alpha[1].front() <= alpha[0].front()) {
        rightc.push_front(alpha[0].back());
        alpha[0].pop_back();
      } else {
        leftc.push_back(alpha[0].front());
        alpha[0].pop_front();
      }
    } else {
      if (alpha[0].front() >= alpha[1].front()) {
        rightc.push_front(alpha[1].back());
        alpha[1].pop_back();
      } else {
        leftc.push_back(alpha[1].front());
        alpha[1].pop_front();
      }
    }
  }

  for (int i = 0; i < (int) leftc.size(); i++) {
    cout << leftc[i];
  }

  for (int i = 0; i < (int) rightc.size(); i++) {
    cout << rightc[i];
  }
  cout << endl;
}