#include <bits/stdc++.h>
using namespace std;
int n, dist[2005][2005];
void Query(int u) {
	printf("? %d\n", u);
	fflush(stdout);
	for (int i = 1; i <= n; i++) scanf("%d", &dist[u][i]);
}
set<pair<int, int> > st;
int main() {
	scanf("%d", &n);
	Query(1);
	int cnt[2] = {0, 0}, ty;
	for (int i = 1; i <= n; i++) cnt[dist[1][i] % 2]++;
	if (cnt[0] <= cnt[1]) ty = 0;
	else ty = 1;
	for (int i = 1; i <= n; i++) if (dist[1][i] % 2 == ty) {
		if (i != 1) Query(i);
		for (int j = 1; j <= n; j++) if (dist[i][j] == 1) {
			st.emplace(min(i, j), max(i, j));
		}
	}
	printf("!\n");
	for (auto &P : st) printf("%d %d\n", P.first, P.second);
	fflush(stdout);
	return 0;
}