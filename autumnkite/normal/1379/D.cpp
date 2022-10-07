#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, h, m, k;
	std::cin >> n >> h >> m >> k;
	m /= 2, --k;
	std::map<int, std::vector<int>> mp;
	for (int i = 0; i < n; ++i) {
		int h, x;
		std::cin >> h >> x;
		x %= m;
		mp[x].push_back(i);
		mp[x + m].push_back(i);
	}

	int ans = n, t = 0, now = 0;
	auto l = mp.begin(), r = mp.end();
	for (auto i = mp.begin(), j = mp.begin(); i != mp.end(); ++i) {
		while (j != i && i->first - j->first > k) {
			now -= j->second.size();
			++j;
		}
		if (i->first >= k && now < ans) {
			ans = now;
			t = i->first % m;
			l = j, r = i;
		}
		now += i->second.size();
	}
	std::cout << ans << " " << t << "\n";
	for (auto i = l; i != r; ++i) {
		for (int x : i->second) {
			std::cout << x + 1 << " ";
		}
	}
	std::cout << "\n";
}