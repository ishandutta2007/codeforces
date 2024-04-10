# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 1000051;
int n, m;
int a[5][NR];
int f[NR][2][2][2];
int main(){
	bool flag;
	memset(f, 0x3f, sizeof(f));
	scanf("%d%d", &n, &m);
	if (n > 3 && m > 3){
		printf("-1\n");
		return 0;
	}
	if (n > 3) flag = true;
	else flag = false;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (flag) scanf("%1d", a[j] + i);
			else scanf("%1d", a[i] + j);
		}
	}
	if (flag) swap(n, m);
	if (n == 1){
		printf("0\n");
		return 0;
	} else if (n == 2){
		int ans = 1e9;
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				f[1][i][j][0] = (i == a[1][1]) + (j == a[2][1]);
			}
		}
		for (int i = 2; i <= m; i++){
			for (int b1 = 0; b1 < 2; b1++){
				for (int b2 = 0; b2 < 2; b2++){
					for (int b3 = 0; b3 < 2; b3++){
						int b4 = 1;
						if ((b1 + b2 + b3) & 1) b4 = 0;
						int md = (b3 == a[1][i]) + (b4 == a[2][i]);
						f[i][b3][b4][0] = min(f[i][b3][b4][0], f[i - 1][b1][b2][0] + md);
						if (i == m) ans = min(ans, f[i][b3][b4][0]);
					}
				}
			}
		}
		printf("%d\n", ans);
	} else {
		int ans = 1e9;
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				for (int k = 0; k < 2; k++){
					f[1][i][j][k] = (i == a[1][1]) + (j == a[2][1]) + (k == a[3][1]);
				}
			}
		}
		for (int i = 2; i <= m; i++){
			for (int b1 = 0; b1 < 2; b1++){
				for (int b2 = 0; b2 < 2; b2++){
					for (int b3 = 0; b3 < 2; b3++){
						for (int b4 = 0; b4 < 2; b4++){
							int b5 = 1, b6 = 1;
							if ((b1 + b2 + b4) & 1) b5 = 0;
							if ((b2 + b3 + b5) & 1) b6 = 0;
							int md = (b4 == a[1][i]) + (b5 == a[2][i]) + (b6 == a[3][i]);
							f[i][b4][b5][b6] = min(f[i][b4][b5][b6], f[i - 1][b1][b2][b3] + md);
							if (i == m) ans = min(ans, f[i][b4][b5][b6]);
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}