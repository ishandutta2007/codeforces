#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 100100;
const int T = 11;

int m, n;
int a[T][M];
int nx[T][M];
int cnt[T][M];
bool u[M];
int ans[M];

void read() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      --a[i][j];
    }
}

int dfs(int x) {
  if (u[x])
    return ans[x];
  u[x] = true;

  int cur = nx[0][x];
  bool ok = true;
  
  for (int i = 0; i < m; ++i)
    ok &= nx[i][x] == cur;

  if (ok && cur >= 0)
    return ans[x] = 1 + dfs(cur);
  else
    return ans[x] = 1;
}

void kill() {
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j) {
      if (j + 1 < n) 
        nx[i][a[i][j]] = a[i][j + 1];
      else 
        nx[i][a[i][j]] = -100 - i;
    }

  ll ans = 0;
  for (int x = 0; x < n; ++x)
    ans += dfs(x);
  cout << ans << "\n";
}


int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}