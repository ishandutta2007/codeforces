#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ldb long double

#define endl '\n'

void solve() {
  int n;
  cin >> n;
  int m, q;
  cin >> m >> q;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  vector<int> c((1 << n));
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        c[mask] += w[i];
      }
    }
  }
  vector<int> cnt(1 << n);
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    int mask = 0;
    for (int j = 0; j < n; j++) {
      if (s[j] == '1')
        mask += 1 << j;
    }
    cnt[mask]++;
  }
  vector<vector<int>> ans(1 << n, vector<int> (102));
  for (int m1 = 0; m1 < (1 << n); m1++) {
    for (int m2 = 0; m2 < (1 << n); m2++) {
      ans[m1][min(101LL, c[((1 << n) - 1) ^ m1 ^ m2])] += cnt[m2];
    }
    for (int i = 0; i < 101; i++) {
      ans[m1][i + 1] += ans[m1][i];
    }
  }
  while (q--) {
    string s;
    cin >> s;
    int mask = 0;
    for (int j = 0; j < n; j++) {
      if (s[j] == '1')
        mask += 1 << j;
    }
    int k;
    cin >> k;
    cout << ans[mask][k] << endl;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--)
    solve();
}