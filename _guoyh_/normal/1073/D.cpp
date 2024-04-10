# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 200051;
int n;
ll t;
ll a[NR], s[NR];
int main(){
	scanf("%d%lld", &n, &t);
	for (int i = 1; i <= n; i++){
		scanf("%lld", a + i);
	}
	ll tol = 0;
	while (true){
		ll s = 0, nm = 0;
		for (int i = 1; i <= n; i++){
			if (t >= a[i]){
				s += a[i];
				nm++;
				t -= a[i];
			}
		}
		if (s == 0) break;
		tol += t / s * nm + nm;
		t %= s;
	}
	printf("%lld\n", tol);
	return 0;
}