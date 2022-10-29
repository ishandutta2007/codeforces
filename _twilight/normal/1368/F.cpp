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

int n, R = -1;
vector<int> his;
bitset<1005> on, need;

void light_on(vector<int> p) {
	cout << (signed) p.size();
	for (auto x : p) {
		cout << ' ' << x + 1;
		on.set(x);
	}
	cout << endl;
	int s;
	cin >> s;
	--s;
	for (int i = 0; i < (signed) p.size(); i++) {
		on.reset(s);
		if (++s == n) {
			s = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	if (n <= 3) {
		cout << '0' << '\n';
		return 0;
	}
	int k = 1;
	for (int i = 2; i <= n; i++) {
		int c = n - (n + i - 1) / i - (i - 1);
		if (c > R) {
			R = c;
			k = i;
		}
	}
	for (int i = 0; i < n / k; i++) {
		for (int j = 0; j < k - 1; j++) {
			need.set(i * k + j);
		}
	}
	for (int i = n / k * k; i < n - 1; i++) {
		need.set(i);
	}
	while ((signed) on.count() < R) {
		vector<int> p;
		for (int i = 0; i < n && (signed) p.size() < k; i++) {
			if (need.test(i) && !on.test(i)) {
				p.push_back(i);
			}
		}
		light_on(p);
	}
	cout << '0' << '\n';
	return 0;
}