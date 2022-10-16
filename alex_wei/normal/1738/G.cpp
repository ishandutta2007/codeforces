#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3 + 5;
int n, k, f[N][N], vis[N][N], limit[N][N];
char s[N][N];
void cmax(int &x, int y) {x = x > y ? x : y;}
void solve() {
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> s[i] + 1;
  for(int i = 0; i <= n + 1; i++)
    for(int j = 0; j <= n + 1; j++)
      limit[i][j] = vis[i][j] = f[i][j] = 0;
  for(int i = n; i; i--)
    for(int j = n; j; j--) {
      f[i][j] = f[i + 1][j + 1] + (s[i][j] == '0');
      cmax(f[i][j], max(f[i + 1][j], f[i][j + 1]));
      if(f[i][j] == k) return puts("NO"), void();
      if(!limit[f[i][j]][j]) limit[f[i][j]][j] = i;
    }
  for(int i = 1; i < k; i++)
    for(int j = n; j; j--)
      limit[i][j] = max(limit[i][j], limit[i][j + 1]);
  for(int i = 1; i <= n; i++) vis[0][i] = 1;
  for(int i = i; i < k; i++) {
    int x = n, y = i;
    while(y <= n) {
      vis[x][y] = 1;
      if(x == limit[k - i][y + 1]) y++;
      else if(vis[x - 1][y]) y++;
      else x--;
    }
  }
  puts("YES");
  for(int i = 1; i <= n; i++, cout << "\n")
    for(int j = 1; j <= n; j++)
      cout << vis[i][j];
}
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}