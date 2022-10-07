#include <cstdio>
#include <cctype>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 100005
#define P 998244353
int n, a[N], dp[N][205][2], pre[N][205][2];
int add(int x, int y){
	return (x += y) >= P ? x - P : x;
}
int del(int x, int y){
	return (x -= y) < 0 ? x + P : x;
}
int suf(int i, int j, int k){
	return del(pre[i][200][k], pre[i][j - 1][k]);
}
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	for (register int i = 1; i <= 200; ++i){
		if (a[1] == -1 || i == a[1]) dp[1][i][0] = 1;
		pre[1][i][0] = add(pre[1][i - 1][0], dp[1][i][0]);
	}
	for (register int i = 2; i <= n; ++i)
		for (register int j = 1; j <= 200; ++j){
			if (a[i] == -1 || a[i] == j){
				dp[i][j][0] = add(pre[i - 1][j - 1][0], pre[i - 1][j - 1][1]);
				dp[i][j][1] = add(dp[i - 1][j][0], suf(i - 1, j, 1));
			}
			pre[i][j][0] = add(pre[i][j - 1][0], dp[i][j][0]);
			pre[i][j][1] = add(pre[i][j - 1][1], dp[i][j][1]);
		}
	printf("%d\n", pre[n][200][1]);
}