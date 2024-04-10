#include <bits/stdc++.h>

struct node {
	long long x, y;

	node() : x(0), y(0) {}
	node(long long _x, long long _y) : x(_x), y(_y) {}
};

bool check(node a, node b, node c) {
	return (__int128_t)(a.y - b.y) * (c.x - b.x) > (__int128_t)(b.y - c.y) * (b.x - a.x);
}

bool check(node a, node b, long long k) {
	return a.y - b.y > (__int128_t)k * (b.x - a.x);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	long long n;
	int q;
	std::cin >> n >> q;
	std::vector<node> p;
	p.emplace_back(0, 0);
	long long ssum = 0, bsum = 0;
	while (q--) {
		int op;
		std::cin >> op;
		if (op == 1) {
			long long k;
			std::cin >> k;
			p.clear();
			p.emplace_back(0, -bsum);
			n += k;
		} else if (op == 2) {
			long long k;
			std::cin >> k;
			node tmp(n, -ssum * n - bsum);
			while ((int)p.size() > 1 && !check(p[p.size() - 2], p[p.size() - 1], tmp)) {
				p.pop_back();
			}
			p.push_back(tmp);
			n += k;
		} else {
			long long b, s;
			std::cin >> b >> s;
			bsum += b;
			ssum += s;
		}
		while ((int)p.size() > 1 && !check(p[p.size() - 2], p[p.size() - 1], ssum)) {
			p.pop_back();
		}
		std::cout << p.back().x + 1 << " " << p.back().x * ssum + p.back().y + bsum << "\n";
	}
}