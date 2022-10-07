#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	if (n == 1) {
		std::cout << "a\n";
		return;
	}
	std::string s;
	for (int i = 0; i < n / 2; ++i) {
		s += 'a';
	}
	s += 'b';
	for (int i = 0; i < n / 2 - 1; ++i) {
		s += 'a';
	}
	if (n & 1) {
		s += 'c';
	}
	std::cout << s << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}