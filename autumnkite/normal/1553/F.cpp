#include <bits/stdc++.h>

template<typename _Val, typename _VV = std::plus<_Val>>
class binary_indexed_tree {
public:
	typedef std::size_t size_type;

protected:
	size_type n;
	std::vector<_Val> c;
	_VV fun_vv;

public:
	binary_indexed_tree() : binary_indexed_tree(0) {}

	binary_indexed_tree(size_type _n) : n(_n), c(n + 1) {}

	void add(size_type x, _Val v) {
		for (++x; x <= n; x += x & -x) {
			c[x] = fun_vv(c[x], v);
		}
	}

	_Val query(size_type x) {
		_Val s = _Val();
		for (; x; x ^= x & -x) {
			s = fun_vv(s, c[x]);
		}
		return s;
	}
};

template<typename _Val, typename _VV = std::plus<_Val>, typename _Diff = std::minus<_Val>>
class diff_binary_indexed_tree : public binary_indexed_tree<_Val, _VV> {
protected:
	_Diff diff;

public:
	typedef std::size_t size_type;

	diff_binary_indexed_tree() : binary_indexed_tree<_Val, _VV>() {}

	diff_binary_indexed_tree(size_type _n) : binary_indexed_tree<_Val, _VV>(_n) {}

	_Val rquery(size_type l, size_type r) {
		return diff(this->query(r), this->query(l));
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int m = *std::max_element(a.begin(), a.end()) + 1;
	diff_binary_indexed_tree<long long> T1(m), T2(m);
	long long sum = 0;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		ans += 1ll * i * x - T2.query(a[i] + 1);
		ans += sum;
		for (int l = x; l < m; l += x) {
			int r = std::min(l + x, m);
			ans -= l * T1.rquery(l, r);
			T2.add(l, l);
			if (r < m) {
				T2.add(r, -l);
			}
		}
		T1.add(x, 1);
		sum += x;
		std::cout << ans << " ";
	}
	std::cout << "\n";
}