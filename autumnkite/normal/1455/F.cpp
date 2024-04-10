#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::string s;
	std::cin >> s;
	std::vector<std::string> f(n + 1);
	f[0] = "";
	auto nxt = [&](char c) -> char {
		return (c - 'a' + 1) % m + 'a';
	};
	auto prv = [&](char c) -> char {
		return (c - 'a' + m - 1) % m + 'a';
	};
	auto upd = [&](std::string &a, std::string b) {
		if ((int)b.size() > 4) {
			b = b.substr((int)b.size() - 4, 4);
		}
		if (a.empty()) {
			a = b;
		} else {
			a = std::min(a, b);
		}
	};
	for (int i = 0; i < n; ++i) {
		upd(f[i + 1], f[i] + std::min({s[i], prv(s[i]), nxt(s[i])}));
		if (i > 0) {
			std::string t = f[i];
			t.back() = s[i];
			t += f[i].back();
			upd(f[i + 1], t);
		}
		if (i + 1 < n) {
			upd(f[i + 2], f[i] + std::min({s[i + 1], prv(s[i + 1]), nxt(s[i + 1])}) + s[i]);
			if (i > 0) {
				std::string t = f[i];
				t.back() = s[i + 1];
				t += f[i].back();
				t += s[i];
				upd(f[i + 2], t);
			}
		}
		if (i >= 4) {
			std::cout << f[i][0];
		}
	}
	std::cout << f[n] << "\n";
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