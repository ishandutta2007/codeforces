#include <bits/stdc++.h>

const int N = 1005;

int n, p[N], vis[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> p[i];
	}
	for (int x = 1; x <= n; ++x) {
		for (int i = 1; i <= n; ++i) {
			vis[i] = 0;
		}
		int i = x;
		while (!vis[i]) {
			vis[i] = 1;
			i = p[i];
		}
		std::cout << i << " \n"[i == n];
	}
}