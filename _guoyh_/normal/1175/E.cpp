# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 500051;
int n, m;
int g[NR][35];
int main(){
	memset(g, -1, sizeof(g));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		g[l][0] = max(g[l][0], r);
	}
	// printf("gi0 ");
	for (int i = 0; i <= 500005; i++){
		g[i][0] = max(g[i][0], g[i - 1][0]);
		if (g[i][0] <= i) g[i][0] = -1;
		// printf("%d ", g[i][0]);
	}
	// putchar('\n');
	for (int j = 1; j <= 30; j++){
		for (int i = 0; i <= 500005; i++) if (g[i][j - 1] != -1) g[i][j] = g[g[i][j - 1]][j - 1];
	}
	while (m--){
		int x, y, ans = 0;
		scanf("%d%d", &x, &y);
		for (int i = 30; i >= 0; i--){
			if (g[x][i] != -1 && g[x][i] < y){
				x = g[x][i];
				ans += (1 << i);
			}
		}
		if (x == y) printf("%d\n", ans);
		else if (g[x][0] >= y) printf("%d\n", ans + 1);
		else printf("-1\n");
	}
	return 0;
}