# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
const int MAXB = 1051;
int n, m;
int a[MAXN], c[MAXN];
int blen, bsz;
int pos[MAXB], bid[MAXN];
int solve(int u, int v){
	int ans = 1;
	int lv = min(a[u], a[v]), rv = max(a[u], a[v]);
	int bu = bid[u] + 1, bv = bid[v] - 1;
	if (bu > bv){
		for (int i = u + 1; i <= v - 1; i++) ans += 2 * (a[i] > lv && a[i] < rv);
		if (a[u] < a[v]) return ans;
		else return -ans;
	}
	for (int i = u + 1; i <= pos[bu - 1]; i++) ans += 2 * (a[i] > lv && a[i] < rv);
	for (int i = pos[bv] + 1; i <= v - 1; i++) ans += 2 * (a[i] > lv && a[i] < rv);
	for (int i = bu; i <= bv; i++) ans += 2 * (upper_bound(c + pos[i - 1] + 1, c + pos[i] + 1, rv) - lower_bound(c + pos[i - 1] + 1, c + pos[i] + 1, lv));
	if (a[u] < a[v]) return ans;
	else return -ans;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) a[i] = c[i] = i;
	blen = sqrt(n);
	while (pos[bsz] + blen < n){
		pos[bsz + 1] = pos[bsz] + blen;
		bsz++;
	}
	pos[++bsz] = n;
	for (int i = 1; i <= bsz; i++){
		for (int j = pos[i - 1] + 1; j <= pos[i]; j++) bid[j] = i;
	}
	// for (int i = 1; i <= n; i++) printf("%d ", bid[i]);
	// putchar('\n');
	ll ans = 0;
	for (int i = 1; i <= m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		if (u == v){
			printf("%lld\n", ans);
			continue;
		}
		if (u > v) swap(u, v);
		ans += solve(u, v);
		printf("%lld\n", ans);
		int bu = bid[u], bv = bid[v];
		swap(a[u], a[v]);
		memcpy(c + pos[bu - 1] + 1, a + pos[bu - 1] + 1, sizeof(int) * (pos[bu] - pos[bu - 1]));
		memcpy(c + pos[bv - 1] + 1, a + pos[bv - 1] + 1, sizeof(int) * (pos[bv] - pos[bv - 1]));
		sort(c + pos[bu - 1] + 1, c + pos[bu] + 1);
		sort(c + pos[bv - 1] + 1, c + pos[bv] + 1);
		// for (int i = 1; i <= n; i++) printf("%d ", a[i]);
		// putchar('\n');
		// for (int i = 1; i <= n; i++) printf("%d ", c[i]);
		// putchar('\n');
	}
	return 0;
}