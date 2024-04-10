#include <bits/stdc++.h>
using namespace std;
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
bool Mbe;
constexpr int N = 2e3 + 5;
constexpr int K = 50 + 5;
constexpr int mod = 998244353;
void add(int &x, int y) {x += y, x >= mod && (x -= mod);}
int ksm(int a, int b) {
  int s = 1;
  while(b) {
    if(b & 1) s = 1ll * s * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return s;
}
int fc[N], ifc[N];
int n, k, b[N], f[K << 1][N], g[K << 1][N], tmp[K << 1][N];
bool Med;
int main() {
  fprintf(stderr, "%.4lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin >> n >> k;
  for(int i = fc[0] = 1; i <= n; i++) fc[i] = 1ll * fc[i - 1] * i % mod;
  ifc[n] = ksm(fc[n], mod - 2);
  for(int i = n - 1; ~i; i--) ifc[i] = 1ll * ifc[i + 1] * (i + 1) % mod;
  for(int i = 1; i <= n; i++) cin >> b[i];
  f[k][0] = 1;
  for(int i = 0; i < n; i++) {
    memset(g, 0, sizeof(g));
    memset(tmp, 0, sizeof(tmp));
    for(int mex = -k; mex <= k; mex++)
      for(int cnt = 0, val; cnt <= i; cnt++)
        if(val = f[k + mex][cnt]) {
          int rmex = b[i] + mex;
          assert(rmex + cnt + 1 <= n);
          add(tmp[mex + k][rmex + cnt + 1], 1ll * val * fc[cnt] % mod);
          int _mex = rmex - b[i + 1];
          if(_mex >= -k && _mex <= k) {
            add(g[_mex + k][cnt], 1ll * val * (rmex + cnt) % mod);
            add(g[_mex + k][cnt + 1], val);
          }
        }
    for(int sum = 0; sum <= i + 1; sum++) {
      for(int mex = -k + 1; mex <= k; mex++) add(tmp[mex + k][sum], tmp[mex + k - 1][sum]);
      for(int _mex = -k; _mex <= k; _mex++) {
        int _rmex = b[i + 1] + _mex;
        if(_rmex < 0 || _rmex > sum) continue;
        int _cnt = sum - _rmex;
        int mxmex = min(k, _rmex - 1 - b[i]);
        if(mxmex < -k) continue;
        add(g[_mex + k][_cnt], 1ll * tmp[mxmex + k][sum] * ifc[_cnt] % mod);
      }
    }
    swap(f, g);
  }
  int ans = 0;
  for(int mex = -k; mex <= k; mex++)
    for(int cnt = 0, val; cnt <= n; cnt++)
      if(val = f[k + mex][cnt]) {
        int rmex = b[n] + mex;
        assert(rmex + cnt <= n);
        add(ans, 1ll * val * fc[n - rmex] % mod * ifc[n - rmex - cnt] % mod);
      }
  cout << ans << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/8/7
start coding at 18:25
finish debugging at 18:45
*/