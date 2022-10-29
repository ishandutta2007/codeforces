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

int n;
ll K;
vector<ll> a;
vector<int> b;

ll calc(ll a, ll s) {
	ll l = 1, r = a;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (a - ((3ll * mid - 3) * mid - 1) >= s) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return l - 1;
}

ll check(ll mid) {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		int x = a[i];
		b[i] = calc(x, mid);
		sum += b[i];
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> K;
	a.resize(n);
	b.resize(n);
	for (auto& x : a)
		cin >> x;
	ll l = -4e18, r = 1e9;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid) >= K) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	ll s = check(l - 1);
	for (int i = 0; i < n && s > K; i++) {
		if (b[i] && a[i] - ((3ll * b[i] - 3) * b[i] - 1) == l - 1) {
			s--;
			b[i]--;
		}
	}
	assert(s == K);
	for (auto x : b)
		cout << x << " ";
	cout <<'\n';
	return 0;
}