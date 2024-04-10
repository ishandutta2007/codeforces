// luogu
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 200051;
int n, rsz, ssz;
int st[NR];
int c[NR], a[NR];
int rid[NR];
int ans[NR];
bool vis[NR];
int dfs(int nw){
	vis[nw] = true;
	st[++ssz] = nw;
	if (rid[a[nw]]) return rid[nw] = rid[a[nw]];
	if (vis[a[nw]]){
		rid[nw] = ++rsz;
		ans[rsz] = 1e9;
		while (ssz > 0 && st[ssz] != a[nw]){
			ans[rsz] = min(ans[rsz], c[st[ssz]]);
			ssz--;
		}
		ans[rsz] = min(ans[rsz], c[a[nw]]);
		return rsz;
	}
	return rid[nw] = dfs(a[nw]);
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", c + i);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++){
		if (!rid[i]) rid[i] = dfs(i);
	}
	int fnl = 0;
	for (int i = 1; i <= rsz; i++) fnl += ans[i];
	printf("%d\n", fnl);
	return 0;
}