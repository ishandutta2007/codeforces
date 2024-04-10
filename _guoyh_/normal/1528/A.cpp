# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
int t, n;
vector <int> g[MAXN];
int l[MAXN], r[MAXN];
ll f[MAXN][2];
void dfs(int nw, int fa){
	int sz = g[nw].size();
	f[nw][0] = f[nw][1] = 0;
	for (int i = 0; i < sz; i++){
		int nxtn = g[nw][i];
		if (nxtn == fa) continue;
		dfs(nxtn, nw);
		f[nw][0] += max(abs(l[nw] - l[nxtn]) + f[nxtn][0], abs(l[nw] - r[nxtn]) + f[nxtn][1]);
		f[nw][1] += max(abs(r[nw] - l[nxtn]) + f[nxtn][0], abs(r[nw] - r[nxtn]) + f[nxtn][1]);
	}
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i <= n; i++) scanf("%d%d", l + i, r + i);
		for (int i = 1; i <= n - 1; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 0);
		printf("%lld\n", max(f[1][0], f[1][1]));
	}
	return 0;
}