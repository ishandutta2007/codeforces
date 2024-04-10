# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 200051;
int n;
ll m, k;
int mn1, mn2;
ll a[NR];
int main(){
	scanf("%d%lld%lld", &n, &m, &k);
	for (int i = 1; i <= n; i++){
		scanf("%lld", a + i);
		if (a[i] > a[mn1]){
			mn2 = mn1;
			mn1 = i;
		} else if (a[i] > a[mn2]){
			mn2 = i;
		}
	}
	int cnt = m / (k + 1);
	ll ans = cnt * a[mn2] + (m - cnt) * a[mn1];
	printf("%lld\n", ans);
	return 0;
}