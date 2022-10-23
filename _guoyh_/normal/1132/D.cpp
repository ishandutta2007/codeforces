# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 200051;
struct Edge{
	int id;
	ll re;
	int nxt;
} g[MAXN];
int n, k, gsz;
int fte[MAXN];
ll a[MAXN], b[MAXN];
void addedge(int t, int id, ll re){
	g[++gsz] = (Edge){id, re, fte[t]};
	fte[t] = gsz;
}
bool check(ll x){
	gsz = 0;
	memset(fte, 0, sizeof(fte));
	for (int i = 1; i <= n; i++){
		if (a[i] < b[i] * (k - 1)){
			if (gsz >= k + 1) return false;
			addedge(a[i] / b[i] + 1, i, a[i] % b[i]);
		}
	}
	if (x == 0) return gsz == 0;
	ll cnt = 0;
	for (int i = 1; i < k; i++){
		cnt++;
		for (int j = fte[i]; j; j = g[j].nxt){
			ll nm = (b[g[j].id] - g[j].re + x - 1) / x;
			// printf("ij %d %lld %d %lld %lld\n", i, cnt, g[j].id, g[j].re, nm);
			if (cnt < nm) return false;
			cnt -= nm;
			if ((g[j].re + nm * x) / b[g[j].id] + i < k){
				if (gsz >= k + 1) return false;
				addedge((g[j].re + nm * x) / b[g[j].id] + i, g[j].id, (g[j].re + nm * x) % b[g[j].id]);
			}
		}
		// printf("ic %d %lld\n", i, cnt);
	}
	return true;
}
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	for (int i = 1; i <= n; i++) scanf("%lld", b + i);
	// printf("%d\n", check(5));
	// return 0;
	ll lft = 0, rgt = 5e17, ans = -1;
	while (lft <= rgt){
		ll mid = (lft + rgt) >> 1;
		if (check(mid)){
			ans = mid;
			rgt = mid - 1;
		} else lft = mid + 1;
	}
	printf("%lld\n", ans);
	return 0;
}