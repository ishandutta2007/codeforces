#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 100;

bool u[M][M];

int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  if (n < 7) {
    cout << m << "\n";
    return 0;
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a,--b;
    u[a][b] = true;
    u[b][a] = true;
  }

  int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      int sub = 0; //u[i][j] ? 1 : 0;
      for (int t = 0; t < n; ++t)
        if (t != i && t != j && u[i][t] && u[j][t])
          ++sub;

      ans = max(ans, m - sub);
    }
  cout << ans << "\n";

}