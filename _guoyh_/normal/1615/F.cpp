# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 2051;
const int P = 1000000007;
int t, n;
char s0[MAXN], s2[MAXN];
int a[MAXN], b[MAXN];
ll f[MAXN][MAXN], s[MAXN][MAXN], f1[MAXN][MAXN], s1[MAXN][MAXN];
void upd(ll &a, ll b){
	a = (a + b) % P;
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		scanf("%s%s", s0 + 1, s2 + 1);
		for (int i = 1; i <= n; i++){
			if (s0[i] == '?') a[i] = -1;
			else a[i] = (s0[i] - '0') ^ (i & 1);
			// printf("%2d ", a[i]);
		}
		// putchar('\n');
		for (int i = 1; i <= n; i++){
			if (s2[i] == '?') b[i] = -1;
			else b[i] = (s2[i] - '0') ^ (i & 1);
		}
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= n; j++){
				f[i][j] = f1[i][j] = s[i][j] = s1[i][j] = 0;
			}
		}
		for (int i = 0; i <= n && b[i] != 1; i++){
			f1[0][i] = 1;
			s1[0][i] = 1;
			for (int j = 1; j <= n && a[j] != 1; j++) s1[j][i] = 1;
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (a[i] != 0 && b[j] != 0){
					upd(f[i][j], s[i - 1][j - 1] + abs(i - j) * s1[i - 1][j - 1] % P);
					upd(f1[i][j], s1[i - 1][j - 1]);
				}
				if (b[j] != 1){
					upd(f[i][j], f[i][j - 1]);
					upd(f1[i][j], f1[i][j - 1]);
				}
				s[i][j] = f[i][j];
				if (a[i] != 1) upd(s[i][j], s[i - 1][j]);
				s1[i][j] = f1[i][j];
				if (a[i] != 1) upd(s1[i][j], s1[i - 1][j]);
				// printf("f %d %d %d %d %d %d\n", i, j, f[i][j], f1[i][j], s[i][j], s1[i][j]);
			}
		}
		printf("%lld\n", (s[n][n] + P) % P);
	}
	return 0;
}