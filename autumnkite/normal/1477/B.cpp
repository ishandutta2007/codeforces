#include <bits/stdc++.h>

const int N = 200005;

int n, q;
char a[N], b[N];

struct Query {
	int l, r;
} Q[N];

void solve() {
	std::cin >> n >> q;
	std::cin >> (a + 1);
	std::cin >> (b + 1);
	for (int i = 1; i <= q; ++i) {
		std::cin >> Q[i].l >> Q[i].r;
	}
	std::map<int, int> S;
	for (int i = 1; i <= n; ++i) {
		S[i] = b[i] - '0';
	}
	for (int i = q; i; --i) {
		int l = Q[i].l, r = Q[i].r;
		auto it = S.lower_bound(l);
		auto ed = S.upper_bound(r);
		int tmp = it->second;
		int lst = l - 1;
		int sum = 0;
		while (it != ed) {
			sum += (it->first - lst) * it->second;
			lst = it->first;
			auto It = it;
			++it;
			S.erase(It);
		}
		sum += (r - lst) * it->second;
		if (l > 1 && !S.count(l - 1)) {
			S[l - 1] = tmp;
		}
		if (2 * sum == r - l + 1) {
			std::cout << "NO\n";
			return;
		}
		S[r] = 2 * sum < r - l + 1 ? 0 : 1;
	}
	for (int i = 1; i <= n; ++i) {
		auto it = S.lower_bound(i);
		if (a[i] - '0' != it->second) {
			std::cout << "NO\n";
			return;
		}
	}
	std::cout << "YES\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}