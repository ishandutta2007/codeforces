# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 2051;
int n, k;
ll p;
ll a[MAXN], b[MAXN];
bool check(ll t){
	int j = 1;
	for (int i = 1; i <= n; i++){
		while (j <= k && abs(b[j] - a[i]) + abs(b[j] - p) > t) j++;
		if (j > k) return false;
		j++;
	}
	return true;
}
int main(){
	scanf("%d%d%lld", &n, &k, &p);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	for (int i = 1; i <= k; i++) scanf("%lld", b + i);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + k + 1);
	ll l = 0, r = 2e9, ans = -1;
	while (l <= r){
		ll mid = (l + r) >> 1;
		if (check(mid)){
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	printf("%lld\n", ans);
	return 0;
}