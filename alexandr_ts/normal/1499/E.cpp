#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e3 + 10;

int dp[N][N][2][2][2];

void add(int& x, int val) {
  x += val;
  if (x >= MOD) {
    x -= MOD;
  }
}

void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      dp[i + 1][j][0][1][0] = 1;
      dp[i][j + 1][1][0][1] = 1;
    }
  }

  auto get_last = [&](int last, int i, int j) -> char {
    if (last == 0) {
      assert(i);
      return s[i - 1];
    }
    assert(j);
    return t[j - 1];
  };

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      for (int last = 0; last <= 1; ++last) {
        for (int a = 0; a <= 1; ++a) {
          for (int b = 0; b <= 1; ++b) {
            if (!dp[i][j][last][a][b]) continue;
            if (j < m && get_last(last, i, j) != t[j]) {
              add(dp[i][j + 1][1][a][1], dp[i][j][last][a][b]);
            }
            if (i < n && get_last(last, i, j) != s[i]) {
              add(dp[i + 1][j][0][1][b], dp[i][j][last][a][b]);
            }
          }
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      for (int last = 0; last <= 1; ++last) {
        add(ans, dp[i][j][last][1][1]);
      }
    }
  }
  cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
    solve();
	}
}