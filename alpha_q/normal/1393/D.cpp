#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

char g[N][N];
int n, m, big[N][N];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", g[i] + 1);
  }
  for (int i = n; i >= 1; --i) {
    for (int j = 1; j <= m; ++j) {
      big[i][j] = 1;
      if (i + 2 <= n and j > 1 and j < m and g[i][j] == g[i + 1][j - 1] and g[i][j] == g[i + 1][j] and g[i][j] == g[i + 1][j + 1] and g[i][j] == g[i + 2][j]) {
        big[i][j] = 1 + min({big[i + 1][j - 1], big[i + 1][j + 1], big[i + 2][j]});
      }
    }
  }
  long long ans = 0;
  for (int j = 1; j <= m; ++j) {
    int at = 1;
    for (int i = 1; i <= n; ++i) {
      while (at + big[at][j] <= i) ++at;
      // cout << i << " " << j << " --> " << at << endl;
      ans += i - at + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}