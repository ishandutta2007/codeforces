#include <bits/stdc++.h>
using namespace std;
#define MAXN 500010
int a[2*MAXN], b[2*MAXN], l[2*MAXN], r[2*MAXN], n, m;
vector<int> adj[MAXN][2]; // 0 = even, 1 = odd
int main() {
	scanf("%d%d", &n, &m);
	if (n == 1) { printf("0\n"); exit(0); }
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d%d", &a[2*i], &b[2*i], &l[2*i], &r[2*i]);
		r[2*i]--;
		a[2*i+1] = b[2*i];
		b[2*i+1] = a[2*i];
		l[2*i+1] = l[2*i];
		r[2*i+1] = r[2*i];
		adj[a[2*i]][0].push_back(2*i);
		adj[a[2*i]][1].push_back(2*i);
		adj[b[2*i]][0].push_back(2*i+1);
		adj[b[2*i]][1].push_back(2*i+1);
	}
	// sort edges by decreasing l[i]
	for (int i = 1; i <= n; i++) {
		auto comp = [](int x, int y) {
			return l[x] > l[y];
		};
		sort(adj[i][0].begin(), adj[i][0].end(), comp);
		sort(adj[i][1].begin(), adj[i][1].end(), comp);
	}
	// do the "dijkstra's"
	priority_queue<array<int, 3>, vector<array<int, 3> >, greater<array<int, 3> > > pq;
	// we can reach all edges leaving 1 with l[i] = 0 (even edges only)
	while (adj[1][0].size() && !l[adj[1][0].back()]) {
		pq.push({0, adj[1][0].back(), 0});
		adj[1][0].pop_back();
	}
	while (pq.size()) {
		int len = pq.top()[0];
		int e = pq.top()[1];
		int parity = pq.top()[2];
		pq.pop();
		if (b[e] == n) {
			printf("%d\n", len+1);
			exit(0);
		}
		int latestPossibleTime = r[e] - ((r[e] % 2) != parity);
		// consider all edges we can reach from here
		while (adj[b[e]][!parity].size() && l[adj[b[e]][!parity].back()] <= latestPossibleTime+1) {
			int newE = adj[b[e]][!parity].back();
			int reachTime = l[newE];
			if (reachTime % 2 == parity) reachTime++;
			reachTime = max(reachTime, len+1);
			if (reachTime <= r[newE]) {
				pq.push({reachTime, newE, !parity});
			}

			adj[b[e]][!parity].pop_back();
		}
	}
	printf("-1\n");
}