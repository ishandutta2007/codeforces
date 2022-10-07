#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> v(n);
	std::vector<int> la(n), ra(n);
	std::vector<int> lb(n), rb(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i];
		std::cin >> la[i] >> ra[i];
		std::cin >> lb[i] >> rb[i];
	}

	auto init = [&](std::vector<int> v, std::vector<int> l, std::vector<int> r) {
		int n = v.size();
		std::vector<int> s1(n);
		for (int i = 0; i < n; ++i) {
			if (l[i] <= v[i] && v[i] <= r[i]) {
				s1[i] = (i ? s1[i - 1] : 0) + 1;
			} else {
				s1[i] = 0;
			}
		}
		std::vector<std::pair<int, int>> sl, sr;
		sl.emplace_back(m + 1, n);
		sr.emplace_back(-1, n);
		std::vector<int> s2(n);
		for (int i = n - 1; i >= 0; --i) {
			while (!sl.empty() && sl.back().first < l[i]) {
				sl.pop_back();
			}
			sl.emplace_back(l[i], i);
			while (!sr.empty() && sr.back().first > r[i]) {
				sr.pop_back();
			}
			sr.emplace_back(r[i], i);
			int tmp = i ? v[i - 1] : 0;
			auto tl = std::lower_bound(sl.begin(), sl.end(), tmp, [&](std::pair<int, int> a, int b) {
				return a.first > b;
			});
			auto tr = std::lower_bound(sr.begin(), sr.end(), tmp, [&](std::pair<int, int> a, int b) {
				return a.first < b;
			});
			s2[i] = std::min((--tl)->second, (--tr)->second);
		}
		return std::make_pair(s1, s2);
	};

	auto [a1, a2] = init(v, la, ra);
	auto [b1, b2] = init(v, lb, rb);

	std::vector<bool> fa(n + 1), fb(n + 1);
	std::vector<int> ga(n + 1), gb(n + 1);
	std::vector<std::vector<int>> pa(n + 1), pb(n + 1);
	std::set<int> sa, sb;
	fa[0] = fb[0] = true;
	for (int i = 0; i < n; ++i) {
		if (fa[i]) {
			sa.insert(i);
			pa[a2[i]].push_back(i);
		}
		if (fb[i]) {
			sb.insert(i);
			pb[b2[i]].push_back(i);
		}
		for (int x : pa[i]) {
			sa.erase(x);
		}
		for (int x : pb[i]) {
			sb.erase(x);
		}
		auto ta = sa.upper_bound(i);
		if (ta != sa.begin()) {
			--ta;
			if (*ta >= i - b1[i] + 1) {
				fb[i + 1] = true;
				gb[i + 1] = *ta;
			}
		}
		auto tb = sb.upper_bound(i);
		if (tb != sb.begin()) {
			--tb;
			if (*tb >= i - a1[i] + 1) {
				fa[i + 1] = true;
				ga[i + 1] = *tb;
			}
		}
	}

	if (fa[n] || fb[n]) {
		std::cout << "Yes\n";
		int now = n;
		int t = fa[n] ? 0 : 1;
		std::vector<int> ans(n);
		while (now) {
			for (int i = t == 0 ? ga[now] : gb[now]; i < now; ++i) {
				ans[i] = t;
			}
			now = t == 0 ? ga[now] : gb[now];
			t ^= 1;
		}
		for (int x : ans) {
			std::cout << x << " ";
		}
		std::cout << "\n";
	} else {
		std::cout << "No\n";
	}
}