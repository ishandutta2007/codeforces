#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int ALPHA = 130;

void solve () {
  string s, t, p;
  cin >> s >> t >> p;

  // is s a subsequence of t?
  int sPtr = 0;
  for (char c : t) {
    if (c == s[sPtr]) {
      sPtr++;
    }

    if (sPtr == (int) s.size()) {
      break;
    }
  }

  if (sPtr < (int) s.size()) {
    cout << "NO" << '\n';
    return;
  }

  vector<short> pCnt (ALPHA, 0);
  vector<short> tCnt (ALPHA, 0);

  for (char c : t) {
    tCnt[c]++;
  }

  for (char c : p) {
    pCnt[c]++;
  }

  for (char c : s) {
    tCnt[c]--;
  }

  for (int i = 0; i < ALPHA; i++) {
    if (pCnt[i] < tCnt[i]) {
      cout << "NO" << '\n';
      return;
    }
  }

  cout << "YES" << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}