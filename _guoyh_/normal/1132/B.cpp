# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 300051;
int n, m;
ll s;
ll a[NR];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%lld", a + i);
		s += a[i];
	}
	sort(a + 1, a + n + 1);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++){
		int q;
		scanf("%d", &q);
		ll ans = s - a[n - q + 1];
		printf("%lld\n", ans);
	}
	return 0;
}