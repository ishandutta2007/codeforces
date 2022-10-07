#include <bits/stdc++.h>

const int P = 1000000007;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> Q;
	for (int i = 0; i < n; ++i) {
		std::string op;
		std::cin >> op;
		int x;
		std::cin >> x;
		if (op == "ADD") {
			Q.emplace_back(0, x);
		} else {
			Q.emplace_back(1, x);
		}
	}

	std::priority_queue<int> A;
	std::priority_queue<int, std::vector<int>, std::greater<int>> B;
	A.push(0), B.push(1e9);
	int lst = -1;
	int ans = 1;
	for (int i = 0; i < n; ++i) {
		if (Q[i].first == 1) {
			int v = Q[i].second;
			if (v < A.top() || v > B.top()) {
				std::cout << 0 << "\n";
				return 0;
			} else if (v == A.top()) {
				A.pop();
			} else if (v == B.top()) {
				B.pop();
			} else {
				ans = 2 * ans % P;
			}
			for (int j = lst + 1; j < i; ++j) {
				if (Q[j].second < v) {
					A.push(Q[j].second);
				} else if (Q[j].second > v) {
					B.push(Q[j].second);
				}
			}
			lst = i;
		}
	}
	int cnt = 0;
	for (int i = lst + 1; i < n; ++i) {
		if (Q[i].second > A.top() && Q[i].second < B.top()) {
			++cnt;
		}
	}
	std::cout << 1ll * ans * (cnt + 1) % P << "\n";
}