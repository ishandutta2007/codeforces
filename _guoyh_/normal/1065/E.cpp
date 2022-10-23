# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXM = 200051;
const int P = 998244353;
const int INV2 = 499122177;
int n, m, A;
int b[MAXM];
ll pwr(ll x, ll y){
	x %= P;
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
	scanf("%d%d%d", &n, &m, &A);
	for (int i = 1; i <= m; i++) scanf("%d", b + i);
	sort(b + 1, b + m + 1);
	ll ans = 1;
	for (int i = 1; i <= m; i++){
		ll nm = pwr(A, b[i] - b[i - 1]);
		ans = ans * (nm * (nm - 1) % P * INV2 % P + nm) % P;
	}
	ans = ans * pwr(A, n - b[m] * 2) % P;
	printf("%lld\n", ans);
	return 0;
}