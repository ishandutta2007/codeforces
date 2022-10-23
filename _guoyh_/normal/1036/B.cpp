# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int q;
ll n, m, k;
int main(){
	scanf("%d", &q);
	while (q--){
		scanf("%lld%lld%lld", &n, &m, &k);
		if (n > m) swap(n, m);
		ll tol = n + (m - n) / 2 * 2;
		if ((m - n) & 1){
			if ((k - tol) & 1) k--;
			else {
				k--;
				tol++;
			}
		} else {
			if ((k - tol) & 1) {
				tol--;
				k -= 2;
			}
		}
		if (tol > k) printf("-1\n");
		else printf("%lld\n", k);
	}
	return 0;
}