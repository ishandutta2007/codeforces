# include <bits/stdc++.h>
# define ll long long
# define fst first
# define snd second
using namespace std;
const int MAXN = 3005;
int t, n;
int a[MAXN];
int f[MAXN][MAXN], s[MAXN][MAXN], w[MAXN][MAXN];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int r = 1; r <= n; r++){
			for (int l = r; l >= 1; l--){
				w[l][r] = w[l + 1][r] + (l + a[l] > r);
			}
		}
		for (int i = 0; i <= n + 1; i++){
			for (int j = 0; j <= n + 1; j++){
				f[i][j] = s[i][j] = 1e9;
			}
		}
		f[n][n + 1] = s[n][n + 1] = 0;
		for (int i = n; i >= 1; i--){
			for (int j = i + a[i]; j > i; j--){
				f[i][j] = w[i + 1][j - 1] + s[j][i + a[i] + 1];
				s[i][j] = min(s[i][j + 1], f[i][j]);
				// printf("f %d %d %d %d\n", i, j, f[i][j], s[i][j]);
			}
		}
		int ans = 1e9;
		for (int i = 1 + a[1]; i > 1; i--) ans = min(ans, f[1][i]);
		printf("%d\n", ans);
	}
	return 0;
}