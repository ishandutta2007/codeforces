#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(m);
  vector<pair<int, int>> cnt(n);
  for (int i = 0; i < n; ++i) {
    cnt[i] = {0, i};
  }
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    g[i].resize(k);
    for (int j = 0; j < k ;++j) {
      cin >> g[i][j];
      g[i][j]--;
      cnt[g[i][j]].first++;
    }
  }
  sort(cnt.begin(), cnt.end());
  reverse(cnt.begin(), cnt.end());
  int best = cnt[0].second;
  vector<int> ans(m);
  int left = (m + 1) / 2;
  for (int i = 0; i < m; ++i) {
    if (g[i].size() == 1) {
      ans[i] = g[i][0] + 1;
      if (g[i][0] == best) {
        left--;
      }
    }
  }
  if (left < 0) {
    cout << "NO\n";
    return;
  }
  for (int i = 0; i < m; ++i) {
    if (g[i].size() == 1) continue;
    if (left > 0) {
      bool fnd = false;
      for (auto j: g[i]) {
        if (j == best) {
          fnd = true;
          ans[i] = best + 1;
          left--;
          break;
        }
      }
      if (!fnd) {
        ans[i] = g[i][0] + 1;
      }
    } else {
      bool fnd = false;
      for (auto j: g[i]) {
        if (j != best) {
          fnd = true;
          ans[i] = j + 1;
          break;
        }
      }
      assert(fnd);
    }
  }
  cout << "YES\n";
  for (auto x: ans) {
    cout << x << " ";
  }
  cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
  cin >> t;
	while (t--) {
		solve();
	}
}