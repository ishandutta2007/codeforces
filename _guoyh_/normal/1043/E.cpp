# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 300051;
struct Node{
	ll x, y;
} a[MAXN];
struct Edge{
	int t, nxt;
} g[MAXN * 2];
int n, m, gsz;
int fte[MAXN];
int b[MAXN];
ll s1[MAXN], s2[MAXN];
ll ans[MAXN];
bool cmp(int x, int y){
	return a[x].x - a[x].y < a[y].x - a[y].y;
}
void addedge(int x, int y){
	g[++gsz] = (Edge){y, fte[x]};
	fte[x] = gsz;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld%lld", &a[i].x, &a[i].y);
	for (int i = 1; i <= m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	for (int i = 1; i <= n; i++) b[i] = i;
	sort(b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; i++) s1[i] = s1[i - 1] + a[b[i]].x;
	for (int i = n; i >= 1; i--) s2[i] = s2[i + 1] + a[b[i]].y;
	for (int i = 1; i <= n; i++){
		ans[b[i]] = s1[i - 1] + s2[i + 1] + (i - 1) * a[b[i]].y + (n - i) * a[b[i]].x;
		for (int j = fte[b[i]]; j; j = g[j].nxt){
			int nxtn = g[j].t;
			ans[b[i]] -= min(a[b[i]].x + a[nxtn].y, a[b[i]].y + a[nxtn].x);
		}
	}
	for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
	putchar('\n');
	return 0;
}