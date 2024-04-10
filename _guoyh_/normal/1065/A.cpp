# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t;
ll s, a, b, c;
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%lld%lld%lld%lld", &s, &a, &b, &c);
		ll ans = s / c;
		ans = ans + ans / a * b;
		printf("%lld\n", ans);
	}
	return 0;
}