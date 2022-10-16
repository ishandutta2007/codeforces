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
} using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

const int N = 2e5 + 5;

int n, k, tot, num, son[N], mxd[N], buc[N]; ll ans = -1e18;
int cnt, hd[N], nxt[N << 1], to[N << 1];
void add(int u, int v) {nxt[++cnt] = hd[u], hd[u] = cnt, to[cnt] = v;}
void dfs(int id, int f) {
	mxd[id] = 1;
	for(int i = hd[id]; i; i = nxt[i]) if(to[i] != f) {
		dfs(to[i], id), cmax(mxd[id], mxd[to[i]] + 1);
		if(mxd[to[i]] > mxd[son[id]]) son[id] = to[i];
	}
}
void dfs2(int id, int f, int t) {
	if(son[id]) dfs2(son[id], id, t); else buc[++num] = mxd[t];
	for(int i = hd[id]; i; i = nxt[i]) if(to[i] != f && to[i] != son[id]) dfs2(to[i], id, to[i]);
}
ll cal(ll r, ll b) {return 1ll * (n - r - b) * (r - b);}
int main() {
	cin >> n >> k;
	for(int i = 1, u, v; i < n; i++) u = read(), v = read(), add(u, v), add(v, u);
	dfs(1, 0), dfs2(1, 0, 1);
	if(num <= k) for(int i = 0; i <= k; i++) cmax(ans, 1ll * (n - i) * i);
	else {
		ans = 1e18, sort(buc + 1, buc + num + 1), reverse(buc + 1, buc + num + 1);
		for(int i = 1; i <= k; i++) tot += buc[i];
		for(int i = 0; i <= n - tot; i++) cmin(ans, 1ll * (n - i - k) * (k - i));
	}
	cout << ans << endl;
	return flush(), 0;
}