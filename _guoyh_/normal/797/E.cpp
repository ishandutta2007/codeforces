# include <cmath>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
int n, m, fsz;
int a[MAXN];
int f[MAXN][505]; 
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	fsz = int(sqrt(n)) / 2;
	for (int i = n; i >= 1; i--){
		for (int j = 1; j <= fsz; j++){
			if (i + j + a[i] > n) f[i][j] = 1;
			else f[i][j] = f[i + j + a[i]][j] + 1;
		}
	}
	scanf("%d", &m);
	while (m--){
		int p, k;
		scanf("%d%d", &p, &k);
		if (k <= fsz) printf("%d\n", f[p][k]);
		else {
			int cnt = 0;
			while (p <= n){
				p = p + a[p] + k;
				cnt++;
			}
			printf("%d\n", cnt);
		}
	}
	return 0;
}