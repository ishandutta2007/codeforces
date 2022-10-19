#include <bits/stdc++.h>
using namespace std;
pair<int, int> people[310*310];
pair<int, int> at[310*310];
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n*m; i++) {
			scanf("%d", &people[i].first);
			people[i].second = i;
		}
		sort(people, people+n*m);
		for (int i = 0; i < n*m; i++) at[i] = people[i];

		// reverse
		int pre = 0;
		for (int i = 0; i < n*m; i++) {
			if (i%m == m-1 || at[i].first != at[i+1].first) {
				reverse(at+pre, at+i+1);
				pre = i+1;
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			int start = i*m;
			for (int j = start; j < start+m; j++) {
				for (int k = start; k < j; k++) {
					if (at[k].second < at[j].second) ans++;
				}
			}
		}

		printf("%d\n", ans);
	}
}