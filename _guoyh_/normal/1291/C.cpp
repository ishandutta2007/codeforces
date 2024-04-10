# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t, n, m, k;
int a[3551];
int f[3551][3551];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int len = n - m + 1; len <= n; len++){
			for (int i = 1; i + len - 1 <= n; i++){
				int j = i + len - 1;
				if (len == n - m + 1) f[i][j] = max(a[i], a[j]);
				else if (n - len < k) f[i][j] = max(f[i + 1][j], f[i][j - 1]);
				else f[i][j] = min(f[i + 1][j], f[i][j - 1]);
			}
		}
		printf("%d\n", f[1][n]);
	}
	return 0;
}