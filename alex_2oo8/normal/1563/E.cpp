#include <bits/stdc++.h>

using namespace std;

const int MX = 1000;

int a[MX], b[MX], parent[MX];
long long dist[MX];
vector<int> G[MX];
bool good[MX];

bool check(int n, long long val) {
	fill(good, good + n, false);
	good[0] = true;
	
	while (true) {
		fill(parent, parent + n, -1);
		
		vector<int> queue;
		for (int i = 0; i < n; i++) {
			if (good[i]) {
				queue.push_back(i);
				dist[i] = val;
			}
		}
		
		set<int> found;
		
		auto addPath = [&](int v) {
			while (good[v] == false) {
				found.insert(v);
				v = parent[v];
			}
		};
		
		for (size_t i = 0; i < queue.size(); i++) {
			int v = queue[i];
			
			for (int u : G[v]) {
				if (parent[v] == u) continue;
				if (good[u]) {
					if (good[v] == false) {
						addPath(v);
						goto DONE;
					}
					else {
						continue;
					}
				}
				
				if (dist[v] <= a[u]) continue;
				
				if (parent[u] != -1) {
					addPath(v);
					addPath(u);
					goto DONE;
				}
				
				parent[u] = v;
				dist[u] = dist[v] + b[u];
				queue.push_back(u);
			}
		}

DONE:	if (found.empty()) break;

		for (int v : found) {
			good[v] = true;
			val += b[v];
		}
	}
	
	return count(good, good + n, true) == n;
}

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int n, m;
		ignore = scanf("%d %d", &n, &m);
		for (int i = 1; i < n; i++) ignore = scanf("%d", a + i);
		for (int i = 1; i < n; i++) ignore = scanf("%d", b + i);
		
		for (int i = 0; i < n; i++) G[i].clear();
		
		for (int i = 0, u, v; i < m; i++) {
			ignore = scanf("%d %d", &u, &v);
			u--;
			v--;
			
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		int ans = 0;
		for (int p = 1 << 30; p > 0; p /= 2) {
			if (check(n, ans + p) == false) {
				ans += p;
			}
		}
		
		printf("%d\n", ans + 1);
	}
	
	return 0;
}