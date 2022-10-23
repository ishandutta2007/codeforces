# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 105;
int n;
ll k, ans;
char s[MAXN];
int last[31];
int pre[MAXN];
ll f[MAXN][MAXN];
int main(){
	scanf("%d%lld", &n, &k);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++){
		pre[i] = last[s[i] - 'a'];
		last[s[i] - 'a'] = i;
	}
	f[0][0] = 1;
	for (int i = 1; i <= n; i++){
		f[i][0] = 1;
		for (int j = 1; j <= i; j++){
			f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
			if (pre[i]) f[i][j] -= f[pre[i] - 1][j - 1];
			// printf("f %d %d %d\n", i, j, f[i][j]);
		}
	}
	for (int i = n; i >= 0; i--){
		if (k <= f[n][i]){
			ans += k * (n - i);
			printf("%lld\n", ans);
			return 0;
		}
		k -= f[n][i];
		ans += f[n][i] * (n - i);
	}
	printf("-1\n");
	return 0;
}