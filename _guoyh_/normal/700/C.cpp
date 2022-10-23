# include <stack>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 1051;
const int MAXM = 30051;
struct Edge{
	int t, w, nxt;
	Edge(){
		w = 2e9 + 1;
	}
	Edge(int t, int w, int nxt): t(t), w(w), nxt(nxt){}
} g[MAXM * 2];
int n, m, s, t, gsz = 1, cnt, dsz;
int fte[MAXN];
int pre[MAXN];
bool vis[MAXN];
stack <int> st;
bool f[MAXN];
bool inst[MAXN];
int dfn[MAXN], low[MAXN], dcc[MAXN];
void addedge(int u, int v, int w){
	g[++gsz] = Edge(v, w, fte[u]);
	fte[u] = gsz;
	g[++gsz] = Edge(u, w, fte[v]);
	fte[v] = gsz;
}
void dfs0(int nw){
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (pre[nxtn] != 0) continue;
		pre[nxtn] = i ^ 1;
		dfs0(nxtn);
	}
}
int getmin(int u, int v){
	if (!u || !v) return u + v;
	return (g[u].w < g[v].w) ? u : v;
}
int tarjan(int nw, int pre, int e){
	// printf("tarjan %d %d\n", nw, pre);
	st.push(nw);
	inst[nw] = true;
	f[nw] = (nw == t);
	low[nw] = dfn[nw] = ++cnt;
	int ans = 0;
	for (int i = fte[nw]; i; i = g[i].nxt){
		if ((i ^ 1) == pre || i == pre || i == e || (i ^ 1) == e) continue;
		int nxtn = g[i].t;
		if (!dfn[nxtn]){
			ans = getmin(ans, tarjan(nxtn, i, e));
			f[nw] |= f[nxtn];
			low[nw] = min(low[nw], low[nxtn]);
		} else if (inst[nxtn]) low[nw] = min(low[nw], dfn[nxtn]);
	}
	if (low[nw] == dfn[nw]){
		int lst = 0;
		while (!st.empty() && lst != nw){
			lst = st.top();
			inst[lst] = false;
			st.pop();
		}
		if (pre != -1) ans = getmin(ans, pre);
	}
	if (f[nw]) return ans;
	else return 0;
}
int main(){
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w);
	}
	pre[s] = -1;
	dfs0(s);
	if (!pre[t]){
		printf("0\n0\n\n");
		return 0;
	}
	int ans = 2e9 + 1, c, e1, e2;
	for (int i = t; i != s; i = g[pre[i]].t){
		memset(vis, false, sizeof(vis));
		memset(dfn, 0, sizeof(dfn));
		memset(f, 0, sizeof(f));
		cnt = dsz = 0;
		int nw = tarjan(s, -1, pre[i]);
		// printf("nw %d %d\n", i, nw);
		if (!dfn[t]){
			if (g[pre[i]].w < ans){
				ans = g[pre[i]].w;
				c = 1;
				e1 = pre[i] / 2;
			}
		} else if (nw != 0) {
			if (g[nw].w + g[pre[i]].w < ans){
				ans = g[nw].w + g[pre[i]].w;
				c = 2;
				e1 = pre[i] / 2;
				e2 = nw / 2;
			}
		}
	}
	if (ans > 2e9){
		printf("-1\n");
		return 0;
	}
	printf("%d\n%d\n", ans, c);
	if (c == 1) printf("%d\n", e1);
	else printf("%d %d\n", e1, e2);
	return 0;
}