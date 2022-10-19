#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<string> ans(n, string(n, '.'));
  int k = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + j) % 2 == 0) {
        ans[i][j] = 'C';
        k++;
      }
    }
  }
  cout << k << endl;
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}