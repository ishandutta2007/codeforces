# include <queue>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 200051;
struct Node{
	int id, wt;
	bool operator < (const Node &o) const{
		return wt < o.wt;
	}
};
struct Edge{
	int to, nxt;
} g[2 * NR];
int n, k, gsz;
ll ans;
bool vis[NR];
priority_queue <Node> q;
int in[NR], fte[NR], fa[NR], dep[NR], sz[NR];
void addedge(int x, int y){
	g[++gsz] = (Edge){y, fte[x]};
	fte[x] = gsz;
}
void dfs(int x){
	vis[x] = true;
	sz[x] = 1;
	for (int i = fte[x]; i; i = g[i].nxt){
		int nxtn = g[i].to;
		if (vis[nxtn]) continue;
		fa[nxtn] = x;
		in[x]++;
		dep[nxtn] = dep[x] + 1;
		dfs(nxtn);
		sz[x] += sz[nxtn];
	}
	if (sz[x] == 1) q.push((Node){x, dep[x]});
}
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	dfs(1);
	for (int i = 1; i <= k; i++){
		Node nw = q.top();
		q.pop();
		ans += nw.wt;
		in[fa[nw.id]]--;
		if (in[fa[nw.id]] <= 0){
			int nxtn = fa[nw.id];
			q.push((Node){nxtn, dep[nxtn] - sz[nxtn] + 1});
		}
	}
	printf("%lld\n", ans);
	return 0;
}