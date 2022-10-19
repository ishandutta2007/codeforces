#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 5e5 + 5;

int N, K;
vector <pii> adj[MAXN];
ll dp[MAXN][2];

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++)
		adj[i].clear();
	for (int i = 1; i < N; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
}

ll solve(int x, int p) {
	vector <pii> ch;
	for (auto it : adj[x])
		if (it.first != p) {
			solve(it.first, x);
			ch.push_back(it);
		}
	
	for (int up = 0; up < 2; up++) {
		dp[x][up] = 0;
		vector <ll> diffs;
		for (auto it : ch) {
			dp[x][up] += dp[it.first][0];
		 	diffs.push_back(dp[it.first][1] + it.second - dp[it.first][0]);
		}
		sort(diffs.begin(), diffs.end(), greater <ll> ());
		while (!diffs.empty() && diffs.back() < 0)
			diffs.pop_back(); 
		int take = min((int)diffs.size(), K - up);
		for (int i = 0; i < take; i++)
			dp[x][up] += diffs[i];
	}
	
	return dp[x][0];
}

int main() {
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		load();
		printf("%lld\n", solve(1, 0));
	}
	return 0;
}