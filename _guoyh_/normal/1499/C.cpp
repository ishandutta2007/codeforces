# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
int t, n;
ll c[MAXN], s[MAXN], mi[MAXN];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			scanf("%lld", c + i);
			s[i] = s[i - 1] + c[i];
			if (i <= 2) mi[i] = c[i];
			else mi[i] = min(mi[i - 2], c[i]);
		}
		ll ans = 1e18;
		for (int i = 2; i <= n; i++){
			ll nw = mi[i] * (n - i / 2) + mi[i - 1] * (n - (i + 1) / 2) + s[i];
			if (i & 1) nw = mi[i] * (n - (i + 1) / 2) + mi[i - 1] * (n - i / 2) + s[i];
			// printf("nw %d %lld\n", i, nw);
			ans = min(ans, nw);
		}
		printf("%lld\n", ans);
	}
	return 0;
}