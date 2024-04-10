#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

int ask(vector<int> a, vector<int> b) {
	if (!a.size() || !b.size())
		return 0;
	printf("%d %d", (signed) a.size(), (signed) b.size());
	for (auto x : a)
		printf(" %d", x + 1);
	for (auto x : b)
		printf(" %d", x + 1);
	putchar('\n');
	fflush(stdout);
	int dist = 0;
	scanf("%d", &dist);
	return dist;
}

int T, n;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int ans = 0;
		for (int i = 0; i < 9; i++) {
			vector<int> a, b;
			for (int j = 0; j < n; j++) {
				if ((j >> i) & 1) {
					a.push_back(j);
				} else {
					b.push_back(j);	
				}
			}
			ans = max(ans, ask(a, b));
		}
		printf("-1 %d\n", ans);
		fflush(stdout);
	}
	return 0;
}