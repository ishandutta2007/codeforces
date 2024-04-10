# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 505;
int n, m, k, ans = 1e9;
int cnt[MAXN];
int a[MAXN][MAXN];
int w[MAXN][MAXN];
int f[MAXN][MAXN];
void update(int &a, int b){
	if (b < a) a = b;
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			scanf("%1d", a[i] + j);
		}
	}
	memset(w, 0x3f, sizeof(w));
	for (int i = 1; i <= n; i++){
		int suml = 0, sumr = 0;
		for (int l = 0; l <= m; l++){
			suml += a[i][l];
			sumr = 0;
			for (int r = m + 1; r > l; r--){
				sumr += a[i][r];
				update(w[i][suml + sumr], r - l - 1);
			}
		}
	}
	// printf("w20 %d\n", w[2][0]);
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= k; j++){
			for (int l = 0; l <= m && l <= j; l++){
				update(f[i][j], f[i - 1][j - l] + w[i][l]);
			}
			if (i == n) ans = min(ans, f[i][j]);
			// printf("f %d %d %d\n", i, j, f[i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}