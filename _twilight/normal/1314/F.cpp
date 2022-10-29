#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

// missed charactors / ?

template <typename T>
boolean vmin(T& a, T b) {
	return (a > b) ? (a = b, true) : (false);
}
template <typename T>
boolean vmax(T& a, T b) {
	return (a < b) ? (a = b, true) : (false);
}

template <typename T>
T smax(T x) {
	return x;
}
template <typename T, typename ...K>
T smax(T a, const K &...args) {
	return max(a, smax(args...));
}

template <typename T>
T smin(T x) {
	return x;
}
template <typename T, typename ...K>
T smin(T a, const K &...args) {
	return min(a, smin(args...));
}

// debugging lib

#define VN(x) #x
#define Vmsg(x) VN(x) << " = " << (x)
#define printv(x) cerr << VN(x) << " = " << (x);
#define debug(...) fprintf(stderr, __VA_ARGS__);

template <typename A, typename B>
ostream& operator << (ostream& os, const pair<A, B>& z) {
	os << "(" << z.first << ", " << z.second << ')';
	return os;
}
template <typename T>
ostream& operator << (ostream& os, const vector<T>& a) {
	boolean isfirst = true;
	os << "{";
	for (auto z : a) {
		if (!isfirst) {
			os << ", ";
		}
		os << z;
		isfirst = false;
	}
	os << '}';
	return os;
}

#define ull unsigned long long
#define ll long long

ull nim_mul(ull a, ull b, int dep = 1 << 6) {
	static const int tabsz = 1 << 8;
	static ull table[tabsz][tabsz];
	if (a > b)
		swap(a, b);
	if (a <= 1)
		return (a) ? (b) : 0;
	if (b < tabsz && table[a][b])
		return table[a][b];
	while (b < (1ull << (dep >> 1)))
		dep >>= 1;
	int half = dep >> 1;
	ull M = 1ull << half;
	ull aH = a >> half, aL = a & (M - 1);
	ull bH = b >> half, bL = b & (M - 1);
	ull t0 = nim_mul(aL, bL, half);
	ull t1 = nim_mul(aL ^ aH, bL ^ bH, half);
	ull t2 = nim_mul(aH, bH, half);
	ull ret = nim_mul(t2, M >> 1, half) ^ ((t1 ^ t0) << half) ^ t0;
	(b < tabsz) && (table[a][b] = ret, 0);
	return ret;
}

void exgcd(ll a, ll b, ll& x, ll& y) {
	if (!b) {
		x = 1, y = 0;
	} else {
		exgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
}
ll inv(ll a, ll n) {
	ll x, y;
	exgcd(a, n, x, y);
	return (x < 0) ? (x + n) : x;
}

const ull F = ~0ull;
vector<ull> pF {3, 5, 17, 257, 641, 65537, 6700417};

ull add(ull a, ull b) {
	ull s = a + b;
	s = s + (s < a);
	return (s == F) ? (0) : (s);
}
ull mul(ll a, ll b) {
	ll rt = 0;
	for ( ; b; b >>= 1, a = add(a, a)) {
		if (b & 1) {
			rt = add(rt, a);
		}
	}
	return rt;
}

ull crt(vector<int> as) {
	ull ret = 0;
	int n = as.size();
	for (int i = 0; i < n; i++)
		ret = add(ret, mul(as[i] * (F / pF[i]), inv(F / pF[i] % pF[i], pF[i])));
	return ret;
}

ull nim_pow(ull a, ull p) {
	ull rt = 1;
	for ( ; p; p >>= 1, a = nim_mul(a, a)) {
		if (p & 1) {
			rt = nim_mul(rt, a);
		}
	}
	return rt;
}

int work(ull a, ull b, int p) {
	int C = sqrt(p + 0.5);
	map<ull, int> G;
	ull pb = b;
	for (int i = 1; i <= C; i++) {
		pb = nim_mul(pb, a);
		G[pb] = i;
	}	
	ull pac = nim_pow(a, C), pa = 1;
	for (int L = 0; L < p; ) {
		pa = nim_mul(pa, pac);
		L += C;
		if (G.count(pa)) {
			return L - G[pa];
		}
	}
	return -1;
}
int solve(ull a, ull b, int p) {
	return work(nim_pow(a, F / p), nim_pow(b, F / p), p);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	ull a, b;
	cin >> T;
	while (T--) {
		cin >> a >> b;
		vector<int> ra;
		boolean suc = true;
		for (auto p : pF) {
			int x = solve(a, b, p);
			if (x < 0) {
				suc = false;
				break;
			}
			ra.push_back(x);
		}
		if (suc) {
			ull t;
			cout << (t = crt(ra)) << '\n';
//			cerr << nim_pow(a, t) << '\n'; 
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}