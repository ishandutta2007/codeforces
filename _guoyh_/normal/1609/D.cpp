# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 1005;
int n, q;
int eu[MAXN], ev[MAXN];
int fa[MAXN], sz[MAXN];
int a[MAXN], asz;
int findroot(int nw){
	if (!fa[nw]) return nw;
	else return fa[nw] = findroot(fa[nw]);
}
bool mrg(int u, int v){
	u = findroot(u);
	v = findroot(v);
	if (u == v) return false;
	sz[v] += sz[u];
	fa[u] = v;
	return true;
}
int main(){
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) sz[i] = 1;
	int cnt = 1;
	for (int i = 1; i <= q; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		cnt += !mrg(u, v);
		int ans = 0;
		asz = 0;
		for (int j = 1; j <= n; j++) if (!fa[j]) a[++asz] = sz[j];
		sort(a + 1, a + asz + 1);
		for (int j = 1; j <= asz && j <= cnt; j++) ans += a[asz - j + 1];
		printf("%d\n", ans - 1);
	}
	return 0;
}