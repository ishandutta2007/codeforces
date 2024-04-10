#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

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

#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define ll long long
#define ull unsigned long long

const int inf = (signed) (~0u >> 2);
const ll llf = (signed ll) (~0ull >> 2);

#define pb push_back
#define eb emplace_back
#define fi first
#define sc second

template <typename T>
int vsize(vector<T>& x) {
	return (signed) x.size(); 
}

template <typename T>
void discrete(T* a, int* b, int n) {
	vector<T> v(a + 1, a + n + 1);
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
}

mt19937 rng (time(NULL) ^ 148257);

#define ll long long
#define ull unsigned long long

template <typename T>
T add(T a, T b, T m) {
	return ((a += b) >= m) ? (a - m) : (a);
}

template <typename T>
void pcopy(T* pst, const T* ped, T* pval) {
	for ( ; pst != ped; *(pst++) = *(pval++));
}

ll mul(ll a, ll b, ll m) {
	//    return (__int128)a * b % m;
	ll rt = 0, pa = a;
	for ( ; b; b >>= 1, pa = add(pa, pa, m))
		if (b & 1)
			rt = add(rt, pa, m);
	return rt;
}

ll qpow(ll a, ll p, ll m) {
	ll rt = 1, pa = a;
	for ( ; p; p >>= 1, pa = mul(pa, pa, m))
		if (p & 1)
			rt = mul(rt, pa, m);
	return rt;
}

ll gcd(ll a, ll b) {
	return (b) ? (gcd(b, a % b)) : (a);
}

ll randLL() {
	static ull seed = 998244353, msk = (1ull << 61) - 1;
	return (signed ll) ((seed = seed * seed + seed * 3 + 233) & msk);
}

boolean miller_rabin(ll n) {
	static int T = 25;
	static const int pri[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	if (!(n & 1))
		return n == 2;
	if (n < 1000) {
		for (int p = 2; p * p <= n; p++)
			if (!(n % p))
				return false;
		return true;
	}
	for (int i = 0; i < 10; i++) {
		if (n == pri[i]) {
			return true;
		} else if (!(n % pri[i])) {
			return false;
		}
	}
	ll d = n - 1;
	int s = 0;
	while (!(d & 1))
		s++, d >>= 1;
	for (int t = 0; t < T; t++) {
		ll b = randLL() % n;
		if (!b)
			continue;
		ll tmp = qpow(b, d, n);
		if (tmp == 1 || tmp == n - 1)
			continue;
		for (int i = 0; i < s; i++) {
			tmp = mul(tmp, tmp, n);
			if (tmp == n - 1)
				goto nextTurn;
			if (tmp == 1 || tmp == 0)
				return false;
		}
		if (tmp != 1)
			return false;
nextTurn:;
	}
	return true;
}

ll pollard_rho(ll x) {
	//	cerr << x << '\n';
	ll a, b, c, g;
	if (!(x & 1))
		return 2;
	while (true) {
		b = a = randLL() % x;
		c = randLL() % 127 % x;
		do {
			a = add(mul(a, a, x), c, x);
			b = add(mul(b, b, x), c, x);
			b = add(mul(b, b, x), c, x);
			g = gcd(b - a, x);
			(g < 0) ? (g = -g) : (0);
			if (g == x)
				break;
			if (g > 1)
				return g;
		} while (a != b);
	}
	assert(false);
	return 0;
}

void get_primary_factors(ll x, vector<ll>& rt) {
	if (x == 1) {
		return;
	}
	if (miller_rabin(x)) {
		rt.push_back(x);
		return;
	}
	ll a = pollard_rho(x);
	get_primary_factors(a, rt);
	get_primary_factors(x / a, rt);
}

void get_primary_factor(vector<ll>& vec) {
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
}

/// Template ends

void check(ll p, int& ans, vector<ll>& a) {
	ll tmp = 0;
	for (auto x : a) {
		ll r = x % p;
		if (x == r) {
			tmp += p - x;
		} else {
			tmp += min(p - r, r);
		}
		if (tmp > ans)
			break;
	}
	if (tmp < ans)
		ans = tmp;
}

int main() {
	srand(((unsigned) time (NULL)) ^ 233);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<ll> a (n, 0);
	for (auto& x : a)
		cin >> x;
	int ans = n + 1;
	random_shuffle(a.begin(), a.end());
	for (int i = 2; i <= 100; i++) {
		if (miller_rabin(i)) {
			check(i, ans, a);
		}
	}
	while (clock() * 1.0 / CLOCKS_PER_SEC < 2.3) {
		int pos = rng() % n;
		vector<ll> tmp;
		for (int d = -1; d < 2; d++) {
			if (a[pos] + d < 1)
				continue;
			get_primary_factors(a[pos] + d, tmp);
			get_primary_factor(tmp);
			for (auto p : tmp)
				if (p > 100)
					check(p, ans, a);
		}
	}
	cout << ans << '\n';
	return 0;
}