#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, C[501000];
vector<int>E[501000], CH[501000];
int D[501000], D2[501000], D3[501000], D4[501000], par[501000];
int H[501000], H2[501000], H3[501000], H4[501000];
int LT[501000][8], RT[501000][8];
void DFS(int a, int pp) {
	int i, chk = 0;
	C[a] = 1;
	for (i = 0; i < E[a].size(); i++) {
		int x = E[a][i];
		if (x == pp)continue;
		par[x] = a;
		CH[a].push_back(x);
		DFS(x, a);
		C[a] += C[x];
		chk = 1;
	}
	if (!chk) {
		D[a] = 0;
		D2[a] = 1;
		D3[a] = 1;
		return;
	}

	for (i = 0; i < 8; i++)LT[0][i] = 0;
	LT[0][0] = 1;

	for (i = 0; i < CH[a].size(); i++) {
		for (int j = 0; j < 8; j++)LT[i + 1][j] = 0;
		int x = CH[a][i];
		if (D[x]) {
			for (int j = 0; j < 8; j++) {
				LT[i + 1][j] += LT[i][j];
			}
		}

		if (D2[x]) {
			for (int j = 0; j < 8; j++) {
				if(!(j&1))LT[i + 1][j+1] += LT[i][j];
			}
		}

		if (D3[x]) {
			for (int j = 0; j < 8; j++) {
				if (!(j & 2))LT[i + 1][j + 2] += LT[i][j]*D3[x];
			}
		}

		if (D4[x]) {
			for (int j = 0; j < 8; j++) {
				if (!(j & 4))LT[i + 1][j + 4] += LT[i][j] * D4[x];
			}
		}
	}
	D2[a] = LT[i][0];
	D[a] = LT[i][1];
	D3[a] = D2[a] + LT[i][3] + LT[i][4];
	D4[a] = LT[i][2];
}
void Do(int a, int pp) {
	int i, j, k;

	int sz = CH[a].size();

	for (i = 0; i < 4; i++)LT[0][i] = 0;
	LT[0][0] = 1;


	for (i = 0; i < sz; i++) {
		for (int j = 0; j < 8; j++)LT[i + 1][j] = 0;
		int x = CH[a][i];
		if (D[x]) {
			for (int j = 0; j < 8; j++) {
				LT[i + 1][j] += LT[i][j];
			}
		}

		if (D2[x]) {
			for (int j = 0; j < 8; j++) {
				if (!(j & 1))LT[i + 1][j + 1] += LT[i][j];
			}
		}

		if (D3[x]) {
			for (int j = 0; j < 8; j++) {
				if (!(j & 2))LT[i + 1][j + 2] += LT[i][j]*D3[x];
			}
		}

		if (D4[x]) {
			for (int j = 0; j < 8; j++) {
				if (!(j & 4))LT[i + 1][j + 4] += LT[i][j]*D4[x];
			}
		}
	}

	for (i = 0; i < 8; i++)RT[sz][i] = 0;
	RT[sz][0] = 1;

	for (i = sz-1; i >= 0; i--) {
		for (int j = 0; j < 8; j++)RT[i][j] = 0;
		int x = CH[a][i];
		if (D[x]) {
			for (int j = 0; j < 8; j++) {
				RT[i][j] += RT[i+1][j];
			}
		}

		if (D2[x]) {
			for (int j = 0; j < 8; j++) {
				if (!(j & 1))RT[i][j + 1] += RT[i+1][j];
			}
		}
		if (D3[x]) {
			for (int j = 0; j < 8; j++) {
				if (!(j & 2))RT[i][j + 2] += RT[i+1][j]*D3[x];
			}
		}

		if (D4[x]) {
			for (int j = 0; j < 8; j++) {
				if (!(j & 4))RT[i][j + 4] += RT[i+1][j]*D4[x];
			}
		}
	}

	for (i = 0; i < sz; i++) {
		int T[8] = { 0 };
		for (j = 0; j < 8; j++) {
			for (k = 0; k < 8; k++) {
				if ((j&k) == 0)T[j | k] += LT[i][j] * RT[i + 1][k];
			}
		}
		int x = CH[a][i];
		H[x] = (H[a] * T[1]) + (H2[a] * T[0]);
		H2[x] = (H[a] * T[0]);
		H3[x] = H2[x] + (H[a] * T[3]) + (H2[a] * T[2]) + (H3[a] * T[1]) + (H4[a] * T[0]) + (H[a] * T[4]);
		H4[x] = (H[a] * T[2]) + (H3[a] * T[0]);
	}

	for (i = 0; i < sz; i++)Do(CH[a][i], a);
}
int main() {
	int i, a, b;
	long long res = 0;
	scanf("%d", &n);
	if (n % 2 == 1) {
		printf("0\n");
		return 0;
	}
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, 0);
	H[1] = 1;
	Do(1, 0);
	if (D[1]) {
		for (i = 2; i <= n; i++) {
			if (D[i]) {
				res += 1ll * C[i] * (n - C[i]);
			}
		}
	}
	for (i = 2; i <= n; i++) {
		res += 1ll * D3[i] * H3[i];
	}
	printf("%lld\n", res);
}