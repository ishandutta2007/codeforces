# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 505;
const int P = 1e9 + 7;
int n;
int a[MAXN][MAXN];
ll f[MAXN][MAXN], g[MAXN][MAXN];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			scanf("%d", a[i] + j);
		}
	}
	for (int len = 1; len <= n; len++){
		for (int l = 1; l + len - 1 <= n; l++){
			int r = l + len - 1;
			if (l == r){
				f[l][r] = g[l][r] = 1;
				continue;
			}
			if (a[l][r]) for (int mid = l; mid < r; mid++) f[l][r] = (f[l][r] + g[l][mid] * g[mid + 1][r]) % P;
			for (int mid = l; mid < r; mid++) g[l][r] = (g[l][r] + g[l][mid] * f[mid][r]) % P;
		}
	}
	printf("%lld\n", g[1][n]);
	return 0;
}