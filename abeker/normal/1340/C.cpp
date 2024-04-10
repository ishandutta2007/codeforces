#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1e6 + 5;
const int MAXM = 1e4 + 5;
const int MAXG = 1e3 + 5;
const int INF1 = 0x3f3f3f3f;
const ll INF2 = 1e18;

int N, M, G, R;
int d[MAXM];
int dist[MAXM][MAXG];
deque <pii> Q;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
		scanf("%d", d + i);
	scanf("%d%d", &G, &R);
}

inline void add_edge(pii from, pii to) {
	int weight = 0;
	if (to.second == G) {
		to.second = 0;
		weight = 1;
	}
	int cand = dist[from.first][from.second] + weight;
	if (cand >= dist[to.first][to.second])
		return;
	dist[to.first][to.second] = cand;
	if (weight)
		Q.push_back(to);
	else
		Q.push_front(to);
}

ll solve() {
	memset(dist, INF1, sizeof dist);
	
	sort(d, d + M);
	
	dist[0][0] = 0;
	Q.push_back({0, 0});
	while (!Q.empty()) {
		pii curr = Q.front();
		Q.pop_front();
		int lft = curr.first ? d[curr.first] - d[curr.first - 1] : MAXN;
		int rig = curr.first < M - 1 ? d[curr.first + 1] - d[curr.first] : MAXN;
		if (curr.second + lft <= G)
			add_edge(curr, {curr.first - 1, curr.second + lft});
		if (curr.second + rig <= G)
			add_edge(curr, {curr.first + 1, curr.second + rig});
	}
		
	ll ans = INF2;	
	for (int i = 0; i < M; i++)
		if (dist[i][0] != INF1 && d[i] + G >= N)
			ans = min(ans, (ll)dist[i][0] * (G + R) + N - d[i]);
		
	return ans == INF2 ? -1 : ans;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}