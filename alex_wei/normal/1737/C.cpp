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

constexpr int N = 2e5 + 5;
int n, a, b, c, d, e, f, x, y;
void solve() {
  cin >> n >> a >> b >> c >> d >> e >> f >> x >> y;
  int cx = a == c ? a : a == e ? a : c;
  int cy = b == d ? b : b == f ? b : d;
  if(cx == 1 && cy == 1) {
    if(x == 1 || y == 1) puts("YES");
    else puts("NO");
  }
  else if(cx == 1 && cy == n) {
    if(x == 1 || y == n) puts("YES");
    else puts("NO");
  }
  else if(cx == n && cy == 1) {
    if(x == n || y == 1) puts("YES");
    else puts("NO");
  }
  else if(cx == n && cy == n) {
    if(x == n || y == n) puts("YES");
    else puts("NO");
  }
  else if((abs(x - cx) & 1) && (abs(y - cy) & 1)) puts("NO");
  else puts("YES");
}
int main() {
//  ios::sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while(T--) solve();
  return 0;
}