#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	long long T;
	std::cin >> n >> T;
	std::string s;
	std::cin >> s;

	T -= 1ll << (s[n - 1] - 'a');
	T += 1ll << (s[n - 2] - 'a');

	std::vector<long long> v(n - 2);
	for (int i = 0; i < n - 2; ++i) {
		T -= 1ll << (s[i] - 'a');
		v.push_back(1ll << (s[i] - 'a' + 1));
	}
	std::sort(v.begin(), v.end(), std::greater<long long>());

	for (long long x : v) {
		if (T + x <= 0) {
			T += x;
		}
	}
	if (T == 0) {
		std::cout << "Yes\n";
	} else {
		std::cout << "No\n";
	}
}