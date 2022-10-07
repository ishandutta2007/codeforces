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
#define N 1000005
#define M 2200005
int n, a[N], ans;
struct node{
	int x, y;
	node(){ x = -1, y = -1; }
	void operator += (const int k){
		if (k > y) return x = y, y = k, void(0);
		else if (k > x) return x = k, void(0);
	}
	void operator += (const node rhs){
		*this += rhs.x, *this += rhs.y;
	}
}dp[M];
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i] = read(), dp[a[i]] += i;
	for (register int i = 0; i < 21; ++i)
		for (register int S = 0; S < (1 << 21); ++S)
			if (S >> i & 1) dp[S ^ (1 << i)] += dp[S];
	for (register int i = 1; i <= n - 2; ++i){
		int p = ((1 << 21) - 1) ^ a[i], x = 0;
		for (register int j = 20; ~j; --j)
			if (p >> j & 1 && dp[x | (1 << j)].x > i && dp[x | (1 << j)].y > i) x |= 1 << j;
		ans = std :: max(ans, a[i] | x);
	}
	printf("%d\n", ans);
}