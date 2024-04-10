# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
int t, n;
ll x;
ll a[MAXN];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%lld", &n, &x);
		ll ans1 = 0, ans2 = 0;
		for (int i = 1; i <= n; i++){
			scanf("%lld", a + i);
			ans1 += a[i];
			ans2 += (a[i] + x - 1) / x;
		}
		ans1 = (ans1 + x - 1) / x;
		printf("%lld %lld\n", ans1, ans2);
	}
	return 0;
}