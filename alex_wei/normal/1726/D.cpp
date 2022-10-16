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
#define vint vector <int>
#define vpii vector <pii>

#define pii pair <int, int>
#define pll pair <ll, ll>
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
//	#define gc (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
	#define pc(x) (*O++ = x)
	#define flush() fwrite(Obuf, 1, O - Obuf, stdout)
	inline ll read() {
		ll x = 0; bool sgn = 0; char s = gc;
		while(!isdigit(s)) sgn |= s == '-', s = gc;
		while(isdigit(s)) x = x * 10 + s - '0', s = gc;
		return sgn ? -x : x;
	}
	template <class T>
		inline void rprint(T x) {if(x >= 10) rprint(x / 10); pc(x % 10 + '0');}
	template <class T>
		inline void print(T x) {if(x < 0) pc('-'), x = -x; rprint(x);}
}
using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

const int mod = 998244353;
int ksm(int a, int b) {
	int s = 1;
	while(b) {
		if(b & 1) s = 1ll * s * a % mod;
		a = 1ll * a * a % mod, b >>= 1;
	}
	return s;
}

constexpr int N = 2e5 + 5;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int n, m, c[N], c0, c1, vis[N];
vector<pii> e[N];
void dfs0(int id, int ff) {
  vis[id] = 1;
  for(pii it : e[id]) {
    if(it.first == ff) continue;
    if(c[it.second]) continue;
    if(vis[it.first]) c0 = 1;
    else dfs0(it.first, id);
  }
}
void dfs1(int id, int ff) {
  vis[id] = 1;
  for(pii it : e[id]) {
    if(it.first == ff) continue;
    if(!c[it.second]) continue;
    if(vis[it.first]) c1 = 1;
    else dfs1(it.first, id);
  }
}
void solve() {
  n = read(), m = read();
  for(int i = 1; i <= n; i++) e[i].clear();
  for(int i = 1; i <= m; i++) {
    int u = read(), v = read();
    e[u].push_back({v, i});
    e[v].push_back({u, i});
  }
  while(1) {
    for(int i = 1; i <= m; i++) c[i] = rnd() & 1;
    c0 = c1 = 0;
    for(int i = 1; i <= n; i++) vis[i] = 0;
    for(int i = 1; i <= m; i++) if(!vis[i]) dfs0(i, 0);
    for(int i = 1; i <= n; i++) vis[i] = 0;
    for(int i = 1; i <= m; i++) if(!vis[i]) dfs1(i, 0);
    if(!c0 && !c1) {
      for(int i = 1; i <= m; i++) cout << c[i];
      cout << "\n";
      return;
    }
  }
}
int main() {
//	ios::sync_with_stdio(0);
	int T = 1;
	cin >> T;
	while(T--) solve();
	return 0;
}