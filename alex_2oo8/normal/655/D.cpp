#include<bits/stdc++.h>

using namespace std;

const int MX = 100000;

set<int> e[MX], nodes[MX];
int indeg[MX], rem[MX];

int main() {
	int n, m, ans = 0;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		nodes[0].insert(i);
	}
	
	while (n > 0 && ans < m) {
		ans++;
		
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		
		if (rem[u] == 1) continue;
		
		e[u].insert(v);
		nodes[indeg[v]].erase(v);
		indeg[v]++;
		nodes[indeg[v]].insert(v);
		
		while (nodes[0].size() == 1) {
			n -= 1;
			
			int u = *nodes[0].begin();
			
			rem[u] = 1;
			nodes[0].erase(u);
			
			for (int v : e[u]) {
				nodes[indeg[v]].erase(v);
				indeg[v]--;
				nodes[indeg[v]].insert(v);
			}
		}
	}
	
	if (n != 0) ans = -1;
	
	printf("%d\n", ans);
	
	return 0;
}