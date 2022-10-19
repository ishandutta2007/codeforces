#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 45;

int N, K;
int mat[MAXN][MAXN];
ll mask[MAXN];
int mx[1 << MAXN / 2];
int dp[1 << MAXN / 2];

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", mat[i] + j);
}

ll intersect(ll subset) {
	ll res = (1ll << N) - 1;
	for (int i = 0; i < N; i++)
		if (subset >> i & 1ll)
			res &= mask[i];
	return res;
}

bool is_clique(ll subset) {
	return (intersect(subset) & subset) == subset;
}

int dfs(int node) {
	int &ref = dp[node];
	if (ref != -1)
		return ref;
	ref = mx[node];
	for (int i = 0; i < N / 2; i++)
		if (node >> i & 1)
			ref = max(ref, dfs(node ^ 1 << i));
	return ref;
}

ld solve() {
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < N; i++) {
		mask[i] = 1ll << i;
		for (int j = 0; j < N; j++)
			if (mat[i][j])
				mask[i] |= 1ll << j;
	}
	
	for (int i = 0; i < 1 << N / 2; i++)
		if (is_clique(i)) 
			mx[i] = __builtin_popcount(i);
		
	int sol = 0;
	for (int i = 0; i < 1 << (N + 1) / 2; i++)
		if (is_clique((ll)i << N / 2))
			sol = max(sol, __builtin_popcount(i) + dfs(intersect((ll)i << N / 2) & ((1ll << N / 2) - 1)));
	
	return (ld)(sol - 1) / (2 * sol) * K * K; 
}

int main() {
	load();
	printf("%.10Lf\n", solve());
	return 0;
}