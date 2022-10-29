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

int na, nb, nc;

ll sqr(ll x) {
	return x * x;
}
ll calc(ll a, ll b, ll c) {
	return sqr(a - b) + sqr(a - c) + sqr(c - b);
}

ll work(vector<int> A, vector<int> B, vector<int> C) {
	auto pb = B.begin(), _pb = B.end();
	auto pc = C.begin(), _pc = C.end();
	ll ret = 4e18;
	for (auto x : A) {
		while (pb != _pb && *pb < x)
			pb++;
		while (pc != _pc && *pc <= x)
			pc++;
		if (pb == _pb) {
			break;
		}
		if (pc != C.begin()) {
			vmin(ret, calc(x, *pb, *(pc - 1)));
		}
	}
	return ret;
}

void solve() {
	cin >> na >> nb >> nc;
	vector<int> A(na), B(nb), C(nc);
	for (auto& x : A) {
		cin >> x;
	}
	for (auto& x : B) {
		cin >> x;
	}
	for (auto& x : C) {
		cin >> x;
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());
	ll ans = 4e18;
	vmin(ans, work(A, B, C));
	vmin(ans, work(A, C, B));
	vmin(ans, work(B, A, C));
	vmin(ans, work(B, C, A));
	vmin(ans, work(C, A, B));
	vmin(ans, work(C, B, A));
	cout << ans << '\n';
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