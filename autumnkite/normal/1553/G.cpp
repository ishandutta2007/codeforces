#include <bits/stdc++.h>

class disjoint_set {
public:
	typedef std::size_t size_type;

protected:
	std::vector<size_type> fa;

public:
	disjoint_set(size_type n = 0) : fa(n) {
		std::iota(fa.begin(), fa.end(), 0);
	}

	size_type find(size_type x) {
		return fa[x] == x ? x : (fa[x] = find(fa[x]));
	}

	bool merge(size_type x, size_type y) {
		x = find(x), y = find(y);
		if (x == y) {
			return false;
		}
		fa[y] = x;
		return true;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	int m = *std::max_element(a.begin(), a.end()) + 1;
	std::vector<int> id(m + 1, -1);
	for (int i = 0; i < n; ++i) {
		id[a[i]] = i;
	}

	std::vector<int> minp(m + 1);
	std::iota(minp.begin(), minp.end(), 0);
	for (int i = 2; i <= m; ++i) {
		if (minp[i] == i) {
			for (int j = i + i; j <= m; j += i) {
				minp[j] = std::min(minp[j], i);
			}
		}
	}

	disjoint_set D(n);
	for (int i = 2; i <= m; ++i) {
		if (minp[i] == i) {
			int lst = -1;
			for (int j = i; j <= m; j += i) {
				if (id[j] != -1) {
					if (lst != -1) {
						D.merge(lst, id[j]);
					}
					lst = id[j];
				}
			}
		}
	}
	
	std::vector<int> bel(m + 1, -1);
	for (int i = 0; i < n; ++i) {
		for (int x = a[i]; x != 1; x /= minp[x]) {
			bel[minp[x]] = D.find(i);
		}
	}
	std::vector<std::set<int>> S(n);
	for (int i = 0; i < n; ++i) {
		std::vector<int> tmp;
		tmp.push_back(D.find(i));
		for (int x = a[i] + 1; x != 1; x /= minp[x]) {
			if (bel[minp[x]] != -1) {
				tmp.push_back(bel[minp[x]]);
			}
		}
		tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
		for (int i = 0; i < (int)tmp.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				S[tmp[i]].insert(tmp[j]);
			}
		}
	}

	while (q--) {
		int x, y;
		std::cin >> x >> y;
		--x, --y;
		x = D.find(x), y = D.find(y);
		if (x == y) {
			std::cout << 0 << "\n";
		} else if (S[x].count(y) || S[y].count(x)) {
			std::cout << 1 << "\n";
		} else {
			std::cout << 2 << "\n";
		}
	}
}