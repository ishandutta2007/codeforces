#include<cstdio>
#include<algorithm>
using namespace std;
int P[6][8] = {
	{1,3,5,7,9,11,24,22},
	{ 2,4,6,8,10,12,23,21 },
{13,14,5,6,17,18,21,22},
{15,16,7,8,19,20,23,24},
{1,13,15,11,12,20,18,2},
{3,14,16,9,10,19,17,4}
};
int w[25], TP[25];
int n;
int main() {
	int i, j, k;
	for (i = 1; i <= 24; i++) {
		scanf("%d", &w[i]);
	}
	for (i = 0; i < 6; i++) {
		for (j = 1; j <= 24; j++)TP[j] = w[j];
		for (j = 0; j < 8; j++) {
			TP[P[i][(j + 2) % 8]] = w[P[i][j]];
		}
		int ck = 0;
		for (j = 1; j <= 24; j += 4) {
			for (k = j; k < j + 4; k++) {
				if (TP[k] != TP[j])ck = 1;
			}
		}
		if (!ck) {
			puts("YES");
			return 0;
		}

		for (j = 1; j <= 24; j++)TP[j] = w[j];
		for (j = 0; j < 8; j++) {
			TP[P[i][(j + 6) % 8]] = w[P[i][j]];
		}
		ck = 0;
		for (j = 1; j <= 24; j += 4) {
			for (k = j; k < j + 4; k++) {
				if (TP[k] != TP[j])ck = 1;
			}
		}
		if (!ck) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}