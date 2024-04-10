#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool Mbe;
constexpr int N = 1 << 20;
int n, m;
ll f[N], g[N], h[N];
char s[20][N];
void FWT(ll *f, int tp) {
  for(int k = 1; k < 1 << n; k <<= 1)
    for(int i = 0; i < 1 << n; i += k << 1)
      for(int j = 0; j < k; j++) {
        ll x = f[i | j], y = f[i | j | k];
        f[i | j] = x + y, f[i | j | k] = x - y;
      }
  if(tp == -1) for(int i = 0; i < 1 << n; i++) f[i] >>= n;
}
bool Med;
int main() {
  fprintf(stderr, "%.4lf\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> s[i];
  for(int i = 0; i < m; i++) {
    int T = 0;
    for(int j = 0; j < n; j++) if(s[j][i] == '1') T |= 1 << j;
    f[T]++;
  }
  for(int i = 0; i < 1 << n; i++) {
    int ppc = __builtin_popcount(i);
    g[i] = min(ppc, n - ppc);
  }
  FWT(f, 1), FWT(g, 1);
  for(int i = 0; i < 1 << n; i++) h[i] = f[i] * g[i];
  FWT(h, -1);
  ll ans = 1e18;
  for(int i = 0; i < 1 << n; i++) ans = min(ans, h[i]);
  cout << ans << endl;
  return cerr << "Time: " << clock() << "\n", 0;
}
/*
2022/7/
start coding at 15:01
finish debugging at 15:24
*/