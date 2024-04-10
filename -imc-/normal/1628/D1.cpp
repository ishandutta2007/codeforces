#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

li MOD = 1e9 + 7;

//vector<vector<li>> ans;
const int maxN = 2005;
int ans[maxN][maxN];

void solve(bool read = true) {
  li N, M, k;
  if (read) {
    cin >> N >> M >> k;
  } else {
    N = M = 2000;
    k = 1;
  }

  li inv2 = 500000004;
  //ans.assign(N + 1, vector<li>(N + 1));

  for (int n = 0; n <= N; ++n) {
    for (int m = 0; m <= n; ++m) {
      if (n == m) {
        ans[n][m] = k * n % MOD;
      } else if (m == 0) {
        ans[n][m] = 0;
      } else {
        ans[n][m] = (ans[n - 1][m] + ans[n - 1][m - 1]) * inv2 % MOD;
      }
    }
  }

  cout << ans[N][M] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#if 1
  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }
#else
  for (int i = 0; i < 1000; ++i) {
    solve(false);
  }
#endif

  return 0;
}