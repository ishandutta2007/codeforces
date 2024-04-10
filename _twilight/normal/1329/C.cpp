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

const int N = 1 << 21;

int h, g, nh;
int a[N], p[N], q[N], d[N];

bool chk(int x) {
	int ls = x << 1;
	int rs = x << 1 | 1;
	if (!a[ls] && !a[rs]) {
		return d[x] > g;
	}
	return a[ls] > a[rs] ? chk(ls) : chk(rs);
}

void f(int x) {
	int ls = x << 1;
	int rs = x << 1 | 1;
	if (!a[ls] && !a[rs]) {
		a[x] = 0;
		return;
	}
	if (a[ls] > a[rs]) {
		p[x] = p[ls];
		q[p[x]] = x;
		a[x] = a[ls];
		f(ls);
	} else {
		p[x] = p[rs];
		q[p[x]] = x;
		a[x] = a[rs];
		f(rs);
	}
}

void solve() {
	cin >> h >> g;
	nh = (1 << h) - 1;
	for (int i = 1; i <= (nh << 1) + 1; i++) {
		a[i] = 0;
		p[i] = q[i] = 0;
		d[i] = d[i >> 1] + 1;
	}
	ll sum = 0;
	for (int i = 1; i <= nh; i++) {
		cin >> a[i];
		sum += a[i];
		p[i] = q[i] = i;
	}
	vector<int> ord (nh);
	for (int i = 1; i <= nh; i++) {
		ord[i - 1] = i;
	}
	sort(ord.begin(), ord.end(), [&] (int x, int y) {	return a[x] > a[y];	});
	vector<int> ans;
	for (auto x : ord) {
		if (chk(q[x])) {
			sum -= a[q[x]];
			f(q[x]);
			ans.pb(q[x]);
		}
	}
	cout << sum << '\n';
	for (auto x : ans) {
		cout << x << " ";
	}
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