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

int m;

template <int Mod, typename T = char>
class StringHash {
	public:
		int base;
		vector<int> pw;
		vector<int> hs;

		StringHash() {	}
		StringHash(const T* s, int n, int base) {
			pw.resize(n + 1);
			hs.resize(n + 1);
			pw[0] = 1;
			for (int i = 1; i <= n; i++)
				pw[i] = pw[i - 1] * 1ll * base % Mod;
			hs[0] = 0;
			for (int i = 1; i <= n; i++)
				hs[i] = (1ll * hs[i - 1] * base + s[i]) % Mod;
		}

		int query(int l, int r) {
			int ret = (hs[r] - 1ll * pw[r - l + 1] * hs[l - 1]) % Mod;
			return (ret < 0) ? (ret + Mod) : (ret);
		}
};

const int N = 1e6 + 5;
char s[N], _s[N];

void solve() {
	cin >> (s + 1);
	int n = strlen(s + 1);
	copy(s + 1, s + n + 1, _s + 1);
	reverse(_s + 1, _s + n + 1);

	int L = 1, R = n;
	while (L <= R && s[L] == s[R])
		L++, R--;
	if (L > R) {
		cout << (s + 1) << '\n';
		return;
	}
	int b1 = rng() % 10000 * 2 + 233, b2 = rng() % 10000 * 2 + 233;
	StringHash<993244853> hs1 (s, n, b1), _hs1 (_s, n, b1);
	StringHash<1000000009> hs2 (s, n, b2), _hs2 (_s, n, b2);

	auto is_pal =[&] (int l, int r) {
		return hs1.query(l, r) == _hs1.query(n - r + 1, n + 1 - l) && hs2.query(l, r) == _hs2.query(n - r + 1, n + 1 - l);	
	};
	string s1, s2;
	for (int i = R; i >= L; i--) {
		if (is_pal(L, i)) {
			for (int j = 1; j <= i; j++)
				s1 += s[j];
			for (int j = R + 1; j <= n; j++)
				s1 += s[j];
			break;
		}
	}
	for (int i = L; i <= R; i++) {
		if (is_pal(i, R)) {
			for (int j = 1; j < L; j++)
				s2 += s[j];
			for (int j = i; j <= n; j++)
				s2 += s[j];
			break;
		}
	}
	if (s1.length() > s2.length()) {
		cout << s1 << '\n';
	} else {
		cout << s2 << '\n';
	}
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