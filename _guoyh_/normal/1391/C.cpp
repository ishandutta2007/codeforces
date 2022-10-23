# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 1000051;
const ll PR = 1000000007;
int n;
ll f[NR], e[NR];
ll pwr(ll x, ll y){
	ll ans = 1;
	while (y){
		if (y & 1) ans = ans * x % PR;
		x = x * x % PR;
		y >>= 1;
	}
	return ans;
}
int main(){
	scanf("%d", &n);
	f[0] = e[0] = 1;
	for (int i = 1; i <= n; i++){
		f[i] = f[i - 1] * i % PR;
		e[i] = pwr(f[i], PR - 2);
	}
	ll fnl = f[n];
	for (int i = 1; i <= n; i++){
		ll nw = f[n - 1] * e[i - 1] % PR * e[n - i] % PR;
		fnl = (fnl - nw) % PR;
	}
	printf("%lld\n", (fnl + PR) % PR);
	return 0;
}