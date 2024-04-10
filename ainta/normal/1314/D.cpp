#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, K;
int w[81][81], C[81][81][5], H[81][81][5], chk[81], res=2e9;
int main() {
	int i, j, k, l, ii, jj;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &w[i][j]);
			if (i == j)w[i][j] = 1e9;
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			for (k = 0; k < 5; k++)C[i][j][k] = 1e9;
			for (k = 2; k <= n; k++) {
				if (i != k && k != j) {
					int t = w[i][k] + w[k][j];
					for (l = 0; l < 5; l++) {
						if (C[i][j][l] > t)break;
					}
					int pv = l;
					for (l = 4; l > pv; l--) {
						C[i][j][l] = C[i][j][l - 1];
						H[i][j][l] = H[i][j][l - 1];
					}
					C[i][j][pv] = t, H[i][j][pv] = k;
				}
			}
		}
	}
	chk[0] = 1;
	if (K == 10) {
		chk[1]++;
		for (i = 1; i <= n; i++) {
			chk[i]++;
			for (j = 1; j <= n; j++) {
				chk[j]++;
				for (k = 1; k <= n; k++) {
					chk[k]++;
					for (l = 1; l <= n; l++) {
						chk[l]++;
						int t1 = -1, t2 = -1, t3 = -1, t4 = -1, t5 = -1;
						for (ii = 0; ii < 5; ii++) {
							if (t1==-1 && !chk[H[1][i][ii]]) {
								t1 = C[1][i][ii];
							}
							if (t2 == -1 && !chk[H[i][j][ii]]) {
								t2 = C[i][j][ii];
							}
							if (t3 == -1 && !chk[H[j][k][ii]]) {
								t3 = C[j][k][ii];
							}
							if (t4 == -1 && !chk[H[k][l][ii]]) {
								t4 = C[k][l][ii];
							}
							if (t5 == -1 && !chk[H[l][1][ii]]) {
								t5 = C[l][1][ii];
							}
						}
						if (t1 != -1 && t2 != -1 && t3 != -1 && t4 != -1 && t5 != -1) {
							res = min(res, t1 + t2 + t3 + t4 + t5);
						}
						chk[l]--;
					}
					chk[k]--;
				}
				chk[j]--;
			}
			chk[i]--;
		}
	}

	if (K == 8) {
		chk[1]++;
		for (i = 1; i <= n; i++) {
			chk[i]++;
			for (j = 1; j <= n; j++) {
				chk[j]++;
				for (k = 1; k <= n; k++) {
					chk[k]++;
					int t1 = -1, t2 = -1, t3 = -1, t4 = -1;
					for (l = 0; l < 5; l++) {
						if (t1 == -1 && !chk[H[1][i][l]]) {
							t1 = C[1][i][l];
						}
						if (t2 == -1 && !chk[H[i][j][l]]) {
							t2 = C[i][j][l];
						}
						if (t3 == -1 && !chk[H[j][k][l]]) {
							t3 = C[j][k][l];
						}
						if (t4 == -1 && !chk[H[k][1][l]]) {
							t4 = C[k][1][l];
						}
					}
					if (t1 != -1 && t2 != -1 && t3 != -1 && t4 != -1) {
						res = min(res, t1 + t2 + t3 + t4);
					}
					chk[k]--;
				}
				chk[j]--;
			}
			chk[i]--;
		}
	}


	if (K == 6) {
		chk[1]++;
		for (i = 1; i <= n; i++) {
			chk[i]++;
			for (j = 1; j <= n; j++) {
				chk[j]++;
				int t1 = -1, t2 = -1, t3 = -1, t4 = -1;
				for (l = 0; l < 5; l++) {
					if (t1 == -1 && !chk[H[1][i][l]]) {
						t1 = C[1][i][l];
					}
					if (t2 == -1 && !chk[H[i][j][l]]) {
						t2 = C[i][j][l];
					}
					if (t3 == -1 && !chk[H[j][1][l]]) {
						t3 = C[j][1][l];
					}
				}
				if (t1 != -1 && t2 != -1 && t3 != -1) {
					res = min(res, t1 + t2 + t3);
				}
				chk[j]--;
			}
			chk[i]--;
		}
	}
	if (K == 4) {
		chk[1] = 1;
		for (i = 1; i <= n; i++) {
			chk[i]++;
			int t1 = -1, t2 = -1, t3 = -1, t4 = -1;
			for (l = 0; l < 5; l++) {
				if (t1 == -1 && !chk[H[1][i][l]]) {
					t1 = C[1][i][l];
				}
				if (t2 == -1 && !chk[H[i][1][l]]) {
					t2 = C[i][1][l];
				}
			}
			if (t1 != -1 && t2 != -1) {
				res = min(res, t1 + t2);
			}
			chk[i]--;
		}
	}
	if (K == 2) {
		res = C[1][1][0];
	}
	printf("%d\n", res);
}