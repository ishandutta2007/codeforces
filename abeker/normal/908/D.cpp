#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
const int MOD = 1e9 + 7;

int K, A, B, C;
int dp[MAXN][MAXN];

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	else if (x < 0)
		x += MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int pot(int x, int y) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2)
			res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

int f(int x, int y) {
	int &ref = dp[x][y];
	if (ref != -1)
		return ref;
	
	if (y >= K)
		return ref = y;
		
	if (x >= K)
		return ref = add(x + y, C);
	
	if (!x)
		return ref = f(x + 1, y);
	
	return ref = add(mul(A, f(x + 1, y)), mul(B, f(x, x + y)));
}

int main() {
	scanf("%d%d%d", &K, &A, &B);
	
	int inv = pot(A + B, MOD - 2);
	A = mul(A, inv);
	B = mul(B, inv);
	C = mul(A, pot(B, MOD - 2));
	
	memset(dp, -1, sizeof dp);
		
	printf("%d\n", f(0, 0));
	
	return 0;
}