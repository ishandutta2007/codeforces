// #pragma GCC optimize(3)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define db double
#define ll long long
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define vint vector<int>
#define vpii vector<pii>
 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define pb emplace_back
#define all(x) begin(x), end(x)
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define mem(x, v, s) memset(x, v, sizeof(x[0]) * (s))
#define cpy(x, y, s) memcpy(x, y, sizeof(x[0]) * (s))
#define FileI(x) freopen(x, "r", stdin)
#define FileO(x) freopen(x, "w", stdout)
#define y1 y_chenxiaoyan_1

bool Mbe;
namespace IO {
  char buf[1 << 21], *p1 = buf, *p2 = buf, Obuf[1 << 24], *O = Obuf;
  #define gc getchar()
//  #define gc (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
  #define pc(x) (*O++ = x)
  #define flush() fwrite(Obuf, 1, O - Obuf, stdout)
  inline ll read() {
    ll x = 0; bool sgn = 0; char s = gc;
    while(!isdigit(s)) sgn |= s == '-', s = gc;
    while(isdigit(s)) x = x * 10 + s - '0', s = gc;
    return sgn ? -x : x;
  }
  template<class T>
    inline void rprint(T x) {if(x >= 10) rprint(x / 10); pc(x % 10 + '0');}
  template<class T>
    inline void print(T x) {if(x < 0) pc('-'), x = -x; rprint(x);}
}
using namespace IO;

template<class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template<class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

constexpr int mod = 998244353;
int ksm(int a, int b) {
  int s = 1;
  while(b) {
    if(b & 1) s = 1ll * s * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return s;
}

constexpr int N = 500 + 5;
constexpr int M = 3e5 + 5;
int n, m, u[M], v[M], w[M], dis[N][N];
void solve() {
  cin >> n >> m;
  memset(dis, 0x0f, sizeof(dis));
  for(int i = 1; i <= n; i++) dis[i][i] = 0;
  for(int i = 1; i <= m; i++) {
    u[i] = read(), v[i] = read(), w[i] = read();
    dis[u[i]][v[i]] = dis[v[i]][u[i]] = 1;
  }
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  ll ans = 1e18;
  for(int i = 1; i <= m; i++) {
    int coef = N * 2, x = u[i], y = v[i];
    coef = min(coef, dis[1][x] + dis[n][y]);
    coef = min(coef, dis[1][y] + dis[n][x]);
    for(int p = 1; p <= n; p++) coef = min(coef, min(dis[y][p], dis[x][p]) + 1 + dis[p][1] + dis[p][n]);
    ans = min(ans, 1ll * (coef + 1) * w[i]);
  }
  cout << ans << "\n";
}
int main() {
//  ios::sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while(T--) solve();
  return 0;
}