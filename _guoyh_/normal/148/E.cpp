# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 105;
const int MAXM = 10051;
int n, m;
int cnt[MAXN];
int v[MAXN][MAXN];
int w[MAXN][MAXN];
int f[MAXN][MAXM];
void update(int &a, int b){
	if (b > a) a = b;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", cnt + i);
		for (int j = 1; j <= cnt[i]; j++) scanf("%d", v[i] + j);
		int suml = 0, sumr = 0;
		for (int l = 0; l <= cnt[i]; l++){
			suml += v[i][l];
			sumr = 0;
			for (int r = cnt[i] + 1; r > l; r--){
				sumr += v[i][r];
				update(w[i][l + cnt[i] - r + 1], suml + sumr);
			}
		}
	}
	memset(f, 0xf3, sizeof(f));
	f[0][0] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= m; j++){
			for (int k = 0; k <= j && k <= cnt[i]; k++){
				update(f[i][j], f[i - 1][j - k] + w[i][k]);
			}
		}
	}
	printf("%d\n", f[n][m]);
	return 0;
}