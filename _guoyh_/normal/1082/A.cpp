# include <cmath>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
ll t;
ll n, x, y, d;
int main(){
	scanf("%lld", &t);
	while (t--){
		scanf("%lld%lld%lld%lld", &n, &x, &y, &d);
		ll ans = 1e18;
		if (abs(y - x) % d == 0) ans = min(ans, abs(y - x) / d);
		if ((y - 1) % d == 0) ans = min(ans, (x - 1 + d - 1) / d + (y - 1) / d);
		if ((n - y) % d == 0) ans = min(ans, (n - x + d - 1) / d + (n - y) / d);
		if (ans > 1e17) printf("-1\n");
		else printf("%lld\n", ans);
	}
	return 0;
}