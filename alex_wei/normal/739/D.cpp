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
	int read() {
		int x = 0; bool sgn = 0; char s = gc;
		while(!isdigit(s)) sgn |= s == '-', s = gc;
		while(isdigit(s)) x = x * 10 + s - '0', s = gc;
		return sgn ? -x : x;
	}
	char rdc() {char s = gc; while(!isalpha(s)) s = gc; return s;}
	char rdd() {char s = gc; while(!isdigit(s)) s = gc; return s;}
	template <class T>
		void rprint(T x) {if(x >= 10) rprint(x / 10); pc(x % 10 + '0');}
	template <class T>
		void print(T x) {if(x < 0) pc('-'), x = -x; rprint(x);}
} using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

int rd() {
	int x = 0; string s; cin >> s;
	if(s == "?") return -1;
	for(char it : s) x = x * 10 + it - '0';
	return x;
}

const int N = 300 + 5;
const int M = 2e5 + 5;
int n, h[N], l[N], ans[N];

struct Dinic {
	int T, cnt, hd[N << 1], nxt[M], to[M], lim[M];
	void init() {cnt = 1, mem(hd, 0, N << 1);}
	void add(int u, int v, int w) {
		nxt[++cnt] = hd[u], hd[u] = cnt, to[cnt] = v, lim[cnt] = w;
		nxt[++cnt] = hd[v], hd[v] = cnt, to[cnt] = u, lim[cnt] = 0;
	}
	int dis[N << 1], cur[N << 1];
	bool BFS() {
		queue <int> q; q.push(0);
		mem(dis, -1, N << 1), cpy(cur, hd, N << 1), dis[0] = 0;
		while(!q.empty()) {
			int t = q.front(); q.pop();
			for(int i = hd[t]; i; i = nxt[i])
				if(lim[i] && dis[to[i]] == -1)
					dis[to[i]] = dis[t] + 1, q.push(to[i]);
		} return dis[T] != -1;
	}
	int DFS(int id, int res) {
		if(id == T || !res) return res;
		int flow = 0;
		for(int i = cur[id]; i && res; i = nxt[i]) {
			int it = to[i], c = min(lim[i], res); cur[id] = i;
			if(c && dis[id] + 1 == dis[it]) {
				int k = DFS(it, c);
				flow += k, res -= k, lim[i] -= k, lim[i ^ 1] += k;
			}
		} if(!flow) dis[id] = -1;
		return flow;
	}
	int MF(int _T) {
		int flow = 0; T = _T;
		while(BFS()) flow += DFS(0, 1e9);
		return flow;
	}
} G;

int mxd, ap[N], cnt[N], mx[N];
int T, x[N], y[N], ban[N << 1]; // x = h, y = l
bool check() {
	T = 0, G.init();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= cnt[i]; j++) {
			x[++T] = 0, y[T] = i;
			if(T > n) return 0;
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= mx[i]; j++) {
			x[++T] = j, y[T] = i;
			if(T > n) return 0;
		}
//	for(int i = 1; i <= T; i++)
//		cerr << "x y " << x[i] << " " << y[i] << endl;
	int flow = 0; mem(ban, 0, N << 1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= T && !ban[i]; j++)
			if(!ban[j + n] && h[i] == x[j] && l[i] == y[j])
				ban[i] = ban[j + n] = 1, flow++;
//	for(int i = 1; i <= n; i++) if(!ban[i]) assert(l[i] == -1 || h[i] == -1 || flow == T);
	for(int i = 1; i <= n; i++) if(!ban[i])
		for(int j = 1; j <= T; j++) if(!ban[j + n])
			if((h[i] == -1 || h[i] == x[j]) && (l[i] == -1 || l[i] == y[j]))
				G.add(i, j + n, 1);
	for(int i = 1; i <= n; i++) if(!ban[i]) G.add(0, i, 1);
	for(int i = 1; i <= T; i++) if(!ban[i + n]) G.add(i + n, n + T + 1, 1);
	return flow + G.MF(n + T + 1) == T;
}
void answer(int I) {
	for(int i = 1; i <= n; i++) if(!ban[i])
		for(int j = G.hd[i]; j; j = G.nxt[j])
			if(G.lim[j] == 0 && G.to[j])
				cerr << i << " " << G.to[j] << " " << x[G.to[j] - n] << " " << y[G.to[j] - n] << endl,
				h[i] = x[G.to[j] - n], l[i] = y[G.to[j] - n];
	int cnt = 0;
//	for(int i = 1; i <= n; i++) cerr << "h " << h[i] << " " << l[i] << endl;
	for(int i = 1; i <= n; i++) if(l[i] == 18) cnt += h[i] == 0;
	cerr << cnt << endl;
	static int pt[N][N];
	vint buc[N]; mem(pt, -1, N);
	for(int i = 1; i <= n; i++) {
		if(l[i] == -1 && h[i] == -1) h[i] = 0, l[i] = 1;
		if(l[i] == -1) l[i] = h[i] == 0 ? 1 : I;
		if(h[i] == -1) h[i] = 1;
		else if(h[i] == 0) buc[l[i]].pb(i);
		pt[h[i]][l[i]] = i;
	}
//	for(int i = 1; i <= n; i++) cerr << "h " << h[i] << " " << l[i] << endl;
	for(int i = 1; i <= n; i++) if(h[i])
		ans[i] = pt[h[i] - 1][l[i]];
//		cout << i << " " << pt[h[i] - 1][l[i]] << endl;
//	cerr << buc[1].size() << endl;
	for(int i = 1; i <= n; i++) {
//		cerr << i << " " << buc[i].size() << endl;
		assert(buc[i].size() % i == 0);
		for(int j = 0; j < buc[i].size(); j += i)
			for(int k = 0; k < i; k++)
				ans[buc[i][j + k]] = buc[i][j + (k + 1) % i];
//				cout << buc[i][j + k] << " " << buc[i][j + (k + 1) % i] << endl;
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}
bool Med;
int main() {
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		h[i] = rd(), l[i] = rd();
//		cin >> h[i] >> l[i];
		if(l[i] != -1) ap[l[i]] = 1;
		if(h[i] == -1) continue;
		if(l[i] == -1) cmax(mxd, h[i]);
		else {
			if(!h[i]) cnt[l[i]]++;
			cmax(mx[l[i]], h[i]);
		}
	}
	static int buc[N]; cpy(buc, cnt, N);
	for(int i = 1; i <= n; i++)
		if(ap[i]) cnt[i] = (max(0, (cnt[i] - 1) / i) + 1) * i;
	int tot = 0;
	for(int i = 1; i <= n; i++) tot += cnt[i];
	if(tot > n) puts("-1"), exit(0);
	vint pos;
	if(mxd) for(int i = 1; i <= n; i++)
		if(l[i] == -1 && h[i] == mxd) pos.pb(i);
	for(int i = 1; i <= n; i++) {
		int omx = mx[i], oc = cnt[i]; cmax(mx[i], mxd);
		if(!ap[i]) cnt[i] = i;
		for(int it : pos) l[it] = i;
		if(check()) cerr << i << endl, answer(i), exit(0);
		mx[i] = omx, cnt[i] = oc;
	} puts("-1"), exit(0);
	return flush(), 0;
}

/*
0
7
2 -1
-1 3
1 3
-1 2
-1 -1
0 -1
-1 -1

0
3
1 -1
1 2
-1 -1

0
5
0 1
0 1
3 1
2 1
1 1

0
1
-1 -1

0
2
-1 -1
-1 2
*/