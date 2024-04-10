#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 5005;
const int INF = 0x3f3f3f3f;

int N, M, T;
vector <pii> E[MAXN];
vector <int> inv[MAXN];
int dp[MAXN][MAXN];
int dad[MAXN][MAXN];
vector <int> topo;
bool bio[MAXN];

void load() {
	scanf("%d%d%d", &N, &M, &T);
	while (M--) {
		int u, v, t;
		scanf("%d%d%d", &u, &v, &t);
		E[u].push_back(pii(v, t));
		inv[v].push_back(u);
	}
}

void dfs(int x) {
	bio[x] = true;
	for (int i = 0; i < inv[x].size(); i++)
		if (!bio[inv[x][i]]) 
			dfs(inv[x][i]);
	topo.push_back(x);
}

void solve() {
	dfs(N);
	
	memset(dp, INF, sizeof dp);
	dp[N][0] = 0; 
	for (int i = (int)topo.size() - 1; i >= 0; i--) {
		int x = topo[i];
		for (int k = 1; k <= N; k++) {
			int &ref = dp[x][k];
			for (int j = 0; j < E[x].size(); j++) {
				int cand = dp[E[x][j].first][k - 1] + E[x][j].second;
				if (cand < ref) {
					ref = cand;
					dad[x][k] = E[x][j].first;
				}	
			}
		}
	}
	
	int sol = 0;
	for (int i = N; i; i--)
		if (dp[1][i] <= T) {
			sol = i;
			break;
		}
		
	printf("%d\n", sol + 1);
	int c = 1;
	while (1) {
		printf("%d ", c);
		if (c == N) break;
		c = dad[c][sol];
		sol--;
	}
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}