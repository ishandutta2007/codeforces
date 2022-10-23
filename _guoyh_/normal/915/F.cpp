# include <vector>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 1000051;
int n;
ll ans;
vector <int> g[MAXN];
int a[MAXN], p[MAXN], fa[MAXN], sz[MAXN];
bool cmp(int x, int y){
	return a[x] < a[y];
}
int findroot(int nw){
	if (fa[nw] == nw) return nw;
	else return fa[nw] = findroot(fa[nw]);
}
ll merge(int x, int y){
	int rx = findroot(x), ry = findroot(y);
	if (rx == ry) return 0;
	ll tmp = 1ll * sz[rx] * sz[ry];
	sz[ry] += sz[rx];
	fa[rx] = ry;
	return tmp;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n - 1; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++){
		sz[i] = 1;
		fa[i] = i;
		p[i] = i;
	}
	sort(p + 1, p + n + 1, cmp);
	for (int i = 1; i <= n; i++){
		int nw = p[i];
		int sz = g[nw].size();
		for (int j = 0; j < sz; j++){
			int nxtn = g[nw][j];
			if (a[nxtn] > a[nw]) continue;
			ans += a[nw] * merge(nw, nxtn);
		}
	}
	// printf("%lld\n", ans);
	for (int i = 1; i <= n; i++){
		sz[i] = 1;
		fa[i] = i;
	}
	for (int i = n; i >= 1; i--){
		int nw = p[i];
		int sz = g[nw].size();
		// printf("nw %d\n", nw);
		for (int j = 0; j < sz; j++){
			int nxtn = g[nw][j];
			if (a[nxtn] < a[nw]) continue;
			ans -= a[nw] * merge(nw, nxtn);
		}
		// printf("%lld\n", ans);
	}
	printf("%lld\n", ans);
	return 0;
}