#include <bits/stdc++.h>

using namespace std;

const int MX = 100000;

long long a[MX];

int main() {
	int n, m;
	ignore = scanf("%d %d", &n, &m);
	for (int i = 0, u, v, d; i < m; i++) {
		ignore = scanf("%d %d %d", &u, &v, &d);
		a[u - 1] += d;
		a[v - 1] -= d;
	}
	
	vector<int> pos, neg;
	for (int i = 0; i < n; i++) (a[i] < 0 ? neg : pos).push_back(i);
	
	vector<tuple<int, int, long long>> ans;
	for (size_t i = 0, j = 0; i < pos.size() && j < neg.size();) {
		int x = pos[i];
		int y = neg[j];
		if (a[x] == 0) i++;
		else if (a[y] == 0) j++;
		else {
			long long d = min(a[x], -1 * a[y]);
			ans.emplace_back(x, y, d);
			a[x] -= d;
			a[y] += d;
		}
	}
	
	printf("%zu\n", ans.size());
	for (auto p : ans) {
		int u, v;
		long long d;
		tie(u, v, d) = p;
		printf("%d %d %lld\n", u + 1, v + 1, d);
	}
	
	return 0;
}