#include <bits/stdc++.h>

int n;
int a[200005];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	std::priority_queue<int, std::vector<int>, std::greater<int>> Q;
	std::vector<int> ans;
	for (int i = 1; i <= 2 * n; ++i) {
		char op;
		std::cin >> op;
		if (op == '-') {
			std::cin >> a[i];
		} else {
			a[i] = -1;
		}
	}
	for (int i = 2 * n; i; --i) {
		if (a[i] == -1) {
			if (Q.empty()) {
				std::cout << "NO" << std::endl;
				return 0;
			}
			ans.push_back(Q.top());
			Q.pop();
		} else {
			if (!Q.empty() && a[i] > Q.top()) {
				std::cout << "NO" << std::endl;
				return 0;
			}
			Q.push(a[i]);
		}
	}
	std::reverse(ans.begin(), ans.end());
	std::cout << "YES" << std::endl;
	for (int v : ans) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}