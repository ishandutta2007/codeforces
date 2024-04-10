#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int N, M;
char mat[MAXN][MAXN];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", mat[i]);
	
	int x1 = 0, y1 = 0;
	int x2 = N, y2 = M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (mat[i][j] == 'B') {
			x1 = max(x1, i);
			y1 = max(y1, j);
			x2 = min(x2, i);
			y2 = min(y2, j);
		}
		
	printf("%d %d\n", (x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1);
	
	return 0;
}