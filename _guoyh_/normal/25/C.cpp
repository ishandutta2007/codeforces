# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 305;
int n, k;
ll d[MAXN][MAXN];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			scanf("%lld", d[i] + j);
		}
	}
	scanf("%d", &k);
	for (int i = 1; i <= k; i++){
		int u, v;
		ll w;
		scanf("%d%d%lld", &u, &v, &w);
		ll ans = 0;
		for (int v1 = 1; v1 <= n; v1++){
			for (int v2 = 1; v2 <= n; v2++){
				d[v1][v2] = min(d[v1][v2], min(d[v1][u] + w + d[v][v2], d[v1][v] + w + d[u][v2]));
				ans += d[v1][v2];
			}
		}
		printf("%lld\n", ans / 2);
	}
	return 0;
}