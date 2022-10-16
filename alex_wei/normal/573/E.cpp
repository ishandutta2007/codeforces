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
bool Mbe;
constexpr int N = 1e5 + 5;
mt19937 rnd(0);
int n, R, node, ls[N], rs[N], rd[N], sz[N];
ll val[N], laz[N];
void push(int x) {sz[x] = sz[ls[x]] + sz[rs[x]] + 1;}
void tag(int x, ll v) {val[x] += v, laz[x] += v;}
void down(int x) {if(laz[x]) tag(ls[x], laz[x]), tag(rs[x], laz[x]), laz[x] = 0;}
int nwnode(ll v) {int x = ++node; sz[x] = 1, val[x] = v, rd[x] = rnd(); return x;}
ll sum(int x) {if(!x) return 0; return down(x), sum(ls[x]) + sum(rs[x]) + val[x];}
void split(int p, int &x, int &y, int acc, ll v) {
  if(!p) return x = y = 0, void();
  down(p);
  int coef = acc + sz[ls[p]] + 1;
  if(v * coef <= val[p]) split(rs[p], rs[x = p], y, coef, v);
  else split(ls[p], x, ls[y = p], acc, v);
  push(p);
}
int merge(int x, int y) {
  if(!x || !y) return x | y;
  down(x), down(y);
  if(rd[x] > rd[y]) return rs[x] = merge(rs[x], y), push(x), x;
  return ls[y] = merge(x, ls[y]), push(y), y;
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int a = read(), x, y;
    split(R, x, y, 0, a), tag(y, a);
    R = merge(merge(x, nwnode(1ll * a * (sz[x] + 1))), y);
  }
  int x, y;
  split(R, x, y, 0, 0), cout << sum(x) << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/10/15
author: Alex_Wei
start coding at 14:01
finish debugging at 14:23
*/