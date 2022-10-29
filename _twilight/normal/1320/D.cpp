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

template <int Mod, typename T = char>
class StringHash {
	public:
		int base;
		vector<int> pw;
		vector<int> hs;

		StringHash() {	}
		StringHash(const T* s, int n) : base(rng() % 10000 * 2 + 233) {
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
		int query(int l, int r, T addition) {
			return (query(l, r) * 1ll * base + addition) % Mod;
		}
};

const int N = 2e5 + 5;

int n, m, q;
char s[N], t[N];
int pre[N], suf[N], pos[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> (s + 1);
	pre[1] = 1;
	for (int i = 2; i <= n; i++) {
		pre[i] = (s[i] == s[i - 1]) ? (pre[i - 1]) : i;
	}
	suf[n] = n;
	for (int i = n - 1; i; i--) {
		suf[i] = (s[i] == s[i + 1]) ? (suf[i + 1]) : i;
	}
	for (int i = 1; i <= n; i++) {
		if (s[i] == '0') {
			t[++m] = '0';
		} else if (i == pre[i] && ((suf[i] - pre[i] + 1) & 1)) {
			t[++m] = '1';
		}
		pos[i] = m;
	}
	cin >> q;
	StringHash<998244353> hs1 (t, m);
	StringHash<1000000009> hs2 (t, m);
	while (q--) {
		int l1, l2, len;
		cin >> l1 >> l2 >> len;
		int r1 = l1 + len - 1;
		int r2 = l2 + len - 1;
		if (suf[l1] >= r1 || suf[l2] >= r2) {
			if (suf[l1] < r1 || suf[l2] < r2) {
				puts("No");
			} else {
				puts(s[l1] == s[l2] ? "Yes" : "No");
			}
		} else {
			l1 = (s[l1] == '1') ? suf[l1] + 1 : l1;
			l2 = (s[l2] == '1') ? suf[l2] + 1 : l2;
			int nr1 = (s[r1] == '1') ? (pre[r1] - 1) : r1;
			int nr2 = (s[r2] == '1') ? (pre[r2] - 1) : r2;
			int v11 = ((r1 - nr1) & 1) ? (hs1.query(pos[l1], pos[nr1], '1')) : (hs1.query(pos[l1], pos[nr1]));
			int v12 = ((r1 - nr1) & 1) ? (hs2.query(pos[l1], pos[nr1], '1')) : (hs2.query(pos[l1], pos[nr1]));
			int v21 = ((r2 - nr2) & 1) ? (hs1.query(pos[l2], pos[nr2], '1')) : (hs1.query(pos[l2], pos[nr2]));
			int v22 = ((r2 - nr2) & 1) ? (hs2.query(pos[l2], pos[nr2], '1')) : (hs2.query(pos[l2], pos[nr2]));
			puts((v11 == v21 && v12 == v22) ? ("Yes") : ("No"));
		}
	}
	return 0;
}