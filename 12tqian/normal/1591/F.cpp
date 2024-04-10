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

template <class T> struct AffineSegmentTree {
	int sz;
	std::vector<T> sum, mult, add, size;

	void push(int ind, int L, int R) { // modify values for current node
		sum[ind] *= mult[ind]; sum[ind] += size[ind] * add[ind];
		if (L != R) {
			mult[2 * ind] *= mult[ind]; mult[2 * ind + 1] *= mult[ind];
			add[2 * ind] *= mult[ind]; add[2 * ind] += add[ind];
			add[2 * ind + 1] *= mult[ind]; add[2 * ind + 1] += add[ind];
		}
		add[ind] = 0; mult[ind] = 1;
	}

	void init(vector<int> size_) {
		int n = (int)size_.size();
		sz = 1;
		while (sz < n) sz *= 2;
		mult.assign(2 * sz, 1);
		sum.assign(2 * sz, 0);
		add.assign(2 * sz, 0);
		size.assign(2 * sz, 0);
		for (int i = 0; i < n; ++i) {
			size[i + sz] = size_[i];
		}
		for (int i = sz - 1; i >= 1; --i) {
			pull(i);
		}
	}

	void pull(int ind) {
		sum[ind] = sum[2 * ind] + sum[2 * ind + 1];
		size[ind] = size[2 * ind] + size[2 * ind + 1];
	}

	// t == 0 is add, t == 1 is for multiplying
	void upd(int t, int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += sz;
		push(ind, L, R);
		if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) {
			if(t == 0) add[ind] = inc;  
			else mult[ind] = inc;
			push(ind, L, R); return;
		}
		int M = (L + R) / 2;
		upd(t, lo, hi, inc, 2 * ind, L, M); upd(t, lo, hi, inc, 2 * ind + 1, M + 1, R);
		pull(ind);
	}
	
	T qsum(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += sz;
		push(ind, L, R);
		if (lo > R || L > hi) return 0;
		if (lo <= L && R <= hi) return sum[ind];
		int M = (L + R) / 2;
		return qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);
	}
};

using mi = Mint<998244353, 5>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> vals = a;
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	auto get_pos = [&](int x) {
		return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
	};
	vector<int> sizes;
	for (int i = 0; i < (int)vals.size(); ++i) {
		sizes.push_back(vals[i] - (i ? vals[i - 1] : 0));
	} 
	AffineSegmentTree<mi> seg;
	seg.init(sizes);
	int sz = (int)sizes.size();
	for (int i = 0; i < n; ++i) {
		int pos = get_pos(a[i]);
		if (i == 0) {
			seg.upd(0, 0, pos, 1);
		} else {
			mi sum = seg.qsum(0, sz - 1);
			seg.upd(1, 0, pos, -1);
			seg.upd(0, 0, pos, sum);
			seg.upd(1, pos + 1, sz - 1, 0);
		}
	}
	mi ans = seg.qsum(0, sz - 1);
	cout << ans << '\n';
	return 0;
}