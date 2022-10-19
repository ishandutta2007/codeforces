#include <bits/stdc++.h>
using namespace std;
int people[310], at[310];
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &people[i]);
		}
		// for each position, choose the latest person we can
		int ans = 0;
		fill_n(at, m, -1);
		for (int i = 0; i < m; i++) {
			// pick the smallest person, breaking ties by largest index 
			pair<int, int> mn = { (int)2e9, (int)2e9 };
			for (int j = 0; j < m; j++) {
				if (at[j] == -1) {
					mn = min(mn, { people[j], -j });
				}
			}
			int chosen = -mn.second;
			at[chosen] = i;
			for (int j = 0; j < chosen; j++) {
				if (at[j] != -1) ans++;
			}
		}
		printf("%d\n", ans);
	}
}