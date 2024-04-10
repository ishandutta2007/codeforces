#include<cstdio>
#include<algorithm>
using namespace std;
int Mod = 1000000007, D[5010][5010], n;
char p[5010];
int main() {
	int i, j;
	D[0][0] = 1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		if (p[0] == 'f') {
			for (j = 0; j <= i; j++)D[i][j + 1] = D[i - 1][j];
		}
		else {
			for (j = 0; j <= i; j++)D[i][j] = D[i - 1][j];
			for (j = i; j >= 1; j--)D[i][j - 1] = (D[i][j - 1] + D[i][j]) % Mod;
		}
		scanf("%s", p);
	}
	int res = 0;
	for (i = 0; i <= n; i++)res = (res + D[n][i]) % Mod;
	printf("%d\n", res);
}