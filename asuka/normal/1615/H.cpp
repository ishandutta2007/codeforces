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
const int N = 1015;
int n, m, a[N], _a[N], ans[N];
VI e[N];
struct MaxFlow {
	struct edge {
		int to, nxt, cap;
	} e[N << 2];
	int n, S, T, tot = 1, head[N], cur[N];
	bool res[N];
	void clear() {
		for(; n > 0; n--) res[n] = head[n] = 0;
		tot = 1;
	}
	void add(int u, int v, int cap) {
		e[++tot] = (edge) {v, head[u], cap};
		head[u] = tot;
		e[++tot] = (edge) {u, head[v], 0};
		head[v] = tot;
	}
	int dep[N];
	queue<int> q;
	bool bfs() {
		rep(i, 1, n) dep[i] = -1;
		dep[S] = 0;
		q.push(S);
		while(SZ(q)) {
			int u = q.front(); q.pop();
			cur[u] = head[u];
			for(int i = head[u]; i; i = e[i].nxt) {
				int v = e[i].to, cap = e[i].cap;
				if(cap > 0 && dep[v] == -1) {
					dep[v] = dep[u] + 1;
					q.push(v);
				}
			}
		}
		return dep[T] != -1;
	}
	int dfs(int u, int dis) {
		if(u == T || dis == 0) return dis;
		int flow = 0;
		for(int i = cur[u]; i; i = e[i].nxt) {
			cur[u] = i;
			int v = e[i].to, cap = e[i].cap;
			if(dep[v] == dep[u] + 1 && cap > 0) {
				int f = dfs(v, min(cap, dis));
				if(f > 0) {
					dis -= f;
					flow += f;
					e[i].cap -= f;
					e[i ^ 1].cap += f;
					if(dis == 0) break;
				}
			}
		}
		return flow;
	}
	void dinic() {
		while(bfs()) dfs(S, infll);
		function<void(int)> find;
		find = [&](int u) -> void{
			res[u] = 1;
			for(int i = head[u]; i; i = e[i].nxt) {
				if(e[i].cap > 0 && !res[e[i].to]) find(e[i].to);
			}
		};
		find(S);
	}
} O;
int id[N];
void solve(VI V, vector<pii> E, int l, int r) {
	if(SZ(V) == 0) return;
	if(l == r) {
		for(auto x : V) ans[x] = _a[l];
		return;
	}
	// printf("[%lld %lld]\n", l, r);
	// for(auto ver : V) printf("%lld ", ver); printf("\n");
	int mid = (l + r) >> 1, vl = _a[mid], vr = _a[mid + 1];
	O.clear();
	O.n = SZ(V) + 2; O.S = SZ(V) + 1; O.T = SZ(V) + 2;
	rep(i, 1, SZ(V)) id[V[i - 1]] = i;
	for(auto [u, v] : E) O.add(id[u], id[v], infll);
	rep(i, 1, SZ(V)) {
		int v = - abs(a[V[i - 1]] - vr) + abs(a[V[i - 1]] - vl);
		if(v > 0) O.add(O.S, i, v);
		else O.add(i, O.T, -v);
	}
	O.dinic();
	VI nV[2];
	vector<pii> nE[2];
	rep(i, 1, SZ(V)) nV[O.res[i]].pb(V[i - 1]);
	for(auto [u, v] : E) if(O.res[id[u]] == O.res[id[v]]) nE[O.res[id[u]]].emplace_back(u, v);
	for(auto [u, v] : E) assert(O.res[id[u]] <= O.res[id[v]]);
	solve(nV[0], nE[0], l, mid);
	solve(nV[1], nE[1], mid + 1, r);
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n) scanf("%lld", &a[i]), _a[i] = a[i];
	sort(_a + 1, _a + n + 1);
	int _m = unique(_a + 1, _a + n + 1) - _a - 1;
	vector<pii> E;
	VI V;
	rep(i, 1, n) V.emplace_back(i);
	rep(i, 1, m) {
		int u, v;
		scanf("%lld%lld", &u, &v);
		E.emplace_back(u, v);
	}
	solve(V, E, 1, _m);
	for(auto [u, v] : E) assert(ans[u] <= ans[v]);
	rep(i, 1, n) printf("%lld ", ans[i]);
	return 0;
}