#include <bits/stdc++.h>

void solve() {
	std::vector<std::pair<int, int>> p(4);
	for (int i = 0; i < 4; ++i) {
		std::cin >> p[i].first >> p[i].second;
	}
	std::sort(p.begin(), p.end());
	
	auto calc = [&](int lx1, int rx1, int lx2, int rx2, int ly1, int ry1, int ly2, int ry2) {
		if (ly1 > ry1) {
			std::swap(ly1, ry1);
		}
		if (ly2 > ry2) {
			std::swap(ly2, ry2);
		}
		int len = std::max(0, std::max(lx2 - rx1, ly2 - ry1));
		long long ans = 0ll + rx1 - lx1 + rx2 - lx2 + ry1 - ly1 + ry2 - ly2;
		if (len > rx2 - lx1) {
			ans += 2ll * (len - (rx2 - lx1));
		}
		if (len > ry2 - ly1) {
			ans += 2ll * (len - (ry2 - ly1));
		}
		return ans;
	};

	long long s1 = calc(p[0].first, p[1].first, 
	                    p[2].first, p[3].first, 
	                    std::min(p[0].second, p[1].second), std::min(p[2].second, p[3].second),
	                    std::max(p[0].second, p[1].second), std::max(p[2].second, p[3].second));
	long long s2 = calc(p[0].first, p[2].first, 
	                    p[1].first, p[3].first, 
	                    std::min(p[0].second, p[2].second), std::min(p[1].second, p[3].second),
	                    std::max(p[0].second, p[2].second), std::max(p[1].second, p[3].second));
	std::cout << std::min(s1, s2) << "\n";
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