#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::string s;
	std::cin >> s;
	int n = s.size();
	std::vector<std::pair<int, int>> seg;
	int p = 0;
	while (p < n) {
		while (p < n && s[p] == '_') {
			++p;
		}
		if (p == n) {
			break;
		}
		int r = p;
		while (r < n && s[r] == '#') {
			++r;
		}
		seg.emplace_back(p, r);
		p = r;
	}

	if (seg.empty()) {
		std::cout << 0 << "\n";
		return 0;
	}

	auto check = [&](int d) {
		auto chk = [&](int len) {
			return len == 0 || (len > 1 && d >= (len & 1) + 1);
		};
		if (!chk(seg.front().first - d)) {
			return false;
		}
		if (!chk(n - seg.back().second - d)) {
			return false;
		}
		for (int i = 1; i < (int)seg.size(); ++i) {
			if (!chk(seg[i].first - seg[i - 1].second - d - 1)) {
				return false;
			}
		}
		return true;
	};

	int d = 0;
	while (d <= 4 && !check(d)) {
		++d;
	}
	if (d == 5) {
		std::cout << -1 << "\n";
		return 0;
	}

	std::vector<int> ans;
	auto work = [&](int len) {
		if (len == 0) {
			return;
		}
		while (len - 2 > 1) {
			ans.push_back(1);
			len -= 2;
		}
		ans.push_back(len - 1);
	};
	work(seg[0].first - d);
	ans.push_back(seg[0].second - seg[0].first + d);
	for (int i = 1; i < (int)seg.size(); ++i) {
		work(seg[i].first - seg[i - 1].second - d - 1);
		ans.push_back(seg[i].second - seg[i].first + d);
	}
	work(n - seg.back().second - d);

	std::cout << ans.size() << "\n";
	for (int x : ans) {
		std::cout << x << " ";
	}
	std::cout << "\n";
}