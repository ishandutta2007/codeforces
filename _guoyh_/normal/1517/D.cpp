# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 505;
const int MAXK = 11;
const int mv[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m, k;
int f[MAXK][MAXN][MAXN];
int w[MAXN][MAXN][4];
int main(){
	scanf("%d%d%d", &n, &m, &k);
	if (k & 1){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				printf("-1 ");
			}
			putchar('\n');
		}
		return 0;
	}
	k /= 2;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m - 1; j++){
			scanf("%d", &w[i][j][0]);
			w[i][j + 1][2] = w[i][j][0];
		}
	}
	for (int i = 1; i <= n - 1; i++){
		for (int j = 1; j <= m; j++){
			scanf("%d", &w[i][j][1]);
			w[i + 1][j][3] = w[i][j][1];
		}
	}
	for (int i = 1; i <= k; i++){
		for (int u = 1; u <= n; u++){
			for (int v = 1; v <= m; v++){
				int ans = 1e9;
				for (int j = 0; j < 4; j++){
					int nx = u + mv[j][0], ny = v + mv[j][1];
					if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
					ans = min(ans, f[i - 1][nx][ny] + w[u][v][j]);
				}
				f[i][u][v] = ans;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			printf("%d ", 2 * f[k][i][j]);
		}
		putchar('\n');
	}
	return 0;
}