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

constexpr int mod = 1e9 + 7;
int ksm(int a, int b) {
  int s = 1;
  while(b) {
    if(b & 1) s = 1ll * s * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return s;
}

constexpr int N = 1e6 + 5;
int n, ans[N], pw[N], fc[N], ifc[N], f[N], s[N];
int bin(int n, int m) {return 1ll * fc[n] * ifc[m] % mod * ifc[n - m] % mod;}
void solve() {
  cin >> n;
  if(n == 1) return puts("1"), void();
  f[n] = s[n] = 1, s[n + 1] = 0;
  for(int i = n - 1; i > 1; i--) {
    f[i] = (s[i + 1] + mod - s[min(n + 1, i * 2)]) % mod;
    s[i] = (s[i + 1] + f[i]) % mod;
    ans[i] = 1ll * f[i] * pw[i / 2 + 1] % mod;
  }
  puts("0");
  ans[n] = pw[n];
  for(int i = n - 1; i; i--) ans[n] = (ans[n] + mod - ans[i]) % mod;
  int iv = ksm(pw[n], mod - 2);
  for(int i = 2; i <= n; i++) cout << 1ll * ans[i] * iv % mod << "\n";
}
int main() {
//  ios::sync_with_stdio(0);
  for(int i = pw[0] = 1; i < N; i++) pw[i] = 1ll * pw[i - 1] * 2 % mod;
  for(int i = fc[0] = 1; i < N; i++) fc[i] = 1ll * fc[i - 1] * i % mod;
  ifc[N - 1] = ksm(fc[N - 1], mod - 2);
  for(int i = N - 2; ~i; i--) ifc[i] = 1ll * ifc[i + 1] * (i + 1) % mod;
  int T = 1;
  cin >> T;
  while(T--) solve();
  return 0;
}