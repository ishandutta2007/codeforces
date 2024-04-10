# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
int t, n;
ll x;
ll a[MAXN];
int b[MAXN];
int main(){
	scanf("%d", &t);
	while (t--){
		int pos = 1;
		ll ans = 0;
		scanf("%d%lld", &n, &x);
		for (int i = 1; i <= n; i++){
			b[i] = 0;
			scanf("%lld", a + i);
			ans += a[i];
			ll tmp = a[i];
			while (tmp % x == 0){
				b[i]++;
				tmp /= x;
			}
			if (b[i] < b[pos]) pos = i;
		}
		ans *= b[pos] + 1;
		for (int i = 1; i < pos; i++) ans += a[i];
		printf("%lld\n", ans);
	}
	return 0;
}