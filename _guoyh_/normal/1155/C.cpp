# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 300051;
int n, m;
ll a[NR], p[NR];
ll gcd(ll x, ll y){
	if (y == 0) return x;
	else return gcd(y, x % y);
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	for (int i = 1; i <= m; i++) scanf("%lld", p + i);
	ll g = a[2] - a[1];
	for (int i = 2; i <= n; i++) g = gcd(g, a[i] - a[i - 1]);
	for (int i = 1; i <= m; i++){
		if (g % p[i] == 0){
			printf("YES\n%lld %d\n", a[1], i);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}