#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

char g[N][N];
int n, m, a[N], cnt[10];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", g[i] + 1);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", a + i);
  }
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    memset(cnt, 0, sizeof cnt);
    for (int j = 1; j <= n; ++j) {
      ++cnt[g[j][i] - 'A'];
    }
    int yo = *max_element(cnt, cnt + 5);
    ans += yo * a[i];
  }
  cout << ans << '\n';
  return 0;
}