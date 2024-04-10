#include <cstdio>
#include <cstring>
#define N 55
int n, a[N][N], b[N][N];
int query(int x1, int y1, int x2, int y2){
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	scanf("%d", &x1);
	return x1;
}
bool myq(int a[N][N], int i, int j){
	return a[i][j] == a[i + 1][j + 2] && 
		(a[i + 1][j] == a[i + 1][j + 1] || 
		a[i][j + 1] == a[i + 1][j + 1] || 
		a[i][j + 1] == a[i][j + 2]);
}
bool check(){
	for (register int i = 1; i <= n - 1; ++i)
		for (register int j = 1; j <= n - 2; ++j)
			if (myq(a, i, j) != myq(b, i, j))
				return myq(a, i, j) == query(i, j, i + 1, j + 2);
}
int main(){
	memset(a, -1, sizeof a);
	scanf("%d", &n);
	a[1][1] = 1, a[1][2] = 0, a[n][n] = 0, a[2][3] = query(1, 2, 2, 3) ^ 1;
	a[2][1] = query(2, 1, 2, 3) ^ a[2][3] ^ 1;
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= n; ++j){
			if (~a[i][j]) continue;
			if (i == 1) a[i][j] = query(i, j - 2, i, j) ^ a[i][j - 2] ^ 1;
			else if (j == 1) a[i][j] = query(i - 2, j, i, j) ^ a[i - 2][j] ^ 1;
			else a[i][j] = query(i - 1, j - 1, i, j) ^ a[i - 1][j - 1] ^ 1;
		}
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= n; ++j)
			if ((i + j) & 1) b[i][j] = a[i][j] ^ 1; else b[i][j] = a[i][j];
	if (!check()) memcpy(a, b, sizeof a);
	printf("!\n");
	for (register int i = 1; i <= n; ++i){
		for (register int j = 1; j <= n; ++j) printf("%d", a[i][j]);
		putchar('\n');
	}
}