#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <array>


int n, q, m;
int a[200001];

int t[200000];
int l[200000];
int r[200000];

struct Elt {
	int id, i;
	bool operator<(const Elt &o) const {
		return id < o.id;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n >> q >> m;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	for (int i = 0; i < q; ++i)
		std::cin >> t[i] >> l[i] >> r[i];

	std::vector<Elt> ve(m);
	for (int i = 0; i < m; ++i) {
		ve[i].id = i;
		std::cin >> ve[i].i;
	}
	for (--q; q >= 0; --q) {
		for (auto &&e : ve) {
			if (l[q] >= r[q]) continue;
			if (e.i >= l[q] && e.i <= r[q]) {
				if (t[q] == 2) { // rev
					e.i = l[q] + r[q] - e.i;
				}
				else { // rot
					if (--e.i < l[q])
						e.i = r[q];
				}
			}
		}
	}

	std::sort(ve.begin(), ve.end());
	std::cout << a[ve[0].i];
	for(int i = 1; i < ve.size() ;++i)
		std::cout << ' ' << a[ve[i].i];
	return 0;
}