#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int w[410][410], L[160010][2], R[160010][2], P[410];
int Gap(int x1, int y1, int x2, int y2){
	if (x1 == x2 && y1 == y2)return 1;
	int r, i, j, k, M, t, LL, RR;
	if (x2 - x1 < y2 - y1){
		int m = (y1 + y2) >> 1;
		r = max(Gap(x1, y1, x2, m), Gap(x1, m + 1, x2, y2));
		for (i = x1; i <= x2; i++){
			for (j = i; j <= x2; j++){
				for (k = y1; k <= y2; k++){
					L[w[j][k]][0] = L[w[j][k]][1] = 0, R[w[j][k]][0] = R[w[j][k]][1] = 999999999;
				}
			}
			LL = y1, RR = y2;
			for (j = y1; j <= m; j++){
				P[j] = y2;
			}
			for (j = i; j <= x2; j++){
				for (k = y1; k <= m; k++){
					t = w[j][k];
					if (L[t][0] < k)L[t][1] = L[t][0], L[t][0] = k;
					else if (L[t][1] < k)L[t][1] = k;
					if (P[L[t][0]] >= R[t][0]) P[L[t][0]] = R[t][0] - 1;
					if (LL <= L[t][1]) LL = L[t][1] + 1;
				}
				for (k = m + 1; k <= y2; k++){
					t = w[j][k];
					if (R[t][0] > k)R[t][1] = R[t][0], R[t][0] = k;
					else if (R[t][1] > k)R[t][1] = k;
					if (P[L[t][0]] >= R[t][0]) P[L[t][0]] = R[t][0] - 1;
					if (RR >= R[t][1]) RR = R[t][1] - 1;
				}
				M = RR;
				for (k = m; k >= LL; k--){
					if (M > P[k]) M = P[k];
					if (r < (M - k + 1) * (j - i + 1))r = (M - k + 1) * (j - i + 1);
				}
			}
		}
	}
	else{
		int m = (x1 + x2) >> 1;
		r = max(Gap(x1, y1, m, y2), Gap(m + 1, y1, x2, y2));
		for (i = y1; i <= y2; i++){
			M = x2 - x1 + 1;
			for (j = i; j <= y2; j++){
				for (k = x1; k <= x2; k++){
					L[w[k][j]][0] = L[w[k][j]][1] = 0, R[w[k][j]][0] = R[w[k][j]][1] = 999999999;
				}
			}
			LL = x1, RR = x2;
			for (j = x1; j <= m; j++){
				P[j] = x2;
			}
			for (j = i; j <= y2; j++){
				for (k = x1; k <= m; k++){
					t = w[k][j];
					if (L[t][0] < k)L[t][1] = L[t][0], L[t][0] = k;
					else if (L[t][1] < k)L[t][1] = k;
					if (P[L[t][0]] >= R[t][0]) P[L[t][0]] = R[t][0] - 1;
					if (LL <= L[t][1]) LL = L[t][1] + 1;
				}
				for (k = m + 1; k <= x2; k++){
					t = w[k][j];
					if (R[t][0] > k)R[t][1] = R[t][0], R[t][0] = k;
					else if (R[t][1] > k)R[t][1] = k;
					if (P[L[t][0]] >= R[t][0]) P[L[t][0]] = R[t][0] - 1;
					if (RR >= R[t][1]) RR = R[t][1] - 1;
				}
				M = RR;
				for (k = m; k >= LL; k--){
					if (M > P[k]) M = P[k];
					if (r < (M - k + 1) * (j - i + 1))r = (M - k + 1) * (j - i + 1);
				}
			}
		}
	}
	return r;
}
int main()
{
	int i, j, n, m;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			scanf("%d", &w[i][j]);
		}
	}
	printf("%d\n", Gap(1, 1, n, m));
}