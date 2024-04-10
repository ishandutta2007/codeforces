#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 100010;
const int INF = 1000 * 1000 * 1000;

int n, m, ver[N], hor[N];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", ver + i);
  }
  int _m = 0;
  for (int i = 1; i <= m; ++i) {
    int x_1, x_2, y;
    scanf("%d %d %d", &x_1, &x_2, &y);
    if (x_1 != 1) continue;
    hor[++_m] = x_2;
  }
  m = _m;
  ver[++n] = INF;
  sort(ver + 1, ver + n + 1);
  sort(hor + 1, hor + m + 1);
  int ans = INF + INF;
  for (int i = 1, j = 1; i <= n; ++i) {
    while (j <= m and hor[j] < ver[i]) ++j;
    ans = min(ans, m + i - j);
  }
  cout << ans << '\n';
  return 0;
}