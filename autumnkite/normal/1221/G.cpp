#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
int n, m, e[45][45];
long long ans;
bool A[1 << 20], B[1 << 20];
int S[1 << 20], dp[1 << 20];
long long no0(){
	int n0 = n >> 1, n1 = n - n0, U = (1 << n1) - 1;
	for (register int i = 0; i < n0; ++i)
		for (register int j = i + 1; j < n0; ++j)
			if (e[i][j]) A[(1 << i) | (1 << j)] = 1;
	for (register int i = 0; i < n1; ++i)
		for (register int j = i + 1; j < n1; ++j)
			if (e[i + n0][j + n0]) B[(1 << i) | (1 << j)] = 1;
	for (register int i = 0; i < n0; ++i)
		for (register int j = 0; j < (1 << n0); ++j)
			if (j >> i & 1) A[j] |= A[j ^ (1 << i)];
	for (register int i = 0; i < n1; ++i)
		for (register int j = 0; j < (1 << n1); ++j)
			if (j >> i & 1) B[j] |= B[j ^ (1 << i)];
	// A[i]  Ai  0 1 B[i] 
	for (register int i = 0; i < (1 << n1); ++i)
		if (!B[i]) dp[i] = 1;
	for (register int i = 0; i < n1; ++i)
		for (register int j = 0; j < (1 << n1); ++j)
			if (j >> i & 1) dp[j] += dp[j ^ (1 << i)];
	// dp[i]  B  i 
	for (register int i = 0; i < n0; ++i)
		for (register int j = 0; j < n1; ++j)
			if (e[i][j + n0]) S[1 << i] |= 1 << j;
	for (register int i = 0; i < n0; ++i)
		for (register int j = 0; j < (1 << n0); ++j)
			if (j >> i & 1) S[j] |= S[j ^ (1 << i)];
	// for (register int i = 0; i < (1 << n0); ++i) printf("%d ", S[i]); putchar('\n');
	// S[i]  A  i  0 B  1 
	long long res = 0;
	for (register int i = 0; i < (1 << n0); ++i)
		if (!A[i]) res += dp[U ^ S[i]];
	// B  S[i]  1 0  U ^ S[i] 
	return res;
}
int fa[45], sz[45], s1, s2;
int find(int x){
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}
void merge(int x, int y){
	x = find(x), y = find(y);
	if (x != y) fa[y] = x, sz[x] += sz[y];
}
int h, t, Q[45], dep[45];
bool bfs(int s){
	h = 0, t = 1, Q[t] = s, dep[s] = 1;
	while (h < t){
		int u = Q[++h];
		for (register int v = 0; v < n; ++v)
			if (e[u][v]){
				if (!dep[v]) dep[v] = dep[u] + 1, Q[++t] = v;
				else if ((dep[u] & 1) == (dep[v] & 1)) return 0;
			}
	}
	return 1;
}
long long only1(){
	for (register int i = 0; i < n; ++i)
		if (!dep[i]) if (!bfs(i)) return 0;
	return 1ll << s1;
}
int main(){
	n = read(), m = read();
	if (m == 0) return puts("0"), 0;
	for (register int i = 0; i < n; ++i) fa[i] = i, sz[i] = 1;
	for (register int i = 1; i <= m; ++i){
		int u = read() - 1, v = read() - 1;
		e[u][v] = e[v][u] = 1, merge(u, v);
	}
	for (register int i = 0; i < n; ++i)
		if (find(i) == i) ++s1, sz[i] == 1 ? ++s2 : 0;
	ans = (1ll << n) - no0() * 2 - (1ll << s1) + (1ll << s2) * 2 + only1();
	printf("%lld\n", ans);
}
/*
xuxuxuxuxu
012=-0-1-2+01+02+12-012
2^n
0/2A,BAAB1/0DP
1012^
01/12>11/02^
022^0
012m=0m=00
*/