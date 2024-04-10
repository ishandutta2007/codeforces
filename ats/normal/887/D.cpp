#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
template <typename monoid>
struct segment_tree {
	using M = monoid;
	using T = typename M::value_type;

	std::size_t sz;
	std::vector<T> x;

	segment_tree(std::size_t n = 0) {
		sz = 1;
		while (sz < n) sz *= 2;
		x.assign(sz * 2, M::id());
		initialize();
	}

	template <typename iterator>
	segment_tree(iterator first, iterator last) {
		sz = 1;
		std::size_t n = std::distance(first, last);
		while (sz < n) sz *= 2;
		x.assign(sz * 2, M::id());
		std::copy(first, last, x.begin() + sz);
		initialize();
	}

	void fill(const T& val) {
		std::fill(x.begin() + sz, x.end(), val);
		initialize();
	}

	void initialize() {
		for (int i = (int)sz - 1; i >= 1; --i) {
			x[i] = M::op(x[i * 2 + 0], x[i * 2 + 1]);
		}
	}

	T accumulate(std::size_t l, std::size_t r) const {
		T al = M::id(), ar = M::id();
		for (l += sz, r += sz; l < r; l /= 2, r /= 2) {
			if (l & 1) al = M::op(al, x[l++]);
			if (r & 1) ar = M::op(x[--r], ar);
		}
		return M::op(al, ar);
	}

	void update(std::size_t i, const T &val) {
		x[i += sz] = val;
		while (i > 1) {
			x[i / 2] = M::op(x[i], x[i ^ 1]);
			i /= 2;
		}
	}

	T operator[](std::size_t i) const { return x[sz + i]; }
};

template <typename T>
struct min_monoid {
	using value_type = T;
	static constexpr T id() { return std::numeric_limits<T>::max(); }
	static T op(const T &a, const T &b) { return std::min(a, b); }
};

template <typename T>
struct max_monoid {
	using value_type = T;
	static constexpr value_type id() { return std::numeric_limits<value_type>::min(); }
	static value_type op(const value_type &a, const value_type &b) { return std::max(a, b); }
};

template <typename T>
struct sum_monoid {
	using value_type = T;
	static constexpr value_type id() { return 0; }
	static value_type op(const value_type &a, const value_type &b) { return a + b; }
};

template <typename value_type>
using rmq = segment_tree<min_monoid<value_type>>;

template <typename value_type>
using rsq = segment_tree<sum_monoid<value_type>>;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, a, b, c, d, st, len;
	cin >> N >> a >> b >> c >> d >> st >> len;
	vector<int> t(N);
	vector<int> p(N);
	int res = (int)1 << 60;
	rmq<int> sg1(N + 1);
	rmq<int> sg2(N + 1);
	vector<int> kh;
	vector<int> sum1(N + 1, 0);
	vector<int> sum2(N + 1, 0);
	kh.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> t[i] >> p[i];
		if (t[i] - len + 1 > 0) {
			kh.push_back(t[i] - len + 1);
		}
		kh.push_back(t[i] + 1);
		if (p[i] == 1) {
			sum1[i + 1] = a;
			sum2[i + 1] = c;
		}
		else if (p[i] == 0) {
			sum1[i + 1] = -b;
			sum2[i + 1] = -d;

		}
	}
	for (int i = 0; i < N; i++) {
		sum1[i + 1] += sum1[i];
		sum2[i + 1] += sum2[i];
	}
	for (int i = 0; i <= N; i++) {
		sg1.update(i, sum1[i]);
		sg2.update(i, sum2[i]);
	}
	sort(kh.begin(), kh.end());
	int l = 0;
	int r = 0;
	int rt = st;
	int trt;
	bool f = true;
	int mn;
	for (int i = 0; i < kh.size(); i++) {
	
		while (t[r] < kh[i] + len && r < N) {

			r++;
		}
		while (t[l] < kh[i] && l < N) {
			if (p[l] == 1) {
				rt += a;
			}
			else {
				rt -= b;
			}
			if (rt < 0) {
				f = false;
				break;
			}
			l++;
		}
		if (!f) {
			break;
		}
		//cerr << kh[i] << " " << l << " " << r <<endl;
		
		mn = sum2[l] - sg2.accumulate(l, r + 1);
		//cerr << mn << endl;
		if (rt - mn < 0)continue;
		trt = rt + sum2[r] - sum2[l];
		//cerr << "trt ="<< trt << endl;
		mn = sum1[r] - sg1.accumulate(r, N + 1);
		//if (trt - mn < 0)continue;
		res = kh[i];
		break;
	}
	if (res == (int)1 << 60) {
		res = -1;
	}
	cout << res << endl;
}