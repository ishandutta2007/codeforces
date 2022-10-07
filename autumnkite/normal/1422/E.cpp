#include <bits/stdc++.h>

class state {
	std::string pre, suf;
	int len;
	bool less;
	
	int get_first() const {
		if (pre.empty()) {
			return suf[0];
		} else {
			return pre[0];
		}
	}

public:
	state() : len(0), less(false) {}

	state insert(char c) const {
		state res;
		if (len) {
			char tmp = get_first();
			res.less = c == tmp ? less : (c < tmp);
		}
		if ((int)suf.size() < 2) {
			res.suf = c + suf;
		} else {
			res.suf = suf;
			res.pre = c + pre;
			if ((int)res.pre.size() > 8) {
				res.pre.resize(8);
			}
		}
		res.len = len + 1;
		return res;
	}

	state trans(char c) const {
		if (!len) {
			return *this;
		}
		char tmp = get_first();
		if (c < tmp || (c == tmp && less)) {
			return this->insert(c).insert(c);
		} else {
			return *this;
		}
	}

	void print() const {
		if (!len) {
			std::cout << 0 << "\n";
			return;
		}
		std::cout << len << " ";
		if (len <= 10) {
			std::cout << pre << suf << "\n";
		} else {
			std::cout << pre.substr(0, 5) << "..." << suf << "\n";
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::string s;
	std::cin >> s;
	int n = s.size();

	std::vector<state> f(n + 1);
	for (int i = n - 1; i >= 0; --i) {
		if (i + 1 < n && s[i] == s[i + 1]) {
			f[i] = f[i + 2].trans(s[i]);
		} else {
			f[i] = f[i + 1].insert(s[i]);
		}
	}
	for (int i = 0; i < n; ++i) {
		f[i].print();
	}
}