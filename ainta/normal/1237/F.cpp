#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int H, W, n;
int visX[4010], visY[4010];
struct point {
	int x, y;
};
vector<int>X, Y;
int D[4010][4010][2], Mod = 998244353;
int Comb[4010][4010], SX, SY;

void Do(vector<int>T, int S, int ck) {
	int i, j, sum = 0, k;
	D[0][0][ck] = 1;
	int sz = T.size();
	for (int i = 1; i <= sz; i++) {
		int t = T[i - 1];
		for (j = 0; j <= sum; j++) {
			int d = D[i - 1][j][ck];
			for (k = 0; k <= t/2; k++) {
				D[i][j + k][ck] = (D[i][j + k][ck] + (long long)d * Comb[t-k][t-k*2]) % Mod;
			}
		}
		sum += t/2;
	}
}
int F[4010];
int main() {
	int i, j;
	scanf("%d%d", &H, &W);
	for (i = 0; i <= 4000; i++) {
		Comb[i][0] = 1;
		for (j = 1; j <= i; j++)Comb[i][j] = (Comb[i - 1][j - 1] + Comb[i - 1][j]) % Mod;
	}
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		point a, b;
		scanf("%d%d%d%d", &a.x, &a.y, &b.x, &b.y);
		visX[a.x] = visX[b.x] = 1;
		visY[a.y] = visY[b.y] = 1;
	}
	int c = 0;
	for (i = 1; i <= H; i++) {
		if (!visX[i])c++, SX++;
		if (i == H || visX[i + 1]) {
			if(c)X.push_back(c);
			c = 0;
		}
	}
	c = 0;
	for (i = 1; i <= W; i++) {
		if (!visY[i])c++, SY++;
		if (i == W || visY[i + 1]) {
			if(c)Y.push_back(c);
			c = 0;
		}
	}
	Do(X, H, 0);
	Do(Y, W, 1);
	long long res = 0;
	F[0] = 1;
	for (i = 1; i <= 4000; i++) {
		F[i] = 1ll*F[i - 1] * i%Mod;
	}
	for (i = 0; i <= SX; i++) {
		for (j = 0; i+j*2 <= SX; j++) {
			if (i * 2 + j <= SY) {
				int rx = SX - j * 2;
				int ry = SY - i * 2;
				res = (res + 1ll * D[X.size()][j][0] * Comb[rx][i] % Mod * D[Y.size()][i][1] % Mod *Comb[ry][j]%Mod*F[i]%Mod*F[j]) % Mod;
			}
		}
	}
	printf("%lld\n", res);
}