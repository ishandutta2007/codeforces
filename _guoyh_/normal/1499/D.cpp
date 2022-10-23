# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 30000051;
int t, c, d, x, psz;
int p[MAXN];
bool flag[MAXN];
ll f[MAXN];
ll work(int u){
	if ((u + d) % c) return 0;
	return f[(u + d) / c];
	// ll ans = 1;
	// for (int i = 2; i * i <= k; i++){
	// 	if (k % i) continue;
	// 	ans *= 2;
	// 	while (k % i == 0) k /= i;
	// }
	// if (k > 1) ans *= 2;
	// return ans;
}
int main(){
	f[1] = 1;
	for (int i = 2; i < MAXN; i++){
		if (!flag[i]){
			p[++psz] = i;
			f[i] = 2;
		}
		// printf("phi %d %d\n", i, phi[i]);
		for (int j = 1; j <= psz && i * p[j] < MAXN; j++){
			flag[i * p[j]] = true;
			if (i % p[j] == 0){
				f[i * p[j]] = f[i];
				break;
			} else f[i * p[j]] = f[i] * 2;
		}
	}
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &c, &d, &x);
		ll ans = 0;
		for (int i = 1; i * i <= x; i++){
			if (x % i) continue;
			ans += work(i);
			if (i * i != x) ans += work(x / i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}