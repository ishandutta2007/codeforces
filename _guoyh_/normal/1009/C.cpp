# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
ll n, m;
ll s = 0;
int main(){
	scanf("%lld%lld", &n, &m);
	ll h = (n + 1) / 2;
	ll mxd = n * (n - 1) / 2, mid = (n & 1) ? h * (h - 1) : h * h;
	ll ans = 0;
	for (int i = 1; i <= m; i++){
		ll x, d;
		scanf("%lld%lld", &x, &d);
		ans += x * n;
		if (d > 0) ans += (d * mxd);
		else ans += (d * mid);
	}
	printf("%lf\n", (double)ans / n);
	return 0;
}