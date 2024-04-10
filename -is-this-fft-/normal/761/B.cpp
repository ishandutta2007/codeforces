#include <iostream>
#include <algorithm>

const int MAX_BARRIER = 55;

using namespace std;

int alpha [MAX_BARRIER], beta [MAX_BARRIER];

int main () {
  int barrierc, length;
  cin >> barrierc >> length;

  for (int i = 0; i < barrierc; i++) {
    cin >> alpha[i];
  }

  for (int i = 0; i < barrierc; i++) {
    cin >> beta[i];
  }

  for (int i = 0; i < 2 * length; i++) {
    bool flag = true;
    for (int j = 0; j < barrierc; j++) {
      if (alpha[j] != beta[j]) {
        flag = false;
      }
    }
    
    if (flag) {
      cout << "YES" << endl;
      return 0;
    }

    for (int j = 0; j < barrierc; j++) {
      alpha[j]++;
      alpha[j] %= length;
    }

    sort(alpha, alpha + barrierc);
  }
  cout << "NO" << endl;
}