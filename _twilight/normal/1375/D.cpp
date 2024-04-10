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


void solve() {
	int n;
	cin >> n;
	vector<int> a (n);
	for (auto& x : a) {
		cin >> x;
	}
	auto get_mex = [&] () {
		vector<bool> vis(n + 3, false);
		for (auto x : a)
			vis[x] = true;
		int rt = 0;
		while (vis[rt])
			rt++;
		return rt;
	};
	auto chk = [&] () {
		for (int i = 0; i < n - 1; i++) {
			if (a[i + 1] < a[i]) {
				return false;
			}
		}
		return true;
	};
	vector<int> p;
	while (!chk()) {
		int x = get_mex();
		if (x == n) {
			int pn = n - 1;
			while (pn >= 0 && (a[pn] == n || a[pn] == pn)) pn--;
			p.push_back(pn);
			a[pn] = n;
		} else {
			p.push_back(x);
			a[x] = x;
		}
	}
	assert((signed) p.size() <= 2 * n);
	cout << p.size() << '\n';
	for (auto x : p)
		cout << x + 1 << " ";
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}