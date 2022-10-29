#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

#define pii pair<int, int>
#define pdi pair<double, int>

const int N = 1e5 + 5;

int K, n, m;
vector<pdi> ans;
vector<pii> add[N];
int a[N], h[N], id[N], op[N];

int main() {
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		h[i] = a[i], id[i] = 0;
	}
	for (int i = 1, op, x, y; i <= m; i++) {
		scanf("%d%d%d", &op, &x, &y);
		::op[i] = op;
		if (op == 1) {
			if (y >= h[x]) {
				h[x] = y;
				id[x] = i;
			}
		} else if (op == 2) {
			add[x].emplace_back(y, i);
		} else if (op == 3) {
			ans.emplace_back(y, i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (id[i])
			add[i].emplace_back(h[i] - a[i], id[i]);
		sort(add[i].begin(), add[i].end(), greater<pii>());
		ll s = a[i];
		for (auto e : add[i]) {
			ans.emplace_back((s + e.first) * 1.0 / s, e.second);
			s += e.first;
		}
	}
	sort(ans.begin(), ans.end(), greater<pdi>());
	ans.resize(min(K, (signed) ans.size()));
	printf("%d\n", (signed) ans.size());
	for (auto e : ans)
		if (op[e.second] == 1)
			printf("%d ", e.second);
	for (auto e : ans)
		if (op[e.second] == 2)
			printf("%d ", e.second);
	for (auto e : ans)
		if (op[e.second] == 3)
			printf("%d ", e.second);
	return 0;
}