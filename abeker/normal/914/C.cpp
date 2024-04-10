#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MOD = 1e9 + 7;

int N, K;
char s[MAXN];
int choose[MAXN][MAXN];
int f[MAXN];

void load() {
	scanf("%s%d", s, &K);
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	return x;
}

int calc(int x) {
	int cnt = 0, res = 0;
	for (int i = 0; i < N; i++) {
		if (s[i] == '1' && cnt <= x)
			res = add(res, choose[N - i - 1][x - cnt]);
		cnt += s[i] - '0';
	}
	if (cnt == x)
		res = add(res, 1);
	return res;
}

int solve() {
	if (!K)
		return 1;

	N = strlen(s);
	
	if (K == 1)
		return N - 1;
	
	for (int i = 2; i < MAXN; i++)
		f[i] = f[__builtin_popcount(i)] + 1;
	
	choose[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		choose[i][0] = 1;
		for (int j = 1; j <= i; j++)
			choose[i][j] = add(choose[i - 1][j - 1], choose[i - 1][j]);
	}
	
	int sol = 0;
	for (int i = 1; i < MAXN; i++)
		if (f[i] == K - 1) 
			sol = add(sol, calc(i));
			
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}