#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 200005;
const int MAXK = 2005;
const int LOG = 23;
const int MOD = 1000000007;

int N, M, K, S;
pii cell[MAXK];
int fact[MAXN], inv[MAXN];
int dp[MAXK][LOG];

inline int add(int x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	else if (x < 0) x += MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int pot(int x, int y) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2) res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

int inverse(int x) {
	return pot(x, MOD - 2);
}

int choose(int n, int k) {
	return n < k || k < 0 ? 0 : mul(fact[n], mul(inv[k], inv[n - k]));
}

int path(pii A, pii B) {
	return choose(B.first - A.first + B.second - A.second, B.first - A.first);
}

void load() {
	scanf("%d%d%d%d", &N, &M, &K, &S);
	for (int i = 0; i < K; i++)
		scanf("%d%d", &cell[i].first, &cell[i].second);
}

int solve() {
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= N + M; i++) {
		fact[i] = mul(fact[i - 1], i);
		inv[i] = inverse(fact[i]);
	}
	
	sort(cell, cell + K);
	
	int en = 0;
	if (cell[K - 1] != pii(N, M)) {
		cell[K++] = pii(N, M);
		en = 1;
	}
	
	int st = 1;
	if (cell[0] != pii(1, 1)) {
		cell[K++] = pii(1, 1);
		st = 0;
	}
	
	sort(cell, cell + K);
	
	dp[0][0] = 1;
	for (int i = 1; i < K; i++) 
		for (int j = 1; j < LOG; j++) 
			for (int k = 0; k < i; k++) 
				if (cell[k].second <= cell[i].second)
					dp[i][j] = add(dp[i][j], mul(add(dp[k][j - 1], -dp[k][j]), path(cell[k], cell[i])));
					
	int tot = path(cell[0], cell[K - 1]);
	int rest = tot, sum = 0;
	for (int i = 0; i < LOG; i++) {
		int cnt = i + en - st;
		if (cnt >= 0) {
			sum = add(sum, mul(dp[K - 1][cnt], S));
			rest = add(rest, -dp[K - 1][cnt]);
		}
		S = (S + 1) / 2;
	}
	
	return mul(add(rest, sum), inverse(tot));
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}