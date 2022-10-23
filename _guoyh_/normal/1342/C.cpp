# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t, q;
ll a, b, l, r, g;
ll gcd(ll x, ll y){
	if (y == 0) return x;
	else return gcd(y, x % y);
}
ll work(ll x){
	ll ans = x / g * b;
	ans += min(x % g + 1, b);
	return x + 1 - ans;
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%lld%lld%d", &a, &b, &q);
		if (a > b) swap(a, b);
		g = a * b / gcd(a, b);
		while (q--){
			scanf("%lld%lld", &l, &r);
			printf("%lld ", work(r) - work(l - 1));
		}
		putchar('\n');
	}
	return 0;
}