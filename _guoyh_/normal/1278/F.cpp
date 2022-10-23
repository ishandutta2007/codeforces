# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXK = 5051;
const int P = 998244353;
int n, m, k;
ll p[MAXK];
ll s[MAXK][MAXK];
ll pwr(ll x, ll y){
	ll ans = 1;
	while (y){
		if (y & 1) ans = ans * x % P;
		x = x * x % P;
		y >>= 1;
	}
	return ans;
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	s[0][0] = 1;
	for (int i = 1; i <= k; i++){
		for (int j = 1; j <= k; j++){
			s[i][j] = (s[i - 1][j - 1] + s[i - 1][j] * j) % P;
		}
	}
	p[0] = 1;
	for (int i = 1; i <= k; i++) p[i] = p[i - 1] * (n - i + 1) % P;
	ll ans = 0;
	for (int j = 1; j <= k; j++){
		ans = (ans + s[k][j] * p[j] % P * pwr(m, (P - 1 - j)) % P) % P;
	}
	printf("%lld\n", ans);
	return 0;
}