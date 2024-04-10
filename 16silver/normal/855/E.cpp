#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
long long bino[32][32], ful[64][12][12];
int dgt[66];
int odod[10];
int main() {
	int i, j, k, q, pp, ods;
	long long l, r, t, a1, a2, b;
	for (i = 0; i < 32; i++) {
		bino[i][i] = 1;
		bino[i][0] = 1;
	}
	for (i = 1; i < 32; i++) {
		for (j = 1; j < i; j++) {
			bino[i][j] = bino[i - 1][j - 1] + bino[i - 1][j];
		}
	}
	for (b = 2; b < 11; b++) {
		ful[0][b][0] = 1;
		ful[1][b][1] = b;
		for (i = 2; i < 64; i++) {
			for (j = 0; j <= b; j++) {
				ful[i][b][j] = ful[i - 1][b][j - 1] * ((long long)(b - j + 1)) + ful[i - 1][b][j + 1] * ((long long)(j + 1));
			}
		}
	}
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%lld%lld%lld", &b, &l, &r);
		l--;
		j = 0;
		a1 = 0;
		a2 = 0;
		for (t = l; t > 0; t /= b) dgt[j++] = t%b;
		if (j % 2 == 1) {
			for (j--; j > 0; j -= 2) {
				a1 += (ful[j][b][0] / b) * (b - 1);
			}
		}
		else {
			k = j;
			for (j -= 2; j > 0; j -= 2) {
				a1 += (ful[j][b][0] / b) * (b - 1);
			}
			j = k;
			ods = 0;
			for (k = 0; k < b; k++) odod[k] = 0;
			for (pp = 1; pp < dgt[j - 1]; pp++) {
				if (odod[pp] == 0) a1 += ful[j - 1][b][ods + 1] / bino[b][ods + 1];
				else a1 += ful[j - 1][b][ods - 1] / bino[b][ods - 1];
			}
			odod[dgt[j - 1]] = 1;
			for (k = j - 2; k >= 0; k--) {
				ods = 0;
				for (pp = 0; pp < b; pp++) ods += odod[pp];
				for (pp = 0; pp < dgt[k]; pp++) {
					if (odod[pp] == 0) a1 += ful[k][b][ods + 1] / bino[b][ods + 1];
					else a1 += ful[k][b][ods - 1] / bino[b][ods - 1];
				}
				odod[dgt[k]] = !odod[dgt[k]];
			}
			ods = 0;
			for (pp = 0; pp < b; pp++) ods += odod[pp];
			if (ods == 0) a1++;
		}
		j = 0;
		for (t = r; t > 0; t /= b) dgt[j++] = t%b;
		if (j % 2 == 1) {
			for (j--; j > 0; j -= 2) {
				a2 += (ful[j][b][0] / b) * (b - 1);
			}
		}
		else {
			k = j;
			for (j -= 2; j > 0; j -= 2) {
				a2 += (ful[j][b][0] / b) * (b - 1);
			}
			j = k;
			ods = 0;
			for (k = 0; k < b; k++) odod[k] = 0;
			for (pp = 1; pp < dgt[j - 1]; pp++) {
				if (odod[pp] == 0) a2 += ful[j - 1][b][ods + 1] / bino[b][ods + 1];
				else a2 += ful[j - 1][b][ods - 1] / bino[b][ods - 1];
			}
			odod[dgt[j - 1]] = 1;
			for (k = j - 2; k >= 0; k--) {
				ods = 0;
				for (pp = 0; pp < b; pp++) ods += odod[pp];
				for (pp = 0; pp < dgt[k]; pp++) {
					if (odod[pp] == 0) a2 += ful[k][b][ods + 1] / bino[b][ods + 1];
					else a2 += ful[k][b][ods - 1] / bino[b][ods - 1];
				}
				odod[dgt[k]] = !odod[dgt[k]];
			}
			ods = 0;
			for (pp = 0; pp < b; pp++) ods += odod[pp];
			if (ods == 0) a2++;
		}
		printf("%lld\n", a2 - a1);
	}
}