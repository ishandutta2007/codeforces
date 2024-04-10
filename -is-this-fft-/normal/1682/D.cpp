#include <iostream>

using namespace std;

void solve () {
  int n;
  cin >> n;

  string S;
  cin >> S;

  int odd = -1, codd = 0;
  for (int i = 0; i < n; i++) {
    if (S[i] == '1') {
      odd = i;
      codd++;
    }
  }

  if (codd % 2 == 1 || codd == 0) {
    cout << "NO" << '\n';
    return;
  }

  cout << "YES" << '\n';
  int start = (odd + 1) % n;
  int cur = -1;
  for (int i = (start + 1) % n; i != start; i = (i + 1) % n) {
    if (cur == -1) {
      cout << 1 + start << " " << 1 + i << '\n';
    } else {
      cout << 1 + cur << " " << 1 + i << '\n';
      cur = -1;
    }

    if (S[i] == '0') {
      cur = i;
    }
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}