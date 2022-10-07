#include <bits/stdc++.h>

const int N = 100005;

int n;
char a[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	std::cin >> (a + 1);
	int x = 0, y = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 'R') {
			++x;
		} else {
			++y;
		}
		if (x == y && i < n && a[i + 1] == a[i]) {
			++ans;
		}
	}
	std::cout << ans << "\n";
}