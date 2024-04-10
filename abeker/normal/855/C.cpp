#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int MOD = 1e9 + 7;

int N, M, K, X;
vector <int> E[MAXN];
int dp[MAXN][15][3];
int tmp[MAXN][15];
int tot[MAXN][15][3];
int coef[3];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	scanf("%d%d", &K, &X);
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

void dfs(int x, int p) {
	vector <int> ch;
	for (auto it : E[x])
		if (it != p) {
			dfs(it, x);
			ch.push_back(it);
		}
	
	for (int it = 0; it < 3; it++) {
		for (int k = 0; k <= ch.size(); k++)
			for (int i = 0; i <= X; i++)
				tmp[k][i] = 0;
		tmp[0][0] = 1;
		for (int k = 0; k < ch.size(); k++)
			for (int i = 0; i <= X; i++)
				for (int j = 0; j <= X; j++)
					if (i + j <= X)
						tmp[k + 1][i + j] = add(tmp[k + 1][i + j], mul(tmp[k][i], tot[ch[k]][j][it]));
		for (int i = 0; i <= X; i++) {
			int nxt = i - (it == 1);
			if (nxt >= 0)
				dp[x][i][it] = mul(tmp[ch.size()][nxt], coef[it]);
		}
	}
	
	for (int i = 0; i <= X; i++) {
		tot[x][i][0] = add(dp[x][i][0], add(dp[x][i][1], dp[x][i][2]));
		tot[x][i][1] = dp[x][i][0];
		tot[x][i][2] = add(dp[x][i][0], dp[x][i][2]);
	}
}

int solve() {
	coef[0] = K - 1;
	coef[1] = 1;
	coef[2] = M - K;
	
	dfs(1, 0);
	
	int sol = 0;
	for (int i = 0; i <= X; i++)
		for (int j = 0; j < 3; j++)
			sol = add(sol, dp[1][i][j]);
	
	return sol;	
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}