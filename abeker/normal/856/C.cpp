#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 2005;
const int MOD = 998244353;

int N;
int a[MAXN];
int fact[MAXN];
int choose[MAXN][MAXN];
int dp[MAXN][MAXN][15];
int val[2][MAXN][15];
int sz[2];

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

void init() {
	for (int i = 0; i < MAXN; i++) {
		choose[i][0] = 1;
		for (int j = 1; j <= i; j++)
			choose[i][j] = add(choose[i - 1][j], choose[i - 1][j - 1]);
	}
	
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fact[i] = mul(fact[i - 1], i);
}

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

int solve() {
	vector <int> v[2];
	int tot = 0;
	for (int i = 0; i < N; i++) {
		int c = 0, sum = 0;
		for (; a[i]; a[i] /= 10) {
			if (c)
				sum += a[i] % 10;
			else
				sum -= a[i] % 10;
			c ^= 1;
		}
		sum %= 11;
		sum += 11;
		sum %= 11;
		v[c].push_back(sum);
		tot += 6 * sum;
	}
	tot %= 11;
	
	if (v[1].empty())
		return tot ? 0 : fact[N];
		
	for (int i = 0; i < 2; i++) {
		dp[0][0][0] = 1;
		sz[i] = v[i].size();
		for (int j = 0; j < sz[i]; j++)
			for (int k = 0; k <= j + 1; k++)
				for (int l = 0; l < 11; l++) {
					dp[j + 1][k][l] = dp[j][k][l];
					if (k)
						dp[j + 1][k][l] = add(dp[j + 1][k][l], dp[j][k - 1][(l - v[i][j] + 11) % 11]);
				}
		for (int j = 0; j <= sz[i]; j++)
			for (int k = 0; k < 11; k++)
				val[i][j][k] = mul(dp[sz[i]][j][k], mul(fact[j], fact[sz[i] - j]));
	}
	
	int sol = 0;
	for (int i = 0; i < 11; i++)
		for (int k = 0; k <= sz[0]; k++) {
			int coef = mul(choose[sz[0] - k + (sz[1] - 1) / 2][(sz[1] - 1) / 2], choose[k + sz[1] / 2][sz[1] / 2]); 
			sol = add(sol, mul(coef, mul(val[0][k][i], val[1][(sz[1] + 1) / 2][(tot - i + 11) % 11])));
		}
	
	return sol;
}

int main() {
	init();
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		printf("%d\n", solve());
	}
	return 0;
}