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
	char buf[1 << 21], *p1 = buf, *p2 = buf, Obuf[1 << 24], *oO = Obuf;
 	#define gc getchar()
//	#define gc (p1 == p2 && (p2 = (p1 = buf) + \
		fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
	#define pc(x) (*oO++ = x)
	#define flush() fwrite(Obuf, 1, oO - Obuf, stdout)
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

const int N = 2e3 + 5;
const int M = 4e3 + 5;

ll n, m, T, ans;
struct network {
	int cnt = 1, hd[N], nxt[M << 1], to[M << 1], lim[M << 1];
	void add(int u, int v, int w) {
		nxt[++cnt] = hd[u], hd[u] = cnt, to[cnt] = v, lim[cnt] = w;
		nxt[++cnt] = hd[v], hd[v] = cnt, to[cnt] = u, lim[cnt] = 0;
	}
	int dis[N], cur[N];
	ll dfs(int id, ll res) {
		if(id == T || !res) return res;
		ll flow = 0;
		for(int i = cur[id]; i && res; i = nxt[i]) {
			int it = to[i], c = min(res, (ll)lim[i]); cur[id] = i;
			if(dis[id] + 1 == dis[it] && c) {
				int k = dfs(it, c);
				res -= k, flow += k, lim[i] -= k, lim[i ^ 1] += k;
			}
		} if(!flow) dis[id] = -1;
		return flow;
	}
	ll MF() {
		ll flow = 0;
		while(1) {
			queue <int> q; q.push(0);
			cpy(cur, hd, N), mem(dis, -1, N), dis[0] = 0;
			while(!q.empty()) {
				int t = q.front(); q.pop();
				for(int i = hd[t]; i; i = nxt[i])
					if(dis[to[i]] == -1 && lim[i])
						dis[to[i]] = dis[t] + 1, q.push(to[i]);
			} if(dis[T] == -1) return flow;
			flow += dfs(0, 1e18);
		}
	}
} flow;

bool Med;
int main() {
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	cin >> n >> m, T = n + m + 1;
	for(int i = 1; i <= n; i++) flow.add(i, T, read());
	for(int i = 1, u, v, w; i <= m; i++)
		u = read(), v = read(), w = read(),
		flow.add(n + i, u, 1e18), flow.add(n + i, v, 1e18),
		flow.add(0, n + i, w), ans += w;
	cout << ans - flow.MF() << endl;
	return 0;
}