#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, d[N];
vector<int> G[N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) G[i].clear(), d[i] = 0;
		for (int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
		}
		vector<int> vec;
		for (int i = 1; i <= n; i++) {
			if (d[i] == 2) vec.push_back(i);
			for (int v : G[i]) {
				d[v] = max(d[v], (d[i] + 1) % 3);
			}
		}
		printf("%d\n", (int)vec.size());
		for (int v : vec) printf("%d ", v);
		puts("");
	}
	return 0;
}