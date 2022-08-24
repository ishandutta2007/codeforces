#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, E[15], C[1 << 14], EE[15][15];
int A[1 << 14][14], B[1 << 14][14], CA[1 << 14], CB[1 << 14];
long long D[1 << 14][15];
char p[20][20];
vector<int>G[15];
int main() {
	int i, j, MM, k, l;
	scanf("%d", &n);
	MM = (n + 1) / 2;
	for (i = 0; i < n; i++) {
		scanf("%s", p[i]);
		for (j = 0; j < n; j++) {
			if (p[i][j] == '1')E[i] |= (1 << j), EE[i][j] = 1;
		}
	}
	for (i = 0; i < (1 << n); i++) {
		for (j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				C[i]++;
				A[i][CA[i]++] = j;
			}
			else {
				B[i][CB[i]++] = j;
			}
		}
		G[C[i]].push_back(i);
	}
	for (i = 0; i < n; i++)D[1 << i][i] = 1;
	for (i = 0; i < (1 << (n - 1)); i++) {
		int LCP = 0;
		if (i != 0) {
			for (j = n - 2; j >= 0; j--) {
				if (((i ^ (i - 1))>>j) & 1)break;
				LCP++;
			}
		}
		for (j = LCP; j < n - 1; j++) {
			for (auto &t : G[j + 2])for (k = 0; k < n; k++)D[t][k] = 0;
			for (auto &t : G[j + 1]) {
				for (k = 0; k < CA[t]; k++) {
					int x = A[t][k];
					int mask = E[x];
					if (!((i >> (n-2-j)) & 1))mask = (1 << n) - 1 - mask - (1 << x);
					mask = ((1 << n) - 1 - t)&mask;
					for (l = 0; l < CA[mask]; l++) {
						int y = A[mask][l];
						D[t | (1 << y)][y] += D[t][x];
					}
				}
			}
		}
		long long r = 0;
		for (j = 0; j < n; j++) r += D[(1 << n) - 1][j];
		printf("%lld ", r);
	}
}