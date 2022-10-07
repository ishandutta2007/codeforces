#include <bits/stdc++.h>

std::vector<std::string> query(int l, int r) {
	if (l >= r) {
		return std::vector<std::string>();
	}
	std::cout << "? " << l + 1 << " " << r << std::endl;
	std::vector<std::string> res((r - l + 1) * (r - l) / 2);
	for (auto &x : res) {
		std::cin >> x;
	}
	return res;
}

std::string solve(int n) {
	auto t1 = query(0, n), t2 = query(1, n);
	std::map<std::string, int> cnt;
	for (auto &x : t1) {
		std::sort(x.begin(), x.end());
		++cnt[x];
	}
	for (auto &x : t2) {
		std::sort(x.begin(), x.end());
		--cnt[x];
	}
	std::vector<std::string> t;
	for (const auto &p : cnt) {
		if (p.second) {
			t.push_back(p.first);
		}
	}
	std::sort(t.begin(), t.end(), [&](const std::string &a, const std::string &b) {
		return a.size() < b.size();
	});

	auto get = [&](const std::string &a, const std::string &b) {
		std::vector<int> cnt(26);
		for (char x : a) {
			++cnt[x - 'a'];
		}
		for (char x : b) {
			--cnt[x - 'a'];
		}
		return (char)(std::find(cnt.begin(), cnt.end(), 1) - cnt.begin() + 'a');
	};

	std::string ans(n, 'a');
	ans[0] = t[0][0];
	for (int i = 1; i < n; ++i) {
		ans[i] = get(t[i], t[i - 1]);
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	int B = (n + 1) / 2;

	auto ans = solve(B);
	
	auto t = query(0, n);
	std::vector<std::vector<int>> f(n + 1, std::vector<int>(26));
	for (const auto &x : t) {
		for (char c : x) {
			++f[x.size()][c - 'a'];
		}
	}
	for (int i = n - B - 1; i >= 0; --i) {
		std::vector<int> cnt(26);
		for (int j = 0; j < 26; ++j) {
			cnt[j] = f[i + 1][j] - f[i][j];
		}
		for (int j = i; j < (int)ans.size(); ++j) {
			--cnt[ans[j] - 'a'];
		}
		ans += (char)(std::find(cnt.begin(), cnt.end(), 1) - cnt.begin() + 'a');
	}
	std::cout << "! " << ans << std::endl;
}