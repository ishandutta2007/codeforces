#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <map>
using namespace std;

const int MAXN = 755;
const int MOD = 1000000007;

int N;
int choose[MAXN][MAXN];
int dp[2][MAXN];
map <int, int> cnt;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		int mx = 1;
		for (int j = 1; j * j <= x; j++)
			if (!(x % (j * j)))
				mx = j * j;
		cnt[x / mx]++;
	}
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	return x;
}

inline void upd(int &x, int y) {
	x = add(x, y);
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int solve() {
	choose[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		choose[i][0] = 1;
		for (int j = 1; j <= i; j++)
			choose[i][j] = add(choose[i - 1][j], choose[i - 1][j - 1]);
	}
		
	int c = 0, tot = 0;
	dp[c][0] = 1;
	int sol = 1;
	for (auto it : cnt) {
		for (int i = 1; i <= it.second; i++)
			sol = mul(sol, i);
		memset(dp[c ^ 1], 0, sizeof dp[c ^ 1]);
		for (int i = 0; i < N && i <= tot; i++)
			for (int k = 1; k <= tot + 1 && k <= it.second; k++) 
				for (int l = 0; l <= k && l <= i; l++)
					upd(dp[c ^ 1][i + it.second - k - l], mul(dp[c][i], mul(mul(choose[i][l], choose[tot + 1 - i][k - l]), choose[it.second - 1][k - 1])));
		tot += it.second;
		c ^= 1;
	}
	
	return mul(sol, dp[c][0]);
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}