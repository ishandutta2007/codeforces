# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
ll n, m;
int main(){
	scanf("%lld%lld", &n, &m);
	printf("%lld ", max(0ll, n - 2 * m));
	ll lft = 1, rgt = n, ans = n;
	while (lft <= rgt){
		ll mid = (lft + rgt) >> 1;
		if (mid * (mid - 1) / 2 >= m){
			ans = mid;
			rgt = mid - 1;
		} else lft = mid + 1;
	}
	if (ans == 1) printf("%lld\n", n);
	else printf("%lld\n", n - ans);
	return 0;
}