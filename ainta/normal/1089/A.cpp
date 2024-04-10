#include<cstdio>
#include<algorithm>
using namespace std;
int D[4][4][210][210], Path[4][4][210][210][2], w[5][2], cnt;
void UDT(int i, int j, int k, int l, int a, int b) {
	if (abs(a - b) < 2 || a < 0 || b < 0)return;
	if (k + a > 200 || l + b > 200)return;
	int M = 25;
	if (i == 2 && j == 2)M = 15;
	if (a < M&&b < M)return;
	if (max(a, b) != M && abs(a - b) != 2) return;
		if (a >b) {
			D[i + 1][j][k + a][l + b] = 1;
			Path[i + 1][j][k + a][l + b][0] = a;
			Path[i + 1][j][k + a][l + b][1] = b;
		}
		else {
			D[i][j + 1][k + a][l + b] = 1;
			Path[i][j + 1][k + a][l + b][0] = a;
			Path[i][j + 1][k + a][l + b][1] = b;
		}

}
int main() {
	int i, j, k, l, ii, jj;
	D[0][0][0][0] = 1;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			int M = 25;
			if (i == 2 && j == 2)M = 15;
			for (k = 0; k <= 200; k++) {
				for (l = 0; l <= 200; l++) {
					if (!D[i][j][k][l])continue;
					for (ii = 0; ii+k<=200; ii++) {
						if (ii == M) {
							for (jj = 0; jj <= M - 2; jj++) {
								UDT(i, j, k, l, ii, jj);
							}
						}
						if(ii<=M+2) UDT(i, j, k, l, ii, M);
						UDT(i, j, k, l, ii, ii-2);
						UDT(i, j, k, l, ii, ii+2);
					}
				}
			}
		}
	}
	int TC, a, b;
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d%d", &a, &b);
		int i, j, Mx = -5, pa, pb;
		for (i = 0; i <= 3; i++)for (j = 0; j <= 3; j++) {
			if (max(i, j) == 3 && D[i][j][a][b] && Mx < i-j) {
				Mx = max(Mx, i - j);
				pa = i, pb = j;
			}
		}
		if (Mx == -5) {
			puts("Impossible");
			continue;
		}
		printf("%d:%d\n", pa, pb);
		int c = pa + pb;
		for(i=c-1;i>=0;i--) {
			w[i][0] = Path[pa][pb][a][b][0];
			w[i][1] = Path[pa][pb][a][b][1];
			if (w[i][0] < w[i][1])pb--;
			else pa--;
			a -= w[i][0], b -= w[i][1];
		}
		for (i = 0; i <c; i++)printf("%d:%d ", w[i][0], w[i][1]);
		puts("");
	}
}