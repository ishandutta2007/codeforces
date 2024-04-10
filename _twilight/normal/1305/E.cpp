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

mt19937 rng (time(NULL));

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int oldm = m;
	vector<int> a;
	int t = 0, curmx = 1e8;
	for (int i = 1; i <= n; i++) {
		if (!m) {
			a.pb(curmx);
			curmx += 1e4 + 3;
		} else {
			int b = a.size();
			if (m >= (b >> 1)) {
				a.pb(b + 1);
				m -= (b >> 1);
			} else {
				auto count = [&] (int x) {
					int rt = 0;
					for (int j = 1; j <= b; j++) {
						int t = x - j;
						if (t <= b && t > j) {
							rt ++;
						}
					}
					return rt;
				};
				int j, x;
				for (j = i + 1; m < (x = count(j)); j++);
				assert(x == m);
				m = 0;
				a.pb(j);
			}
		}
	}
	if (m) {
		cout << "-1";
		return 0;
	}
	assert(vsize(a) == n);
	for (auto x : a)
		cout << x << " ";
	return 0;
	t = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			auto it = lower_bound(a.begin(), a.end(), a[i] + a[j]);
			if (it != a.end() && *it == a[i] + a[j]) {
				t++;
			}
		}
	}
	assert(t == oldm);
	return 0;
}