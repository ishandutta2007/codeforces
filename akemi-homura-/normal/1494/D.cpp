#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, a[N][N], c[N], bb[N], fa[N], ccc;
int Find(int x) {
	return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
void Union(int x, int y) {
	x = Find(x), y = Find(y);
	if (x != y) ccc--, fa[x] = y;
}
vector<pair<int, int> > vec;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++) c[i] = a[i][i], fa[i] = i, bb[i] = i;
	ccc = n;
	m = n;
	while (ccc > 1) {
		int mn = 1145141;
		for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) if (Find(i) != Find(j)) {
			mn = min(mn, a[i][j]);
		}
		for (int i = 1; i <= n; i++) {
			int flag = 0;
			for (int j = i + 1; j <= n; j++) if (Find(i) != Find(j)) {
				if (a[i][j] == mn) { flag = 1; break; }
			}
			if (flag) {
				c[++m] = mn;
				vec.emplace_back(bb[Find(i)], m);
				for (int j = i + 1; j <= n; j++) if (Find(i) != Find(j)) {
					if (a[i][j] == mn) {
						Union(i, j);
						vec.emplace_back(bb[Find(j)], m);
					}
				}
				bb[Find(i)] = m;
			}
		}
	}
	printf("%d\n", m);
	for (int i = 1; i <= m; i++) printf("%d%c", c[i], " \n"[i == m]);
	printf("%d\n", m);
	for (auto P : vec) printf("%d %d\n", P.first, P.second);
	return 0;
}