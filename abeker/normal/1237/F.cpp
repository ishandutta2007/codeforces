#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3.6e3 + 5;
const int MOD = 998244353;

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		return x - MOD;
	if (x < 0)
		return x + MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int H, W, N;
int fact[MAXN];
int choose[MAXN][MAXN];
vector <bool> rows, cols;

vector <vector <int>> get_ways(vector <bool> used) {
	int n = used.size();
	vector <vector <int>> dp(n);
	int free = 0;
	for (int i = 0; i < n; i++) {
		dp[i].resize(n / 2 + 1);
		if (!i) {
			dp[0][0] = 1;
			continue;
		}
		for (int j = 0; j < dp[i].size(); j++) {
			dp[i][j] = dp[i - 1][j];
			if (i >= 2 && j && !used[i] && !used[i - 1])
				dp[i][j] = add(dp[i][j], dp[i - 2][j - 1]);
		}
		free += !used[i];
	}
	vector <vector <int>> res(dp[n - 1].size());
	for (int i = 0; i < dp[n - 1].size(); i++) {
		res[i].resize(free + 1);
		if (2 * i > free)
			continue;
		for (int j = 0; j <= free; j++)
			res[i][j] = mul(choose[free - 2 * i][j], dp[n - 1][i]);
	}
	return res;
}

void load() {
	scanf("%d%d%d", &H, &W, &N);
	rows.resize(H + 1);
	cols.resize(W + 1);
	while (N--) {
		int r1, c1, r2, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		rows[r1] = rows[r2] = true;
		cols[c1] = cols[c2] = true;
	}
}

int solve() {
	choose[0][0] = 1;
	for (int i = 1; i < MAXN; i++) {
		choose[i][0] = 1;
		for (int j = 1; j <= i; j++)
			choose[i][j] = add(choose[i - 1][j], choose[i - 1][j - 1]);
	}
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fact[i] = mul(fact[i - 1], i);
	
	vector <vector <int>> R = get_ways(rows);
	vector <vector <int>> C = get_ways(cols);
	
	int sol = 0;
	for (int hor = 0; hor <= W / 2; hor++)
		for (int ver = 0; ver <= H / 2; ver++)
			sol = add(sol, mul(mul(fact[hor], fact[ver]), mul(hor < R[ver].size() ? R[ver][hor] : 0, ver < C[hor].size() ? C[hor][ver] : 0)));
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}