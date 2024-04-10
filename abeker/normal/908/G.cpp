#include <bits/stdc++.h>
using namespace std;

const int MAXN = 705;
const int MOD = 1e9 + 7;

int N;
char s[MAXN];
int choose[MAXN][MAXN];
int pre[11][MAXN];

void load() {
	scanf("%s", s);
}

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

int get(int n, int m, int k) {
	return k < 0 ? 0 : mul(choose[n][k], mul(pre[10 - m][k], pre[m][n - k]));
}

int calc(int dig, int occ) {
	int cnt = 0, res = 0;
	for (int i = 0; i < N; i++) {
		int tmp = s[i] - '0';
		for (int j = 0; j < tmp; j++)
			res = add(res, get(N - i - 1, dig, occ - cnt - (j >= dig)));
		cnt += tmp >= dig;
	}
	return add(res, cnt == occ);
}

int solve() {
	N = strlen(s);
	
	choose[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		choose[i][0] = 1;
		for (int j = 1; j <= i; j++)
			choose[i][j] = add(choose[i - 1][j], choose[i - 1][j - 1]);
	}
	
	for (int i = 1; i <= 10; i++)
		for (int j = 0; j <= N; j++)
			pre[i][j] = pot(i, j);
	
	int sol = 0;
	for (int i = 1; i < 10; i++)
		for (int j = 0; j <= N; j++) 
			sol = add(sol, mul(calc(i, j), pre[10][j]));
	
	int num = 1;
	for (int i = 0; i < N; i++)
		num = add(num, mul(pre[10][N - i - 1], s[i] - '0'));
		
	return add(mul(sol, pot(9, MOD - 2)), -num);
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}