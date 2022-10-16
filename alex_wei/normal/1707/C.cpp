//#pragma GCC optimize(3)

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
//	#define gc (p1 == p2 && (p2 = (p1 = buf) + \
		fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
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
constexpr int K = 20;
int n, m, u[N], v[N], add[N], fa[N];
vector<int> e[N];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
int dn, dfn[N], sz[N];
int dep[N], anc[K][N];
bool isanc(int u, int v) {return dfn[u] <= dfn[v] && dfn[v] < dfn[u] + sz[u];}
void dfs(int id, int ff) {
	dfn[id] = ++dn;
	sz[id] = 1;
	anc[0][id] = ff;
	dep[id] = dep[ff] + 1;
	for(int i = 1; i < K; i++) anc[i][id] = anc[i - 1][anc[i - 1][id]];
	for(int it : e[id]) if(it != ff) dfs(it, id), sz[id] += sz[it];
}
int kth(int u, int k) {
	for(int i = K - 1; ~i; i--)
		if(k >> i & 1)
			u = anc[i][u];
	return u;
}
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i];
		int x = find(u[i]), y = find(v[i]);
		if(x != y) {
			fa[y] = x;
			add[i] = 1;
			e[u[i]].push_back(v[i]);
			e[v[i]].push_back(u[i]);
		}
	}
	dfs(1, 0);
	static int d[N];
	memset(d, 0, sizeof(d));
	auto upd = [&](int x, int v) {
		d[dfn[x]] += v;
		d[dfn[x] + sz[x]] -= v;
	};
	for(int i = 1; i <= m; i++) {
		if(add[i]) continue;
		int x = u[i], y = v[i];
		if(isanc(y, x)) swap(x, y);
		if(isanc(x, y)) {
			int d = kth(y, dep[y] - dep[x] - 1);
			upd(d, 1), upd(y, -1);
		}
		else upd(1, 1), upd(x, -1), upd(y, -1);
	}
	for(int i = 1; i <= n; i++) d[i] += d[i - 1];
	for(int i = 1; i <= n; i++)
		if(d[dfn[i]]) cout << '0';
		else cout << '1';
	cout << endl;
}
int main() {
	int T = 1;
//	cin >> T;
	while(T--) solve();
	return 0;
}