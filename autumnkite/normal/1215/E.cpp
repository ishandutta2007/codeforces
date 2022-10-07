#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 400005
#define INF 0x3f3f3f3f3f3f3f3fll
int n, a[N], Log[1 << 20], pre[N][20], m;
long long Pre[20][20], sum[20], g[1 << 20][20], f[1 << 20];
std :: vector<int> pos[20];
int lowbit(int x){
	return Log[x & -x];
}
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i)
		a[i] = read(), m = std :: max(m, a[i]), pos[--a[i]].push_back(i);
	for (register int i = 1; i <= n; ++i){
		for (register int j = 0; j < m; ++j) pre[i][j] = pre[i - 1][j];
		++pre[i][a[i]];
	}
	for (register int i = 0; i < m; ++i){
		for (register int j = 0; j < m; ++j)
			for (int k : pos[j]) Pre[i][j] += pre[k][i];
		g[1 << i][i] = Pre[i][i];
	}
	for (register int i = 0; i < m; ++i)
		for (int j : pos[i]) sum[i] += j;
	Log[0] = -1;
	for (register int i = 1; i < (1 << m); ++i) Log[i] = Log[i >> 1] + 1;
	for (register int i = 1; i < (1 << m); ++i)
		for (register int j = 0; j < m; ++j)
			if ((i >> j & 1) && (i ^ (1 << j))){
				int k = lowbit(i ^ (1 << j));
				g[i][j] = g[i ^ (1 << k)][j] + Pre[k][j];
			}
	f[0] = 0;
	for (register int i = 1; i < (1 << m); ++i){
		f[i] = INF;
		for (register int j = 0; j < m; ++j)
			if (i >> j & 1) f[i] = std :: min(f[i], f[i ^ (1 << j)] + sum[j] - g[i][j]);
	}
	printf("%lld\n", f[(1 << m) - 1]);
}