#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 7005;

const char msg[3][10] = {"Lose", "Win", "Loop"};

int N;
int k[2];
int a[2][MAXN];
int dp[MAXN][2];
int deg[MAXN][2];
queue <pii> Q;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < 2; i++) {
		scanf("%d", k + i);
		for (int j = 0; j < k[i]; j++)
			scanf("%d", a[i] + j);
	}
}

void solve() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 2; j++) {
			dp[i][j] = 2;
			deg[i][j] = k[j];
		}
	
	dp[0][0] = dp[0][1] = 0;
	Q.push({0, 0});
	Q.push({0, 1});
	while (!Q.empty()) {
		int pos = Q.front().first;
		int who = Q.front().second;
		Q.pop();
		for (int i = 0; i < k[who ^ 1]; i++) {
			int node = (pos - a[who ^ 1][i] + N) % N;
			if (!dp[pos][who]) {
				if (dp[node][who ^ 1] == 2) {
					dp[node][who ^ 1] = 1;
					Q.push({node, who ^ 1});
				}	
			}
			else if (--deg[node][who ^ 1] == 0) {
				if (dp[node][who ^ 1] == 2) {
					dp[node][who ^ 1] = 0;
					Q.push({node, who ^ 1});
				}	
			}
		}
	}
	
	for (int j = 0; j < 2; j++, puts(""))
		for (int i = 1; i < N; i++)
			printf("%s ", msg[dp[i][j]]);
}

int main() {
	load();
	solve();
	return 0;
}