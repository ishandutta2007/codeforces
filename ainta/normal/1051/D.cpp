#include<cstdio>
#include<algorithm>
using namespace std;
int D[1010][2010][4], Mod = 998244353;
int n, K, w[4][4] = {
	{0,1,1,1},
	{0,0,2,0},
	{0,2,0,0},
	{1,1,1,0}
};
int main() {
	int i, j, k, l;
	scanf("%d%d", &n, &K);
	D[1][1][0] = D[1][2][1] = D[1][2][2] = D[1][1][3] = 1;
	for (i = 1; i < n; i++) {
		for (j = 0; j <= 2 * i; j++) {
			for (k = 0; k < 4; k++) {
				for (l = 0; l < 4; l++) {
					D[i + 1][j + w[k][l]][l] = (D[i + 1][j + w[k][l]][l] + D[i][j][k]) % Mod;
				}
			}
		}
	}
	int res = 0;
	for (i = 0; i < 4; i++)res = (res + D[n][K][i]) % Mod;
	printf("%d\n", res);
}