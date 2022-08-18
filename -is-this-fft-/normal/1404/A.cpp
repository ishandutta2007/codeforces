#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve () {
  int n, K;
  cin >> n >> K;

  vector<int> has0 (K, 0);
  vector<int> has1 (K, 0);
  string s;
  cin >> s;

  for (int i = 0; i < n; i++) {
    if (s[i] == '0') has0[i % K]++;
    if (s[i] == '1') has1[i % K]++;
  }

  int c0 = 0, c1 = 0;
  for (int i = 0; i < K; i++) {
    if (has0[i] && has1[i]) {
      cout << "NO" << '\n';
      return;
    } else if (has0[i]) {
      c0++;
    } else if (has1[i]) {
      c1++;
    }
  }

  if (2 * max(c0, c1) > K) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}