# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 1000051;
const int P = 998244353;
const int INV2 = 499122177;
int n;
ll a[MAXN], f[MAXN], s[MAXN], ss[MAXN];
ll pwr(ll x, ll y){
	y = (y % (P - 1) + (P - 1)) % (P - 1);
	ll ans = 1;
	while (y){
		if (y & 1) ans = ans * x % P;
		x = x * x % P;
		y >>= 1;
	}
	return ans;
}
int main(){
	scanf("%d", &n);
	ll p0 = 1;
	for (int i = 1; i <= n; i++){
		scanf("%lld", a + i);
		// a[i] = i;
		s[i] = (s[i - 1] + a[i]) % P;
		p0 = p0 * INV2 % P;
		ss[i] = (ss[i - 1] + p0 * s[i]) % P;
	}
	ll sf = 0;
	ll p1 = pwr(2, n), p2 = pwr(2, -n), pn = pwr(2, -n);
	for (int i = n; i >= 1; i--){
		f[i] = p1 * sf % P;
		f[i] = (f[i] + ss[n - i]) % P;
		f[i] = (f[i] + pn * p1 % P * s[n - i + 1]) % P;
		sf = (sf + p2 * f[i]) % P;
		p1 = p1 * INV2 % P;
		p2 = p2 * 2 % P;
	}
	ll ans = f[1] * pwr(2, n - 1) % P;
	printf("%lld\n", (ans + P) % P);
	return 0;
}