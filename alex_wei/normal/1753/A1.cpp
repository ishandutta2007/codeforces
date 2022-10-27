// LUOGU_RID: 91279639
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

constexpr int N = 2e5 + 5;
int n, a[N];
void solve() {
  cin >> n;
  vector<int> buc;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    if(a[i]) buc.push_back(i);
  }
  if(buc.size() & 1) return puts("-1"), void();
  vector<pii> ans;
  int lst = 0;
  for(int i = 0; i < buc.size(); i += 2) {
    if(lst + 1 < buc[i]) ans.push_back({lst + 1, buc[i] - 1});
    if(a[buc[i]] != a[buc[i + 1]]) {
      ans.push_back({buc[i], buc[i + 1] - 1});
      ans.push_back({buc[i + 1], buc[i + 1]});
    }
    else if(buc[i + 1] - buc[i] & 1) ans.push_back({buc[i], buc[i + 1]});
    else {
      ans.push_back({buc[i], buc[i + 1] - 2});
      ans.push_back({buc[i + 1] - 1, buc[i + 1]});
    }
    lst = buc[i + 1];
  }
  if(lst < n) ans.push_back({lst + 1, n});
  cout << ans.size() << "\n";
  for(pii it : ans) cout << it.first << " " << it.second << "\n";
}
int main() {
//  ios::sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while(T--) solve();
  return 0;
}