#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, x, Mod = 1000000007;
long long res;
vector< vector< vector<int> > >D;
int main()
{
	int i, j, k;
	scanf("%d%d%d", &n, &m, &x);
	if (n > m){
		printf("0\n");
		return 0;
	}
	D.resize(m + 1);
	for (i = 0; i <= m; i++){
		D[i].resize(n + 1);
		for (j = 0; j <= n; j++){
			D[i][j].resize(n + 1);
		}
	}
	D[0][0][0] = 1;
	for (i = 0; i < m; i++){
		for (j = 0; j <= n; j++){
			for (k = 0; k <= j; k++){
				if (i + 1 != x)D[i + 1][j][k] = (D[i + 1][j][k] + D[i][j][k]) % Mod;
				if(j != n)D[i + 1][j + 1][k] = (D[i + 1][j + 1][k] + D[i][j][k]) % Mod;
				if(i + 1 != x && k != n)D[i + 1][j][k + 1] = (D[i + 1][j][k + 1] + D[i][j][k]) % Mod;
				if (j != n&&k != n)D[i + 1][j + 1][k + 1] = (D[i + 1][j + 1][k + 1] + D[i][j][k]) % Mod;
			}
		}
	}
	res = D[m][n][n];
	for (i = 1; i <= n; i++){
		res = res*i%Mod;
	}
	printf("%lld\n", res);
}