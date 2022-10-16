#include <bits/stdc++.h>

using namespace std;

// 5 is a root of both mods
template <int MOD, int RT> struct Mint {
	static const int mod = MOD;
	static constexpr Mint rt() { return RT; } // primitive root for FFT
	static constexpr int md() { return MOD; } // primitive root for FFT
	int v; 
	explicit operator int() const { return v; } // explicit -> don't silently convert to int
	explicit operator bool() const { return v != 0; }
	Mint() { v = 0; }
	Mint(long long _v) { v = int((-MOD <= _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }
	friend bool operator==(const Mint& a, const Mint& b) { return a.v == b.v; }
	friend bool operator!=(const Mint& a, const Mint& b) { return !(a == b); }
	friend bool operator<(const Mint& a, const Mint& b) { return a.v < b.v; }
	friend bool operator>(const Mint& a, const Mint& b) { return a.v > b.v; }
	friend bool operator<=(const Mint& a, const Mint& b) { return a.v <= b.v; }
	friend bool operator>=(const Mint& a, const Mint& b) { return a.v >= b.v; }
	friend std::istream& operator >> (std::istream& in, Mint& a) { 
		long long x; std::cin >> x; a = Mint(x); return in; }
	friend std::ostream& operator << (std::ostream& os, const Mint& a) { return os << a.v; }
	Mint& operator+=(const Mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	Mint& operator-=(const Mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	Mint& operator*=(const Mint& m) { 
		v = (long long)v * m.v % MOD; return *this; }
	Mint& operator/=(const Mint& m) { return (*this) *= inv(m); }
	friend Mint pow(Mint a, long long p) {
		Mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
		return ans; 
	}
	friend Mint inv(const Mint& a) { assert(a.v != 0); return pow(a, MOD - 2); }
	Mint operator-() const { return Mint(-v); }
	Mint& operator++() { return *this += 1; }
	Mint& operator--() { return *this -= 1; }
	friend Mint operator+(Mint a, const Mint& b) { return a += b; }
	friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
	friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
	friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
};

template <class T> struct FenwickTree {
	std::vector<T> fwt;
	int n;

	void init(int n_) {
		n = n_;
		fwt.assign(n, 0);
	}

	void init(std::vector<T>& a) {
		n = (int)a.size();
		fwt.assign(n, 0);
		for (int i = 0; i < (int)a.size(); i++) {
			add(i, a[i]);
		}
	}

	T sum(int r) {
		T ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1) 
			ret += fwt[r];
		return ret;
	}

	T query(int l, int r) {
		return sum(r) - sum(l - 1);
	}
	
	void add(int idx, T delta) {
		for (; idx < n; idx = idx | (idx + 1)) 
			fwt[idx] += delta;
	}
};

template <class T> struct SparseTable {
	std::vector<T> v;
	std::vector<std::vector<int>> jump;

	int level(int x) { return 31 - __builtin_clz(x); }

	int comb(int a, int b) {
		return v[a] == v[b] ? std::min(a, b) : (v[a] > v[b] ? a : b);
	}

	void init(const std::vector<T>& _v) {
		v = _v;
		jump = {std::vector<int>((int)v.size())};
		iota(jump[0].begin(), jump[0].end(), 0);
		for (int j = 1; (1 << j) <= (int)v.size(); j++) {
			jump.push_back(std::vector<int>((int)v.size() - (1 << j) + 1));
			for (int i = 0; i < (int)jump[j].size(); i++) {
				jump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);
			}
		}
	}

	int index(int l, int r) {
		assert(l <= r);
		int d = level(r - l + 1);
		return comb(jump[d][l], jump[d][r - (1 << d) + 1]);
	}

	T query(int l, int r) {
		return v[index(l, r)];
	}
};

using mi = Mint<1000000007, 5>;

template <class T> int get_pos(const vector<T>& v, const T& x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin();
}

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	auto vals = a;
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	for (int i = 0; i < n; ++i) {
		a[i] = get_pos(vals, a[i]);	
	}
	vector<mi> pre(n);
	FenwickTree<mi> fwt;
	fwt.init(n);
	for (int i = 0; i < n; ++i) {
		pre[i] = fwt.query(0, a[i] - 1) + 1;
		fwt.add(a[i], pre[i]);
	}
	vector<mi> suf(n);
	fwt.init(n);
	for (int i = n - 1; i >= 0; --i) {
		suf[i] = fwt.query(a[i] + 1, n - 1) + 1;
		fwt.add(a[i], suf[i]);
	}
	SparseTable<int> st;
	st.init(a);
	vector<int> go(n);
	for (int i = 0; i < n; ++i) {
		int l = i;
		int r = n - 1;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if (st.query(m, n - 1) <= a[i]) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		int idx = n - 1;
		if (st.query(l, n - 1) <= a[i]) {
			idx = l - 1;
		} else if (st.query(r, n - 1) <= a[i]) {
			idx = r - 1;
		}
		go[i] = idx;	
	}
	mi ans = 0;
	fwt.init(n);
	for (int i = n - 1; i >= 0; --i) {
		int to = go[i];
		if (i < to) {
			mi add = suf[i];
			add -= fwt.query(a[i] + 1, a[to] - 1) + 1;
			ans += add * pre[i];
			fwt.add(a[i], suf[i] - add);
		} else {
			fwt.add(a[i], 1);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}