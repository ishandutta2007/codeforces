# include <stack>
# include <vector>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 500051;
struct DSU{
	stack <int> st;
	int sz[MAXN];
	int fa[MAXN];
	DSU(){
		for (int i = 1; i < MAXN; i++) sz[i] = 1;
	}
	int findroot(int nw){
		if (!fa[nw]) return nw;
		else return findroot(fa[nw]);
	}
	bool merge(int u, int v){
		u = findroot(u);
		v = findroot(v);
		if (u == v) return false;
		if (sz[u] > sz[v]) swap(u, v);
		fa[u] = v;
		sz[v] += sz[u];
		st.push(u);
		return true;
	}
	bool undo(int x){
		for (int i = 1; i <= x; i++){
			if (st.empty()) return false;
			int nw = st.top();
			st.pop();
			sz[fa[nw]] -= sz[nw];
			fa[nw] = 0;
		}
		return true;
	}
} dsu;
struct Edge{
	int u, v, w;
} e[MAXN], e1[MAXN];
struct Query{
	int id, st;
	Query(int id = 0, int st = 0): id(id), st(st){}
};
int n, m, q;
bool flag[MAXN];
vector <int> adj[MAXN];
vector <Query> bdj[MAXN];
bool cmp(int x, int y){
	return e[x].w < e[y].w;
}
bool cmp2(Edge x, Edge y){
	return x.w < y.w;
}
int main(){
	memset(flag, true, sizeof(flag));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++){
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
		e1[i] = e[i];
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++){
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++){
			int u;
			scanf("%d", &u);
			adj[i].push_back(u);
		}
		sort(adj[i].begin(), adj[i].end(), cmp);
		int sz = adj[i].size();
//		printf("adj %d: ", i);
//		for (int j = 0; j < sz; j++) printf("%d ", e[adj[i][j]].w);
//		putchar('\n');
		for (int j = 0; j < sz; j++){
			if (j == 0 || e[adj[i][j]].w != e[adj[i][j - 1]].w) bdj[e[adj[i][j]].w].push_back(Query(i, j));
		}
	}
//	printf("bdj:\n");
//	for (int i = 1; i <= 2; i++){
//		int sz = bdj[i].size();
//		for (int j = 0; j < sz; j++) printf("%d %d  ", bdj[i][j].id, bdj[i][j].st);
//		putchar('\n');
//	}
//	putchar('\n');
	sort(e1 + 1, e1 + m + 1, cmp2);
	for (int i = 1; i <= m; i++){
//		printf("e %d %d %d\n", e1[i].u, e1[i].v, e1[i].w);
		if (i == 1 || e1[i].w != e1[i - 1].w){
			int bsz = bdj[e1[i].w].size();
			for (int j = 0; j < bsz; j++){
				Query nw = bdj[e1[i].w][j];
				int asz = adj[nw.id].size();
				int cnt = 0;
//				printf("fa\n");
//				for (int i = 1; i <= n; i++) printf("%d ", dsu.fa[i]);
//				putchar('\n');
//				printf("nw %d %d\n", nw.id, nw.st);
				for (int k = nw.st; k < asz && e[adj[nw.id][k]].w == e1[i].w; k++){
//					printf("edge %d %d %d\n", e[adj[nw.id][k]].u, e[adj[nw.id][k]].v, e[adj[nw.id][k]].w);
					if (!dsu.merge(e[adj[nw.id][k]].u, e[adj[nw.id][k]].v)){
						flag[nw.id] = false;
						break;
					}
					cnt++;
				}
//				putchar('\n');
				dsu.undo(cnt);
//				for (int i = 1; i <= n; i++) printf("%d ", dsu.fa[i]);
//				putchar('\n');
			}
		}
//		printf("???????????????????????????????? %d %d\n", e1[i].u, e1[i].v);
		dsu.merge(e1[i].u, e1[i].v);
	}
	for (int i = 1; i <= q; i++) printf(flag[i] ? "YES\n": "NO\n");
	return 0;
}