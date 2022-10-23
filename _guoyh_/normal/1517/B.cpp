# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 105;
int t, n, m;
int r[MAXN];
int p[MAXN * MAXN];
int b[MAXN][MAXN];
int ans[MAXN][MAXN];
bool cmp(int u, int v){
	int ux = (u - 1) / m + 1, uy = (u - 1) % m + 1;
	int vx = (v - 1) / m + 1, vy = (v - 1) % m + 1;
	return b[ux][uy] < b[vx][vy];
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++) ans[i][j] = 0;
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				scanf("%d", b[i] + j);
				p[(i - 1) * m + j] = (i - 1) * m + j;
			}
			r[i] = m;
			sort(b[i] + 1, b[i] + m + 1);
		}
		sort(p + 1, p + n * m + 1, cmp);
		for (int i = 1; i <= m; i++){
			int nx = (p[i] - 1) / m + 1, ny = (p[i] - 1) % m + 1;
			ans[nx][i] = b[nx][ny];
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (ans[i][j]) printf("%d ", ans[i][j]);
				else printf("%d ", b[i][r[i]--]);
			}
			putchar('\n');
		}
	}
	return 0;
}