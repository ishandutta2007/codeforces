// LUOGU_RID: 91463523
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using uint = unsigned int;
using ld = long double;
// using lll = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
inline ll read() {
  ll x = 0, sgn = 0;
  char s = getchar();
  while(!isdigit(s)) sgn |= s == '-', s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return sgn ? -x : x;
}
inline void print(ll x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
constexpr int N = 5e3 + 5;
constexpr int mod = 998244353;
constexpr int iv6 = (mod + 1) / 6;
void add(int &x, int y) {x += y, x >= mod && (x -= mod);}
int S1(int x) {return 1ll * x * (x + 1) / 2 % mod;}
int S2(int x) {return 1ll * x * (x + 1) % mod * (x + x + 1) % mod * iv6 % mod;}
int n, t, ans, d[N];
int pre[N], nxt[N], buc[N];
struct point {
  int x, y;
  bool operator < (const point &z) const {return x < z.x;}
} p[N];
int calc(int x, int y) {
  x = 2 * t + 1 - x, y = 2 * t + 1 - y;
  if(x <= 0 || y <= 0) return 0;
  int ans = 1ll * (t + 1) * x % mod * y % mod;
  int lim = min(x, y) >> 1;
  add(ans, mod - 1ll * (lim + 1) * x % mod * y % mod);
  add(ans, 2ll * (x + y) * S1(lim) % mod);
  add(ans, mod - 4ll * S2(lim) % mod);
  return ans;
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n >> t, ans = 1ll * n * calc(0, 0) % mod;
  for(int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y, d[i] = p[i].y;
  sort(p + 1, p + n + 1), sort(d + 1, d + n + 1);
  for(int i = 1; i <= n; i++) p[i].y = lower_bound(d + 1, d + n + 1, p[i].y) - d;
  for(int l = 1; l < n; l++) {
    memset(buc, 0, sizeof(buc));
    for(int r = l; r <= n; r++) buc[p[r].y]++;
    int lst = 0;
    for(int i = 1; i <= n; i++) if(buc[i]) pre[i] = lst, nxt[lst] = i, lst = i;
    nxt[lst] = 0;
    for(int r = n; r > l; r--) {
      int u = p[l].y, v = p[r].y, dis = p[r].x - p[l].x;
      if(buc[u] == 1 + (u == v) && buc[v] == 1 + (u == v)) {
        bool swp = false;
        if(u > v) swp = true, swap(u, v);
        if(u == v || nxt[u] == v) {
          add(ans, mod - calc(dis, d[v] - d[u]));
          if(pre[u]) add(ans, calc(dis, d[v] - d[pre[u]]));
          if(nxt[v]) add(ans, calc(dis, d[nxt[v]] - d[u]));
          if(pre[u] && nxt[v]) add(ans, mod - calc(dis, d[nxt[v]] - d[pre[u]]));
        }
        if(swp) swap(u, v);
      }
      if(!--buc[v]) pre[nxt[v]] = pre[v], nxt[pre[v]] = nxt[v];
    }
  }
  cout << ans << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/10/25
author: Alex_Wei
start coding at 15:06
finish debugging at 15:32
*/