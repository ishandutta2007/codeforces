#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<bitset>
using namespace std;
int n;
bitset<1300000>S1[30], S2[30];
int U[26][1300000], C[26], Num1[26][1300000], Num2[26][1300000];
int w[60];
void Do1(int pv, int ed, int c, int S, int mask) {
	if (pv == ed) {
		S1[c][S] = 1;
		Num1[c][S] = mask;
		return;
	}
	Do1(pv + 1, ed, c, S, mask);
	Do1(pv + 1, ed, c + 1, S + w[pv], mask|(1<<pv));
}
void Do2(int pv, int ed, int c, int S, int mask) {
	if (pv == ed) {
		S2[c][S] = 1;
		Num2[c][S] = mask;
		return;
	}
	Do2(pv + 1, ed, c, S, mask);
	Do2(pv + 1, ed, c + 1, S + w[pv], mask|(1<<(pv-n)));
}
int res = 2e9, mask1, mask2, R[2][30];
void UDT(int tp, int m1, int m2) {
	if (res <= tp)return;
	res = tp;
	mask1 = m1;
	mask2 = m2;
}
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n * 2; i++) {
		scanf("%d", &w[i]);
	}
	sort(w, w + n*2);
	if (n == 2) {
		printf("%d %d\n%d %d\n", w[0], w[2], w[3], w[1]);
		return 0;
	}
	Do1(2, n, 0, 0, 0);
	Do2(n, 2 * n, 0, 0, 0);
	int sum1 = 0, sum2 = 0;
	for (i = 2; i < n; i++)sum1 += w[i];
	for (i = n; i < 2 * n; i++)sum2 += w[i];
	for (i = 1; i < n; i++) {
		for (j = 0; j <= 50000 * i; j++) {
			if (S2[i][j]) {
				U[i][C[i]++] = j;
			}
		}
	}
	for (i = 1; i < n; i++) {
		for (j = 0; j <= 50000 * i; j++) {
			if (S1[i - 1][j]) {
				int t = (sum2 - sum1) / 2 + j;
				int pv = lower_bound(U[i], U[i] + C[i], t) - U[i];
				if (pv < C[i]) {
					int s = U[i][pv];
					int tp = max(j + sum2 - s, sum1 - j + s);
					UDT(tp, Num1[i - 1][j], Num2[i][s]);
				}
				if (pv) {
					int s = U[i][pv - 1];
					int tp = max(j + sum2 - s, sum1 - j + s);
					UDT(tp, Num1[i - 1][j], Num2[i][s]);
				}
			}
		}
	}
	R[0][1] = w[0];
	R[1][n] = w[1];
	int p1 = 1, p2 = n;
	for (i = 2; i < n; i++) {
		if ((mask1 >> i) & 1) {
			R[0][++p1] = w[i];
		}
		else {
			R[1][--p2] = w[i];
		}
	}
	p1 = 0;
	p2 = n + 1;
	for (i = n; i < 2 * n; i++) {
		if ((mask2 >> (i - n)) & 1) {
			R[1][++p1] = w[i];
		}
		else R[0][--p2] = w[i];
	}
	for (i = 0; i < 2; i++) {
		for (j = 1; j <= n; j++)printf("%d ", R[i][j]);
		puts("");
	}
}