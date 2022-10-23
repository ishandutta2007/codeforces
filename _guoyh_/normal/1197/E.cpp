# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
const int P = 1000000007;
int n;
int au[MAXN], av[MAXN];
int a[MAXN], b[MAXN];
int f[MAXN], f2[MAXN];
bool cmpu(int u, int v){
	return au[u] < au[v];
}
bool cmpv(int u, int v){
	return av[u] < av[v];
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", au + i, av + i);
	for (int i = 1; i <= n; i++) a[i] = i;
	sort(a + 1, a + n + 1, cmpv);
	for (int i = 1; i <= n; i++) b[i] = i;
	sort(b + 1, b + n + 1, cmpu);
	int p = 1, mi = 0;
	f2[0] = 1;
	for (int i = 1; i <= n; i++){
		f2[a[i]] = f2[a[i - 1]];
		while (p <= n && au[b[p]] <= av[a[i]]){
			if (f[b[p]] + av[a[i]] - au[b[p]] == f[mi] + av[a[i]] - au[mi]) f2[a[i]] = (f2[a[i]] + f2[b[p]]) % P;
			if (f[b[p]] + av[a[i]] - au[b[p]] < f[mi] + av[a[i]] - au[mi]) f2[a[i]] = f2[b[p]];
			if (f[b[p]] + av[a[i]] - au[b[p]] <= f[mi] + av[a[i]] - au[mi]) mi = b[p];
			p++;
		}
		f[a[i]] = f[mi] + av[a[i]] - au[mi];
		// printf("f %d %d %d\n", a[i], f[a[i]], mi);
	}
	mi = 1e9;
	for (int i = 1; i <= n; i++) if (au[i] > av[a[n]]) mi = min(mi, f[i]);
	int ans = 0;
	for (int i = 1; i <= n; i++){
		if (f[i] == mi && au[i] > av[a[n]]) ans = (ans + f2[i]) % P;
		// printf("f %d %d %d\n", i, f[i], f2[i]);
	}
	printf("%d\n", ans);
	return 0;
}