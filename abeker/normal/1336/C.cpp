#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e3 + 5;
const int MOD = 998244353;

int N, M;
char s[MAXN], t[MAXN];
int dp1[MAXN][MAXN], dp2[MAXN][MAXN];

void load() {
	scanf("%s%s", s + 1, t + 1);
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int rec1(int l, int r) {
	int &ref = dp1[l][r];
	if (ref != -1)
		return ref;
	if (r == N + 2)
		return ref = 0;
	if (l == 0 && r > M)
		return ref = N + 2 - r;
	ref = 0;
	int pos = r - l;
	if (l && s[pos] == t[l])
		ref = add(ref, rec1(l - 1, r));
	if (r > M || s[pos] == t[r])
		ref = add(ref, rec1(l, r + 1));
	return ref;
}

int rec2(int x, int y) {
	int &ref = dp2[x][y];
	if (ref != -1)
		return ref;
	if (x == N + 1)
		return ref = !y;
	if (y == 0)
		return ref = N + 2 - x; 
	ref = 0;
	if (y < M)
		ref = add(ref, rec2(x + 1, y));
	if (s[x] == t[y])
		ref = add(ref, rec2(x + 1, y - 1));
	return ref;
}

int solve() {
	memset(dp1, -1, sizeof dp1);
	memset(dp2, -1, sizeof dp2);
	
	N = strlen(s + 1);
	M = strlen(t + 1);
	
	int sol = 0;
	for (int i = 0; i < M; i++) 
		sol = add(sol, rec1(i, i + 1));
		
	int pot = 1;
	for (int i = 1; i <= N; i++) {
		sol = add(sol, mul(pot, rec2(i, M)));
		pot = mul(pot, 2);
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}