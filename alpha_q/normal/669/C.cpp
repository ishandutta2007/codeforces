#include <bits/stdc++.h>

using namespace std;

int n, m, A[105][105], t, q, r, c, x;
int Op[10005][5];

int main (int argc, char const *argv[]) {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d", &t);
		if (t == 3) {
			Op[i][0] = 3;
			scanf("%d %d %d", &Op[i][1], &Op[i][2], &Op[i][3]);
		}
		if (t == 1) {
			Op[i][0] = 1;
			scanf("%d", &Op[i][1]);
		}
		if (t == 2) {
			Op[i][0] = 2;
			scanf("%d", &Op[i][1]);
		}
	}
	
	/*for (int i = 1; i <= q; i++) {
		for (int j=  0; j <= 3; j ++)cout<<Op[i][j]<<" ";
		cout <<endl;
	}*/

	for (int i = q; i >= 1; i--) {
		t = Op[i][0];
		if (t == 3) {
			r = Op[i][1], c = Op[i][2], x = Op[i][3];
			A[r][c] = x;
		} 
		if (t == 1) {
			x = Op[i][1];
			int right = A[x][m];
			for (int k = m; k >= 2; k--) A[x][k] = A[x][k - 1];
			A[x][1] = right;
		}
		if (t == 2) {
			x = Op[i][1];
			int bottom = A[n][x];
			for (int k = n; k >= 2; k--) A[k][x] = A[k - 1][x];
			A[1][x] = bottom;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) printf("%d ", A[i][j]);
		printf("\n");
	}
	return 0;
}