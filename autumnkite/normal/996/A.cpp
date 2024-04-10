#include <bits/stdc++.h>

const int c[] = {1, 5, 10, 20, 100};

int n;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cin >> n;
	
	int ans = 0;
	for (int i = 4; ~i; --i) {
		while (n >= c[i]) {
			n -= c[i];
			++ans;
		}
	}
	std::cout << ans << "\n";
}