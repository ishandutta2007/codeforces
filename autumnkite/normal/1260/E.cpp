#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int &x : a) {
		std::cin >> x;
	}
	
	std::priority_queue<int, std::vector<int>, std::greater<int>> Q;
	long long ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == -1) {
			std::cout << ans << "\n";
			return 0;
		}
		Q.push(a[i]);
		if (((i + 1) & i) == 0) {
			ans += Q.top();
			Q.pop();
		}
	}
}