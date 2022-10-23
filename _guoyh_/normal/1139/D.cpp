# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
const int P = 1000000007;
int n, psz;
bool flag[MAXN];
int p[MAXN];
int mu[MAXN];
void euler(){
	mu[1] = 1;
	for (int i = 2; i < MAXN; i++){
		if (!flag[i]){
			p[++psz] = i;
			mu[i] = -1;
		}
		for (int j = 1; j <= psz && i * p[j] < MAXN; j++){
			flag[i * p[j]] = true;
			if (i % p[j] == 0){
				mu[i * p[j]] = 0;
				break;
			} else mu[i * p[j]] = -mu[i];
		}
	}
}
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
	euler();
	scanf("%d", &n);
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		ll prb = n / i * pwr(n, P - 2) % P;
		ans = (ans - mu[i] * prb * pwr(1 - prb, P - 2)) % P;
		// printf("%d %lld %lld\n", i, prb, ans);
	}
	printf("%lld\n", (ans + 1 + P) % P);
	return 0;
}