#include <bits/stdc++.h>

int query(std::vector<int> a, std::vector<int> b) {
	std::cout << "? " << a.size() << " " << b.size() << "\n";
	for (int x : a) {
		std::cout << x + 1 << " ";
	}
	std::cout << "\n";
	for (int x : b) {
		std::cout << x + 1 << " ";
	}
	std::cout << std::endl;
	std::string s;
	std::cin >> s;
	if (s == "FIRST") {
		return 1;
	} else if (s == "SECOND") {
		return -1;
	} else {
		assert(s == "EQUAL");
		return 0;
	}
}

void answer(int x) {
	std::cout << "! " << x + 1 << std::endl;
}

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());
	int id = 0;
	for (int i = 0; i < 20; ++i) {
		int x = rnd() % (n - 1);
		if (x >= id) {
			++x;
		}
		if (query({x}, {id}) == 1) {
			id = x;
		}
	}
	if (id != 0 && query({id}, {0}) == 1) {
		answer(0);
		return;
	}

	auto get = [&](int l, int c) {
		std::vector<int> res;
		for (int i = l; i < l + c; ++i) {
			res.push_back(i);
		}
		return res;
	};
	int t = 0;
	while ((1 << (t + 1)) <= n) {
		if (query(get(0, 1 << t), get(1 << t, 1 << t)) == 0) {
			++t;
		} else {
			break;
		}
	}
	int now = 1 << t;
	for (int i = t - 1; i >= 0; --i) {
		if (now + (1 << i) < n && query(get(0, 1 << i), get(now, 1 << i)) == 0) {
			now += 1 << i;
		}
	}
	answer(now);
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