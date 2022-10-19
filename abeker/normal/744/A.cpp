#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1005;

int N, M, K;
int c[MAXN];
vector <int> E[MAXN];
bool bio[MAXN];

void load() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < K; i++)
		scanf("%d", c + i);
	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
}

int dfs(int x) {
	if (bio[x])
		return 0;
	bio[x] = true;
	int res = 1;
	for (int nxt : E[x])
		res += dfs(nxt);
	return res;
}

int choose(int n) {
	return n * (n - 1) / 2;
}

int solve() {
	int mx = 0, sum = 0;
	for (int i = 0; i < K; i++) {
		int tmp = dfs(c[i]);
		mx = max(mx, tmp);
		sum += choose(tmp);
	}
	sum -= choose(mx);
	for (int i = 1; i <= N; i++)
		mx += dfs(i);
	sum += choose(mx);	
	
	return sum - M;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}