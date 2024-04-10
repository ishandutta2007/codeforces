#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, D[2010][11], TD[2010][11], Mod = 998244353, F[2010];
int DD[2010][2010][11];
char p[20];
void Put(int a) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < 11; j++) {
			TD[i][(j + a) % 11] = (TD[i][(j + a) % 11] + D[i][j]) % Mod;
			TD[i+1][(j + 11 - a) % 11] = (TD[i+1][(j + 11 - a) % 11] + D[i][j]) % Mod;
		}
	}
	for (i = 0; i <= n; i++)for (j = 0; j < 11; j++) {
		D[i][j] = TD[i][j];
		TD[i][j] = 0;
	}
}
int main() {
	int TC, i, j, k;
	scanf("%d", &TC);
	F[0] = 1;
	for (i = 1; i <= 2000; i++)F[i] = 1ll * F[i - 1] * i%Mod;
	while (TC--) {
		scanf("%d", &n);
		vector<int>A, B;
		for (i = 0; i <= n; i++) {
			for (j = 0; j <= n+1; j++)for (k = 0; k < 11; k++)DD[i][j][k] = 0;
			for (j = 0; j < 11; j++)D[i][j] = 0;
		}
		D[0][0] = 1;
		int cnt = 0;
		for (i = 0; i < n; i++) {
			scanf("%s", p);
			int s = 0;
			for (j = 0; p[j]; j++) {
				if (j % 2 == 0)s += p[j] - '0';
				else s -= p[j] - '0';
			}
			s = (s + 1111) % 11;
			if (j % 2 == 0)B.push_back(s);
			else {
				cnt++;
				Put(s);
			}
		}
		for (i = 0; i < 11; i++) {
			DD[cnt][(cnt+1)/2][i] = 1ll * D[cnt / 2][i] * F[cnt / 2] % Mod * F[(cnt + 1) / 2] % Mod;
		}
		for (i = cnt; i < n; i++) {
			int a = B[i - cnt];
			for (j = 0; j <= i + 1; j++) {
				for (k = 0; k < 11; k++) {
					DD[i + 1][j][(k+a)%11] = (DD[i + 1][j][(k + a) % 11] + 1ll * DD[i][j][k] * (i + 1 - j)) % Mod;
					DD[i + 1][j + 1][(k + 11 - a) % 11] = (DD[i + 1][j + 1][(k + 11 - a) % 11] + 1ll * DD[i][j][k] * j) % Mod;
				}
			}
		}
		int res = 0;
		for (i = 0; i <= n; i++)res = (res + DD[n][i][0]) % Mod;
		printf("%d\n", res);
	}
}