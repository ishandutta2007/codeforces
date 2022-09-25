#include <bits/stdc++.h>

using namespace std;

const int MX = 200000;

int a[MX], n;
vector<int> G[MX];

int solve(int c) {
	vector<int> deg;
	vector<int> leaves[3];
	
	for (int i = 0; i < n; i++) {
		deg.push_back(G[i].size());
		
		if (deg[i] < 2) leaves[a[i]].push_back(i);
	}
	
	set<int> deleted;
	auto rem = [&](int v) {
		deleted.insert(v);
		
		for (int u : G[v]) {
			if (deleted.count(u) == 1) continue;
			
			deg[u]--;
			if (deg[u] == 1) leaves[a[u]].push_back(u);
		}
	};
	
	int res = 0;
	while (deleted.size() < n) {
		res++;
		
		while (leaves[c].size() + leaves[0].size() > 0) {
			int v;
			if (leaves[c].size() > 0) {
				v = leaves[c].back();
				leaves[c].pop_back();
			}
			else {
				v = leaves[0].back();
				leaves[0].pop_back();
			}
			
			rem(v);
		}
		
		c ^= 3;
	}
	
	return res;
}

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		ignore = scanf("%d", &n);
		
		for (int i = 0; i < n; i++) {
			ignore = scanf("%d", a + i);
			G[i].clear();
		}
		
		for (int i = 1, u, v; i < n; i++) {
			ignore = scanf("%d %d", &u, &v);
			u--; v--;
			G[u].emplace_back(v);
			G[v].emplace_back(u);
		}
		
		int ans = min(solve(1), solve(2));
		printf("%d\n", ans);
	}
	
	return 0;
}