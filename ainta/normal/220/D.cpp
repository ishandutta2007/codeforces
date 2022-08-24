#pragma warning(disable:4996)
#include<stdio.h>
int w[4][4][4], n, m;
long long G[4], Res, Mod = 1000000007, D[4001][4001], C1, C2, S, S2;
int Do(int ax, int ay, int bx, int by, int cx, int cy){
	int t = (ax*by + bx*cy + cx*ay) - (ay*bx + by*cx + cy*ax);
	if (t < 0)t = -t;
	if (t % 2 == 0)return 1;
	return 0;
}
long long G2(long long a){
	return (a*(a - 1) / 2) % Mod;
}
long long G3(long long a){
	return a*(a - 1)*(a - 2) / 6ll;
}
int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
int main()
{
	int i, j, k;
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			for (k = 0; k < 4; k++){
				w[i][j][k] = Do(i / 2, i & 1, j / 2, j & 1, k / 2, k & 1);
			}
		}
	}
	scanf("%d%d", &n, &m);
	G[0] = (n / 2 + 1)*(m / 2 + 1);
	G[1] = (n / 2 + 1)*((m + 1) / 2);
	G[2] = ((n + 1) / 2)*(m / 2 + 1);
	G[3] = ((n + 1) / 2)*((m + 1) / 2);
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			for (k = 0; k < 4; k++){
				if (w[i][j][k])Res = (Res + G[i] % Mod * G[j] % Mod * G[k]) % Mod;
			}
		}
	}
	C1 = (n + 1)*(m + 1);
	C2 = C1 * (C1 - 1) * 3;
	C1 = (C1 + C2) % Mod;
	Res = (Res - C1 + Mod) % Mod;
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			D[i][j] = D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1] + gcd(i,j) - 1;
		}
	}
	for (i = 0; i <= n; i++){
		for (j = 0; j <= m; j++){
			S = (S + D[i][j]) % Mod;
		}
	}
	S = S * 12 % Mod;
	S2 = ((n + 1) * G3(m + 1) + (m + 1)*G3(n + 1)) * 6 % Mod;
	S = (S + S2) % Mod;
	Res = (Res - S + Mod) % Mod;
	printf("%lld\n", Res);
}