#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 1005
int n, a[N][N];
int main(){
	n = read();
	for (register int i = 0; i < n; ++i)
		for (register int j = 0; j < n; ++j)
			a[i][j] = read();
	for (register int i = 0; i < n; ++i){
		int p1 = (i - 1 + n) % n, p2 = (i + 1) % n;
		int x = sqrt(1ll * a[p1][i] * a[p2][i] / a[p1][p2]);
		printf("%d ", x);
	}
}