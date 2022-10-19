#include<bits/stdc++.h>
#define int long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int MAXM = 33333, MAXN = 15555;
namespace Dinic {
	struct edge {
		int to, nxt, cap;
	} e[MAXM << 1];
	int S, T, dep[MAXN], head[MAXN], cur[MAXN], tot;
	void init() {
		memset(head, -1, sizeof head);
		tot = 1;
	}
	void add(int u, int v, int cap) {
		e[++tot] = (edge) {v, head[u], cap};
		head[u] = tot;
		e[++tot] = (edge) {u, head[v], 0};
		head[v] = tot;
	}
	queue<int> q;
	bool bfs() {
		memset(dep, -1, sizeof dep);
		q.push(S);
		dep[S] = 0;
		while (SZ(q)) {
			int u = q.front();
			q.pop();
			cur[u] = head[u];
			for (int i = head[u]; ~i; i = e[i].nxt) {
				int v = e[i].to, cap = e[i].cap;
				if (dep[v] == -1 && cap > 0) {
					dep[v] = dep[u] + 1;
					q.push(v);
				}
			}
		}
		return dep[T] != -1;
	}
	int dfs(int u, int dis) {
		if (u == T || dis == 0) return dis;
		int flow = 0;
		for (int i = cur[u]; ~i; i = e[i].nxt) {
			cur[u] = i;
			int v  = e[i].to, cap = e[i].cap;
			if (dep[v] == dep[u] + 1 && cap > 0) {
				int f = dfs(v, min(dis, cap));
				if (f > 0) {
					dis -= f;
					flow += f;
					e[i].cap -= f;
					e[i ^ 1].cap += f;
					if (dis == 0) break;
				}
			}
		}
		return flow;
	}
	int dinic() {
		int ans = 0;
		while (bfs()) {
			ans += dfs(S, INT_MAX);
		}
		return ans;
	}
}
using namespace Dinic;
const int N = 10015;
int n, m, g, v[N], gender[N];
signed main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%lld%lld%lld", &n, &m, &g);
	S = n + 1; T = n + 2;
	init();
	rep(i, 1, n) scanf("%lld", &gender[i]);
	rep(i, 1, n) scanf("%lld", &v[i]);
	rep(i, 1, n) {
		if(gender[i] == 0) add(i, T, v[i]);
		else add(S, i, v[i]);
	}
	int ans = 0, cnt = n + 2;
	rep(_, 1, m) {
		int gd, good, w, k, x;
		cnt++;
		scanf("%lld%lld%lld", &gd, &w, &k);
		ans += w;
		rep(i, 1, k) {
			scanf("%lld", &x);
			if(gd == 0) add(x, cnt, INT_MAX);
			else add(cnt, x, INT_MAX);
		}
		scanf("%lld", &good);
		if(gd == 0) add(cnt, T, w + good * g);
		else add(S, cnt, w + good * g);
	}
	printf("%lld\n", ans - dinic());
	return 0;
}