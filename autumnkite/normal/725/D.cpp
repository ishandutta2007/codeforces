#include <bits/stdc++.h>

const int N = 300005;

int n;

struct Node {
	long long t, w;

	bool operator < (const Node &rhs) const {
		return t > rhs.t;
	}
} c, a[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	--n;
	std::cin >> c.t >> c.w;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i].t >> a[i].w;
	}
	std::sort(a + 1, a + 1 + n);
	int ans = n, p = 1;
	std::priority_queue<long long, std::vector<long long>, std::greater<long long>> Q;
	while (c.t >= 0) {
		while (p <= n && a[p].t > c.t) {
			Q.push(a[p].w + 1 - a[p].t);
			++p;
		}
		ans = std::min(ans, (int)Q.size());
		if (Q.empty()) {
			break;
		}
		c.t -= Q.top();
		Q.pop();
	}
	std::cout << ans + 1 << std::endl;
}