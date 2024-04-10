# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 405;
const int MAXM = 250051;
struct Truck{
	int s, t, r;
	ll c;
} tr[MAXM];
int n, m;
ll ans;
ll a[MAXN];
ll f[MAXN][MAXN];
bool cmp(Truck x, Truck y){
	return x.r < y.r;
}
int main(){
	memset(f, 0x3f, sizeof(f));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= m; i++) scanf("%d%d%lld%d", &tr[i].s, &tr[i].t, &tr[i].c, &tr[i].r);
	sort(tr + 1, tr + m + 1, cmp);
	int p = 1;
	for (int k = 1; k <= n; k++){
		for (int l = 1; l <= n; l++){
			int mid = n;
			for (int r = n; r > l; r--){
				if (r == l + 1 || k == 1) f[l][r] = a[r] - a[l];
				else {
					while (mid >= r) mid--;
					while (mid - 1 > l && f[l][mid - 1] >= a[r] - a[mid - 1]) mid--;
					f[l][r] = min(f[l][r], min(a[r] - a[mid - 1], f[l][mid]));
					// printf("f %d %d %d %lld\n", l, r, k, f[l][r]);
				}
			}
		}
		while (p <= m && tr[p].r == k - 1){
			ans = max(ans, f[tr[p].s][tr[p].t] * tr[p].c);
			p++;
		}
		if (p > m) break;
	}
	while (p <= m){
		ans = max(ans, f[tr[p].s][tr[p].t] * tr[p].c);
		p++;
	}
	printf("%lld\n", ans);
	return 0;
}