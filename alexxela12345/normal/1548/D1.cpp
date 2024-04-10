#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> cnt(2, vector<int> (2));
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a/=2;
    b/=2;
    cnt[a % 2][b % 2]++;
  }
  ll ans1 = 0, ans2 = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ans1 += 1LL * cnt[i][j] * (cnt[i][j] - 1) * (n - 2) / 2;
      ans2 += 1LL * cnt[i][j] * (cnt[i][j] - 1) * (cnt[i][j] - 2) / 6;
    }
  }
  cerr << ans1 << endl;
  cerr << ans2 << endl;
  cout << ans1 - ans2 * 2 << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}