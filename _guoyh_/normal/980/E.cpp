# include <vector>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 1000051;
int n, k, ans;
int dep[MAXN];
bool flag[MAXN];
int fa[MAXN][21];
vector <int> g[MAXN];
void dfs(int nw){
	int sz = g[nw].size();
	for (int i = 0; i < sz; i++){
		int nxtn = g[nw][i];
		if (nxtn == fa[nw][0]) continue;
		fa[nxtn][0] = nw;
		dep[nxtn] = dep[nw] + 1;
		for (int j = 1; j <= 20; j++) fa[nxtn][j] = fa[fa[nxtn][j - 1]][j - 1];
		dfs(nxtn);
	}
}
int count(int nw){
	if (flag[nw]) return 0;
	int cnt = 0;
	for (int i = 20; i >= 0; i--){
		if (fa[nw][i] != 0 && !flag[fa[nw][i]]){
			cnt += (1 << i);
			nw = fa[nw][i];
		}
	}
	return cnt + 1;
}
void solve(int nw){
	int cnt = count(nw);
	if (k < cnt) return;
	k -= cnt;
	for (int i = nw; !flag[i]; i = fa[i][0]) flag[i] = true;
}
int main(){
	scanf("%d%d", &n, &k);
	k = n - k;
	for (int i = 1; i <= n - 1; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dep[n] = 1;
	dfs(n);
	for (int i = n; i >= 1; i--) solve(i);
	for (int i = 1; i <= n; i++) if (!flag[i]) printf("%d ", i);
	putchar('\n');
	return 0;
}