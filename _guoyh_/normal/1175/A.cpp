# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t;
ll n, k;
int main(){
	scanf("%d", &t);
	while (t--){
		ll ans = 0;
		scanf("%lld%lld", &n, &k);
		ans += n % k;
		while (n >= k){
			n /= k;
			ans += n % k + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}