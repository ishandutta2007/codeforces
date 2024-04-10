# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 1051;
const int P = 998244353;
int n, k;
ll f[MAXN][2 * MAXN][4];
int main(){
	scanf("%d%d", &n, &k);
	f[1][1][0] = f[1][2][1] = f[1][2][2] = f[1][1][3] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k; j++){
			//00
			f[i + 1][j + 0][0] = (f[i + 1][j + 0][0] + f[i][j][0]) % P;
			f[i + 1][j + 1][1] = (f[i + 1][j + 1][1] + f[i][j][0]) % P;
			f[i + 1][j + 1][2] = (f[i + 1][j + 1][2] + f[i][j][0]) % P;
			f[i + 1][j + 1][3] = (f[i + 1][j + 1][3] + f[i][j][0]) % P;
			//01
			f[i + 1][j + 0][0] = (f[i + 1][j + 0][0] + f[i][j][1]) % P;
			f[i + 1][j + 0][1] = (f[i + 1][j + 0][1] + f[i][j][1]) % P;
			f[i + 1][j + 2][2] = (f[i + 1][j + 2][2] + f[i][j][1]) % P;
			f[i + 1][j + 0][3] = (f[i + 1][j + 0][3] + f[i][j][1]) % P;
			//10
			f[i + 1][j + 0][0] = (f[i + 1][j + 0][0] + f[i][j][2]) % P;
			f[i + 1][j + 2][1] = (f[i + 1][j + 2][1] + f[i][j][2]) % P;
			f[i + 1][j + 0][2] = (f[i + 1][j + 0][2] + f[i][j][2]) % P;
			f[i + 1][j + 0][3] = (f[i + 1][j + 0][3] + f[i][j][2]) % P;
			//11
			f[i + 1][j + 1][0] = (f[i + 1][j + 1][0] + f[i][j][3]) % P;
			f[i + 1][j + 1][1] = (f[i + 1][j + 1][1] + f[i][j][3]) % P;
			f[i + 1][j + 1][2] = (f[i + 1][j + 1][2] + f[i][j][3]) % P;
			f[i + 1][j + 0][3] = (f[i + 1][j + 0][3] + f[i][j][3]) % P;
		}
	}
	printf("%lld\n", (f[n][k][0] + f[n][k][1] + f[n][k][2] + f[n][k][3]) % P);
	return 0;
}