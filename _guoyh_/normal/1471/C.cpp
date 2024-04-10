# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 300051;
int t, n, m;
int k[MAXN];
ll c[MAXN];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", k + i);
		for (int i = 1; i <= m; i++) scanf("%lld", c + i);
		sort(k + 1, k + n + 1);
		int p = 0;
		ll ans = 0;
		for (int i = n; i >= 1; i--){
			if (p < k[i]) ans += c[++p];
			else ans += c[k[i]];
		}
		printf("%lld\n", ans);
	}
	return 0;
}