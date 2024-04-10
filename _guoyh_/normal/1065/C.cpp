# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const ll NR = 200051;
ll n, k, mx, ans;
ll h[NR], d[NR];
int main(){
	scanf("%lld%lld", &n, &k);
	for (ll i = 1; i <= n; i++){
		scanf("%lld", h + i);
		d[h[i]]++;
		mx = max(mx, h[i]);
	}
	ll nw = 0, cnt = 0;
	for (ll i = mx; i >= 0; i--){
		nw += d[i];
		if (nw == n) break;
		if (cnt + nw > k){
			ans++;
			cnt = nw;
		} else cnt += nw;
	}
	if (cnt) ans++;
	printf("%lld\n", ans);
	return 0;
}