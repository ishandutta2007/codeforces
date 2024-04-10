// LUOGU_RID: 91280679
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
#define y1 y_chensiyuan_1

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
  template<class T> inline void rprint(T x) {if(x >= 10) rprint(x / 10); pc(x % 10 + '0');}
  template<class T> inline void print(T x) {if(x < 0) pc('-'), x = -x; rprint(x);}
}
using namespace IO;

template<class T1, class T2> void cmin(T1 &a, T2 b) {a = a < b ? a : b;}
template<class T1, class T2> void cmax(T1 &a, T2 b) {a = a > b ? a : b;}

constexpr int mod = 998244353;
int ksm(int a, int b) {
  int s = 1;
  while(b) {
    if(b & 1) s = 1ll * s * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return s;
}

constexpr int N = 3e5 + 5;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
ll n, m, p, q, f[N];
string s[N];
vector<pii> e[N];
priority_queue<pll, vector<pll>, greater<pll>> qu; 
int ind(int x, int y) {return x * m + y;} 
void solve() {
  cin >> n >> m >> p >> q;
  memset(f, 0x3f, sizeof(f));
  for(int i = 0; i < n; i++) cin >> s[i];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      int id = ind(i, j);
      if(s[i][j] == '.') f[id] = 0, qu.push({0, id});
      auto add = [&](int u, int v, int w) {
        if(u < 0 || u >= n || v < 0 || v >= m) return;
        e[ind(u, v)].push_back({id, w});
      };
      if(s[i][j] == 'L') add(i, j + 2, q), add(i + 1, j + 1, p), add(i - 1, j + 1, p);
      if(s[i][j] == 'R') add(i, j - 2, q), add(i + 1, j - 1, p), add(i - 1, j - 1, p);
      if(s[i][j] == 'U') add(i + 2, j, q), add(i + 1, j + 1, p), add(i + 1, j - 1, p);
      if(s[i][j] == 'D') add(i - 2, j, q), add(i - 1, j + 1, p), add(i - 1, j - 1, p);
    }
  while(!qu.empty()) {
    pll t = qu.top();
    qu.pop();
    int id = t.second;
    if(f[id] != t.first) continue;
    for(pii _ : e[id]) {
      int it = _.first;
      ll d = f[id] + _.second;
      if(d < f[it]) qu.push({f[it] = d, it});
    }
  }
  ll ans = inf;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      if(j + 1 < m) ans = min(ans, f[ind(i, j)] + f[ind(i, j + 1)]);
      if(i + 1 < n) ans = min(ans, f[ind(i, j)] + f[ind(i + 1, j)]);
    }
  if(ans == inf) ans = -1;
  cout << ans << "\n";
}
int main() {
//  ios::sync_with_stdio(0);
  int T = 1;
//  cin >> T;
  while(T--) solve();
  return 0;
}