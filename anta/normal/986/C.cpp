#include "bits/stdc++.h"
using namespace std;

int main() {
	int n; int m;
	while (~scanf("%d%d", &n, &m)) {
		vector<bool> input(1 << n);
		for (int i = 0; i < m; ++ i) {
			int a;
			scanf("%d", &a);
			input[a] = true;
		}
		vector<bool> vis(2 << n);
		vector<int> que(2 << n, -1);
		int ans = 0;
		for (int s = 0; s < 1 << n; ++ s) if (input[s] && !vis[s]) {
			++ ans;
			int qt = 0;
			auto go = [&](int i) {
				if (!vis[i]) {
					vis[i] = true;
					que[qt ++] = i;
				}
			};
			go(s);
			for (int qh = 0; qh < qt; ++ qh) {
				int i = que[qh];
				if (i < 1 << n) {
					go(i + (1 << n));
				} else {
					for (int k = 0; k < n; ++ k) if(~i >> k & 1)
						go(i | 1 << k);
					if (input[~i & ((1 << n) - 1)])
						go(~i & ((1 << n) - 1));
				}
			}
		}
		printf("%d\n", ans);
	}
}