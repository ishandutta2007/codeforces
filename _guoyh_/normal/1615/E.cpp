# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
int n, k;
struct Edge{
	int t, nxt;
	Edge(int t = 0, int nxt = 0): t(t), nxt(nxt){}
} g[MAXN * 2];
int gsz;
int fte[MAXN];
void addedge(int u, int v){
	g[++gsz] = Edge(v, fte[u]);
	fte[u] = gsz;
}
int fa[MAXN], dep[MAXN], mxd[MAXN];
void dfs(int nw){
	mxd[nw] = nw;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa[nw]) continue;
		fa[nxtn] = nw;
		dep[nxtn] = dep[nw] + 1;
		dfs(nxtn);
		if (dep[mxd[nxtn]] > dep[mxd[nw]]) mxd[nw] = mxd[nxtn];
	}
}
bool flag[MAXN];
priority_queue <pair <int, int> > q;
ll cal(ll x, ll y, ll z){
	if (z < y) return x * (y - z);
	ll u = (z - y - x) / 2;
	u = max(u, 0ll);
	u = min(u, z - 1);
	return min((x + u) * (y - z + u), (x + u + 1) * (y - z + u + 1));
}
ll work(){
	int cnt = 0;
	ll ans = cal(0, 0, n);
	q.push(make_pair(dep[mxd[1]], mxd[1]));
	for (int i = 1; i <= k; i++){
		if (!q.empty()){
			int nw = q.top().second;
			q.pop();
			while (!flag[nw] && nw){
				cnt++;
				flag[nw] = true;
				for (int j = fte[nw]; j; j = g[j].nxt){
					int nxtn = g[j].t;
					if (nxtn == fa[nw] || flag[nxtn]) continue;
					q.push(make_pair(dep[mxd[nxtn]] - dep[nxtn], mxd[nxtn]));
				}
				nw = fa[nw];
			}
			// printf("cnt %d %d\n", i, cnt);
		}
		ans = max(ans, cal(cnt - i, i, n - cnt));
	}
	return ans;
}
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n - 1; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	dfs(1);
	printf("%lld\n", work());
	return 0;
}