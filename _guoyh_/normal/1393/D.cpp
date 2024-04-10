# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 2051;
int n, m;
ll ans;
ll f[NR][NR];
char p[NR][NR];
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%s", p[i] + 1);
	}
	for (int s = 2; s <= n + m; s++){
		for (int j = max(1, s - n); j <= m; j++){
			int i = s - j;
			if (i <= 0) break;
			f[i][j] = 1;
			if (j - 2 <= 0 || i - 1 <= 0 || i + 1 > n) continue;
			if (p[i - 1][j - 1] != p[i][j] || p[i][j - 1] != p[i][j] || p[i + 1][j - 1] != p[i][j] || p[i][j - 2] != p[i][j]) continue;
			f[i][j] = min(f[i - 1][j - 1], min(f[i][j - 1], min(f[i + 1][j - 1], f[i][j - 2]))) + 1;
			// printf("%d %d %d\n", i, j, f[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans += f[i][j];
	printf("%lld\n", ans);
	return 0;
}