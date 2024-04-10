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
//#define int long long
#define ll long long
int MOD = 1000000007;
struct VEB_BASE {
	static const unsigned INVALID = ~0;

	unsigned mi, ma;

	VEB_BASE() : mi(INVALID), ma(0) { }

	inline unsigned min() const { return mi; }

	inline unsigned max() const { return mi <= ma ? ma : INVALID; }

	inline bool empty() const { return ma < mi; }
};

// van Emde Boas Tree 2P-bit (upper P-bit and lower P-bit, 0 ~ 2^(2P)-1);
template<const unsigned P> struct VEB_NODE : VEB_BASE {
	typedef VEB_NODE<(P >> 1)> Child;

	int ch_len;
	Child aux, *ch;

	VEB_NODE() : VEB_BASE(), ch_len(0), aux(), ch(NULL) { }

	VEB_NODE(int n_) : VEB_BASE(), ch_len(0), aux(), ch(NULL) {
		int r = n_ & ((1u << P) - 1u);
		ch_len = (n_ >> P) + (bool)r;
		ch = new Child[ch_len];
		if (r) {
			for (int i = 0; i < ch_len - 1; i++) ch[i] = Child(1u << P);
			ch[ch_len - 1] = Child(r);
		}
		else {
			for (int i = 0; i < ch_len; i++) ch[i] = Child(1u << P);
		}
		aux = Child(ch_len);
	}

	unsigned next(unsigned u) const {
		if (ma <= u) return INVALID;
		if (u < mi) return mi;
		unsigned hi = u >> P, lo = u & ((1u << P) - 1u);
		if (lo < ch[hi].ma) return (hi << P) | ch[hi].next(lo);
		hi = aux.next(hi);
		return (hi << P) | ch[hi].mi;
	}

	unsigned prev(unsigned u) const {
		if (u <= mi) return INVALID;
		if (ma < u) return ma;
		unsigned hi = u >> P, lo = u & ((1 << P) - 1u);
		if (ch[hi].mi < lo) return (hi << P) | ch[hi].prev(lo);
		hi = aux.prev(hi);
		return hi == INVALID ? mi : (hi << P) | ch[hi].ma;
	}

	bool find(unsigned u) const {
		return !empty() && (u == min() || ch[u >> P].find(u & ((1u << P) - 1u)));
	}

	bool insert(unsigned u) {
		if (empty()) {
			mi = ma = u;
			return true;
		}
		if (u < mi) swap(mi, u);
		if (mi < u) {
			unsigned hi = u >> P, lo = u & ((1u << P) - 1u);
			if (ma < u) ma = u;
			if (ch[hi].empty()) aux.insert(hi);
			return ch[hi].insert(lo);
		}
		return false;
	}

	bool erase(unsigned u) {
		if (empty()) {
			return false;
		}
		else if (mi == u) {
			if (ma == u) {
				mi = INVALID; ma = 0;
				return true;
			}
			else {
				mi = u = (aux.mi << P) | ch[aux.mi].mi;
			}
		}
		if (ch[u >> P].erase(u & ((1u << P) - 1u))) {
			if (ch[u >> P].empty()) aux.erase(u >> P);
			if (ma == u) {
				if (aux.empty()) ma = mi;
				else ma = (aux.ma << P) | ch[aux.ma].ma;
			}
			return true;
		}
		else {
			return false;
		}
	}

	void clear() {
		if (ch) {
			for (int i = 0; i < ch_len; i++) ch[i].clear();
			aux.clear();
			delete[] ch; ch = NULL;
		}
	}
};

// vEB 6-bit (0 ~ 63);
template<> struct VEB_NODE<3> : VEB_BASE {
	unsigned long long mask;

	VEB_NODE() : VEB_BASE(), mask(0) { }

	VEB_NODE(int n_) : VEB_BASE(), mask(0) { }

	static inline unsigned ctz(unsigned long long u) {
#ifdef __GNUC__
		return __builtin_ctzll(u);
#else
		//	When __builtin_ctzll is not defined;
		unsigned n = 0;
		if ((u & 0x00000000FFFFFFFFULL) == 0) { u >>= 32; n += 32; }
		if ((u & 0x000000000000FFFFULL) == 0) { u >>= 16; n += 16; }
		if ((u & 0x00000000000000FFULL) == 0) { u >>= 8; n += 8; }
		if ((u & 0x000000000000000FULL) == 0) { u >>= 4; n += 4; }
		static const unsigned ctz_4bit[16] = { 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, };
		return n + ctz_4bit[u & 0xFULL]; // if u == 0: return 64;
#endif
	}

	static inline unsigned lg(unsigned long long u) {
#ifdef __GNUC__
		return __lg(u);
#else
		//	When __builtin_clzll and __lg are not defined;
		unsigned n = 0;
		if (u & 0xFFFFFFFF00000000ULL) { u >>= 32; n += 32; }
		if (u & 0x00000000FFFF0000ULL) { u >>= 16; n += 16; }
		if (u & 0x000000000000FF00ULL) { u >>= 8; n += 8; }
		if (u & 0x00000000000000F0ULL) { u >>= 4; n += 4; }
		static const unsigned lg_4bit[16] = { 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, };
		return n + lg_4bit[u]; // if u == 0: return 0;
#endif
	}

	unsigned next(unsigned u) const {
		if (ma <= u) return INVALID; // empty or ma <= u;
		if (u < mi) return mi;
		return ctz(mask & ~((1ULL << (u + 1)) - 1));
	}

	unsigned prev(unsigned u) const {
		if (u <= mi) return INVALID; // empty or u <= mi;
		if (ma < u) return ma;
		unsigned long long k = mask & ((1ULL << u) - 1);
		return k ? lg(k) : mi;
	}

	bool find(unsigned u) const {
		return !empty() && (min() == u || (mask & (1ULL << u)));
	}

	bool insert(unsigned u) {
		if (empty()) {
			mi = ma = u;
			return true;
		}
		if (u < mi) swap(mi, u);
		if (mi < u) {
			if (ma < u) ma = u;
			if (mask & (1ULL << u)) return false;
			mask |= 1ULL << u;
			return true;
		}
		return false;
	}

	bool erase(unsigned u) {
		if (mi == u) {
			if (ma == u) {
				mi = INVALID; ma = 0;
				return true;
			}
			mi = ctz(mask); mask &= ~(1ULL << mi);
			return true;
		}
		else if (u == ma) {
			mask &= ~(1ULL << u);
			if (mask) ma = lg(mask);
			else ma = mi;
			return true;
		}
		else if (mi < u) { // if mi < u < ma;
			if (mask & (1ULL << u)) {
				mask &= ~(1ULL << u);
				return true;
			}
		}
		return false;
	}

	void clear() { // has nothing to clear;
	}
};

// vEB 24-bit;
typedef VEB_NODE<12> VEB;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// VEB
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	//N = 100000; Q = 100;
	vector<int> A(N);
	vector<int> B(N - 1);
	vector<ll> res(Q);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		//A[i] = i;
	}
	for (int i = 0; i < N - 1; i++) {
		B[i] = abs(A[i + 1] - A[i]);
	}
	vector<int> idx(N - 1);
	{
		vector<pair<int, int> > vp;
		for (int i = 0; i < N - 1; i++) {
			vp.emplace_back(B[i], i + 1);
		}
		sort(vp.rbegin(), vp.rend());
		for (int i = 0; i < N - 1; i++) {
			idx[i] = vp[i].second;
		}
	}

	int l, r;

	for (int i = 0; i < Q; i++) {
		cin >> l >> r;

		//l = 1; r = N;
		VEB st(N + 1);

		st.insert(l - 1);
		//cerr << "ok" <<endl;
		st.insert(r);
		//cerr << "ok"<<endl;
		res[i] = 0;
		int L, R;
		for (int j = 0; j < N - 1; j++) {
			if (idx[j] >= l && idx[j] < r) {

				L = idx[j] - st.prev(idx[j]);

				R = st.next(idx[j]) - idx[j];

				st.insert(idx[j]);

				//cerr << B[idx[j]] <<" " << L << " " << R << endl;
				res[i] += (ll)B[idx[j] - 1] * L * R;
			}
		}

	}
	for (int i = 0; i < Q; i++) {
		cout << res[i] << endl;
	}
}