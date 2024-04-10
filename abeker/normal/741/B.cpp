#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1005;

int N, M, W;
int b[MAXN], t[MAXN];
vector <int> E[MAXN];
bool bio[MAXN];
vector <int> comp;
int dp[MAXN][2];
int curr;

void load() {
	scanf("%d%d%d", &N, &M, &W);
	for (int i = 1; i <= N; i++)
		scanf("%d", t + i);
	for (int i = 1; i <= N; i++) 
		scanf("%d", b + i);
	while (M--) {
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
}

void dfs(int x) {
	bio[x] = true;
	comp.push_back(x);
	for (int nxt : E[x])
		if (!bio[nxt])
			dfs(nxt);
}

void update(int &ref, int val) {
	ref = max(ref, val);
}

void trans(int c, int v) {
	for (int i = 0; i <= W - c; i++)
		update(dp[i + c][curr ^ 1], dp[i][curr] + v);
}

int solve() {
	for (int i = 1; i <= N; i++) {
		if (bio[i])	
			continue;
		comp.clear();
		dfs(i);
		int cost = 0, tot = 0;
		for (int it : comp) {
			trans(t[it], b[it]);
			cost += t[it];
			tot += b[it];
		}
		trans(cost, tot);
		for (int j = 0; j <= W; j++)
			update(dp[j][curr ^ 1], dp[j][curr]);
		curr ^= 1;
	}
	
	return dp[W][curr];
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}