# include <cmath>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
int t, n;
ll a[MAXN], b[MAXN];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= 2 * n; i++){
			ll u, v;
			scanf("%lld%lld", &u, &v);
			if (u == 0) b[++cnt2] = v * v;
			else a[++cnt1] = u * u;
		}
		sort(a + 1, a + cnt1 + 1);
		sort(b + 1, b + cnt2 + 1);
		double ans = 0;
		for (int i = 1; i <= n; i++) ans += sqrt(a[i] + b[i]);
		printf("%.15f\n", ans);
	}
	return 0;
}//