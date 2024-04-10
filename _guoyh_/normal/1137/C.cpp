# include <stack>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXD = 51;
const int MAXN = 100051;
const int MAXV = MAXN * MAXD;
const int MAXE = MAXN * MAXD;
struct Edge{
	int t, nxt;
	Edge(int t = 0, int nxt = 0): t(t), nxt(nxt){}
} g[MAXE * 2];
int n, m, d, gsz, csz, cnt;
int f1[MAXV * 2], f2[MAXV];
int fte[MAXV * 2];
stack <int> st;
bool inst[MAXV];
int flag[MAXV];
int dfn[MAXV], low[MAXV], scc[MAXV];
void addedge(int u, int v){
	g[++gsz] = Edge(v, fte[u]);
	fte[u] = gsz;
}
inline void tarjan(int nw){
	// printf("tarjan %d\n", nw);
	inst[nw] = true;
	st.push(nw);
	low[nw] = dfn[nw] = ++cnt;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (!dfn[nxtn]){
			tarjan(nxtn);
			low[nw] = min(low[nw], low[nxtn]);
		} else if (inst[nxtn]) low[nw] = min(low[nw], dfn[nxtn]);
	}
	if (dfn[nw] == low[nw]){
		csz++;
		int lst = 0;
		while (!st.empty() && lst != nw){
			if (f1[st.top()]){
				f1[csz + d * n] += flag[(st.top() - 1) % n] != nw;
				flag[(st.top() - 1) % n] = nw;
			}
			scc[st.top()] = csz;
			inst[st.top()] = false;
			lst = st.top();
			st.pop();
		}
	}
}
inline int dfs(int nw){
	if (f2[nw] != -1) return f2[nw];
	f2[nw] = 0;
	for (int i = fte[nw + n * d]; i; i = g[i].nxt){
		int nxtn = g[i].t - n * d;
		f2[nw] = max(f2[nw], dfs(nxtn));
	}
	f2[nw] += f1[nw + d * n];
	return f2[nw];
}
int main(){
	memset(f2, -1, sizeof(f2));
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 1; i <= m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		for (int j = 0; j < d; j++) addedge(u + j * n, v + ((j + 1) % d) * n);
	}
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < d; j++){
			int u;
			scanf("%1d", &u);
			f1[i + j * n] = u;
		}
	}
	tarjan(1);
	// for (int i = 1; i <= n * d; i++) printf("scc %d %d %d\n", i, scc[i], f1[scc[i] + n * d]);
	for (int i = 1; i <= n * d; i++){
		if (!scc[i]) continue;
		for (int j = fte[i]; j; j = g[j].nxt){
			int nxtn = g[j].t;
			if (!scc[nxtn]) continue;
			if (scc[i] != scc[nxtn]) addedge(scc[i] + n * d, scc[nxtn] + n * d);
		}
	}
	printf("%d\n", dfs(scc[1]));
	return 0;
}