#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, cnt, lab[N];
set<int> G[N];
inline void add_edge(int u, int v) {
	if (u > v) swap(u, v);
	lab[u]++;
	if (lab[u] == 1) cnt--;
}
inline void del_edge(int u, int v) {
	if (u > v) swap(u, v);
	lab[u]--;
	if (!lab[u]) cnt++;
}
int main() {
	scanf("%d%d", &n, &m);
	cnt = n;
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v);
		} else if (op == 2) {
			int u, v;
			scanf("%d%d", &u, &v);
			del_edge(u, v);
		} else {
			printf("%d\n", cnt);
		}
	}
	return 0;
}