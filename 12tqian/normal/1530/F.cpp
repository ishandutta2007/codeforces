#include <bits/stdc++.h>

using namespace std;

const int MOD = 31607;
const int INV = 3973;

int add(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) a += MOD;
	return a;
}

int mul(int a, int b) {
	return a * b % MOD;
}

int n, a[21][21], prob[1 << 23];

void dfs(int i, int j, int mask, int forced, int ways) {
	if (j == n) {
		prob[mask] = mul(prob[mask], mul(forced, sub(1, ways)));
		return;
	}
	if ((i == j && (mask >> n) & 1) || (i + j == n - 1 && (mask >> (n + 1)) & 1)) {
		dfs(i, j + 1, mask, mul(forced, a[i][j]), ways);
		dfs(i, j + 1, mask + (1 << j), mul(forced, a[i][j]), ways);
	} else {
		dfs(i, j + 1, mask, forced, mul(ways, a[i][j]));
		dfs(i, j + 1, mask + (1 << j), mul(forced, a[i][j]), ways);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) {
			cin >> a[i][j];
			a[i][j] = mul(a[i][j], INV);
		}

	fill(prob, prob + (1 << (n + 2)), 1);
	for (int mainDiag=0; mainDiag<2; ++mainDiag)
		for (int antiDiag=0; antiDiag<2; ++antiDiag)
			for (int i=0; i<n; i++)
				dfs(i, 0, (mainDiag << n) | (antiDiag << (n + 1)), 1, 1);

	int ret = 1;
	for (int mask=0; mask<1<<(n+2); ++mask) {
		if (__builtin_parity(mask))
			ret = add(ret, prob[mask]);
		else
			ret = sub(ret, prob[mask]);
	}
	cout << ret << "\n";

	return 0;
}