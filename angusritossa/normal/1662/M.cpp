#include <bits/stdc++.h>
using namespace std;
int best[11], t;
int main() {
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		int n, m;
		scanf("%d%d", &n, &m);
		int r = 0, w = 0;
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			r = max(r, x);
			w = max(w, y);
		}
		r = max(r, n-w);
		if (r+w == n) {
			for (int i = 0; i < r; i++) printf("R");
			for (int i = 0; i < w; i++) printf("W");
			printf("\n");
		} else {
			printf("IMPOSSIBLE\n");
		}
	}
}