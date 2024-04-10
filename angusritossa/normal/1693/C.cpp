#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
#define MAXN 200010
int n, m;
vector<int> adj[MAXN], revadj[MAXN];
int done[MAXN], dis[MAXN];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int numAdj[MAXN];
void reachVert(int a, int d) {
	done[a] = true;
	dis[a] = d;
	for (auto b : revadj[a]) {
		numAdj[b]++;
		int newd = d + 1 - numAdj[b] + adj[b].size();
		if (newd < dis[b]) {
			dis[b] = newd;
			pq.push({newd, b});
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		dis[i] = 1e9;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		revadj[b].push_back(a);
	}
	reachVert(n, 0);
	while (pq.size()) {
		int a = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if (d != dis[a]) continue;
		reachVert(a, d);
	}
	printf("%d\n", dis[1]);
}