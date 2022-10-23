# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const ll NR = 400051;
ll n, m;
ll ans = 0;
ll d[NR];
int main(){
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; i++){
		scanf("%lld", d + i);
		d[i + n] = d[i];
	}
	n = n * 2;
	ll l = 1;
	ll len = 0, nw = 0;
	for (ll i = 1; i <= n; i++){
		len += d[i];
		nw += d[i] * (d[i] + 1) / 2;
		while (len > m){
			len -= d[l];
			nw -= d[l] * (d[l] + 1) / 2;
			l++;
		}
		if (l > 1) ans = max(ans, nw + (d[l - 1] + d[l - 1] - (m - len) + 1) * (m - len) / 2);
		else ans = max(ans, nw);
	}
	printf("%lld\n", ans);
	return 0;
}