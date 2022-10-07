#include <bits/stdc++.h>

std::vector<int> EXKMP(std::string s) {
	std::vector<int> z(s.size());
	z[0] = s.size();
	for (int i = 1, l = 0, r = 0; i < (int)s.size(); ++i) {
		z[i] = std::max(std::min(z[i - l], r - i), 0);
		while (i + z[i] < (int)s.size() && s[z[i]] == s[i + z[i]]) {
			++z[i];
		}
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
	return z;
}

template<typename Tp> 
class binary_indexed_tree {
	int n;
	std::vector<Tp> c;

public:
	binary_indexed_tree(int _n) : n(_n), c(n + 1) {}

	void add(int x, Tp v) {
		for (++x; x <= n; x += x & -x) {
			c[x] += v;
		}
	}

	Tp query(int x) {
		Tp s = Tp();
		for (; x; x ^= x & -x) {
			s += c[x];
		}
		return s;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::string a, b;
	std::cin >> a >> b;
	std::reverse(b.begin(), b.end());
	std::string s, t;
	std::cin >> s;
	t = std::string(s.rbegin(), s.rend());

	std::vector<int> za = EXKMP(s + '#' + a);
	std::vector<int> zb = EXKMP(t + '#' + b);
	za.erase(za.begin(), za.begin() + m + 1);
	zb.erase(zb.begin(), zb.begin() + m + 1);
	std::reverse(zb.begin(), zb.end());

	for (int &x : za) {
		x = std::min(x, m - 1);
	}
	for (int &x : zb) {
		x = std::min(x, m - 1);
	}

	binary_indexed_tree<int> T(m);
	binary_indexed_tree<long long> Ti(m);
	long long ans = 0;
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < n && j - i + 1 < m) {
			T.add(zb[j], 1);
			Ti.add(zb[j], zb[j]);
			++j;
		}
		ans += Ti.query(m) - Ti.query(m - za[i]);
		ans += 1ll * (T.query(m) - T.query(m - za[i])) * (za[i] - m + 1);
		T.add(zb[i], -1);
		Ti.add(zb[i], -zb[i]);
	}
	std::cout << ans << "\n";
}