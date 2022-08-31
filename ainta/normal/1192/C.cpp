#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int CC[20][110][110];
string U[201000];
char p[110];
int Num(char ch) {
	if (ch <= '9')return 52 + ch - '0';
	if (ch <= 'Z')return 26 + ch - 'A';
	if (ch <= 'z')return ch - 'a';
}
int D[63][63][63], Mod = 998244353;
int D2[63][63][63][63];
int D3[63][63][63], res, C[63][63];
const int BB = 62;
void Do(int L) {
	int i, j, k, l, ii;
	for (i = 0; i < BB; i++)for (j = 0; j < BB; j++)C[i][j] = CC[L][i][j];
	for (i = 0; i < BB; i++)for (j = i; j < BB; j++)for (k = j; k < BB; k++)D[i][j][k] = 0;
	for (i = 0; i < BB; i++)for (j = i; j < BB; j++)for (k = j; k < BB; k++)for (l = 0; l < BB; l++)D[i][j][k] = (D[i][j][k] + (long long)C[i][l] * C[j][l] * C[k][l]) % Mod;
	for (i = 0; i < BB; i++)for (j = i; j < BB; j++)for (k = j; k < BB; k++) {
		
		for (l = k; l < BB; l++) {
			long long s = (long long)D[i][j][k] * D[i][j][l] % Mod*D[j][k][l] % Mod*D[i][k][l] % Mod;
			if (s) {
				int c = (i == j) + (j == k) + (k == l);
				if (c == 0)res = (res + s * 24) % Mod;
				if (c == 1)res = (res + s * 12) % Mod;
				if (c == 3)res = (res + s) % Mod;
				if (c == 2) {
					if (j != k)res = (res + s * 6) % Mod;
					else res = (res + s * 4) % Mod;
				}
			}
		}

	}
}
int main() {
	int i;
	int n, cnt = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s", p);
		U[cnt] = p;
		U[cnt + 1] = U[cnt];
		reverse(U[cnt].begin(), U[cnt].end());
		cnt += 2;
	}
	sort(U, U + cnt);
	cnt = unique(U, U + cnt) - U;
	for (i = 0; i < cnt; i++) {
		CC[U[i].size()][Num(U[i].front())][Num(U[i].back())]++;
	}
	for (i = 3; i <= 10; i++) {
		Do(i);
	}
	printf("%d\n", res);
}