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
int discrete(T* a, int* b, int n) {
    vector<T> v(a + 1, a + n + 1);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i <= n; i++) b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	return v.size();
}

mt19937 rng (time(NULL));

int randint(int l, int r) {
	return rng() % (r - l + 1) + l;
}

const int bzmax = 28;

int n;
vector<int> a, b[2];

pii calc(const vector<int>& x, const vector<int>& y, int msk) {
	int n = x.size(), m = y.size();
	int py = m - 1;
	pii rt (0, 0);
	for (auto e : x) {
		while (~py && ((e & msk) + (y[py] & msk)) > msk)
			py--;
		rt.fi += py + 1;
		rt.sc += m - py - 1;
	} 
	return rt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	a.resize(n);
	for (auto& x : a) {
		cin >> x;
	}
	int ans = 0;
	for (int i = 0; i < bzmax; i++) {
		b[0].clear();
		b[1].clear();
		for (auto x : a) {
			b[(x >> i) & 1].pb(x);
		}
		int msk = (1 << i) - 1;
		int cnt = 0;
		cnt += calc(b[0], b[1], msk).fi;
		cnt += calc(b[1], b[0], msk).fi;
		cnt += calc(b[0], b[0], msk).sc;
		cnt += calc(b[1], b[1], msk).sc;
		for (auto x : a) {
			if (((x + x) >> i) & 1) {
				cnt--;
			}
		}
		assert(!(cnt & 1));
		cnt = (cnt >> 1) & 1;
		if (cnt)
			ans |= (1 << i);
		a.clear();
		for (auto x : b[0])
			a.pb(x);
		for (auto x : b[1])
			a.pb(x);
	}
	cout << ans << '\n';
	return 0;
}