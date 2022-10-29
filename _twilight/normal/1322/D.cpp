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

const int N = 2005, S = 1 << 11, S2 = S << 1;

int n, m;
int l[N], s[N], c[N << 1];
int f[S], g[N][S2], cto[S];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> l[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= n + m; i++) {
		cin >> c[i];
	}
	for (int i = n + m; i; i--)
		c[i] += c[i + 1];
	for (int i = 1; i < S; i++) {
		if (i & 1) {
			cto[i] = cto[i >> 1] + 1;
		} else {
			cto[i] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < S2; j++) {
			g[i][j] = -inf;
		}
	}
	for (int i = 0; i <= 11; i++)
		g[1][1 << i] = 0;
	int ans = 0;
	for (int i = n; i; i--) {
		int t = l[i];
		for (int s = 0; s < S; s++) {
			f[s] = -inf;
		}
		for (int d = 0; d <= 11 && t > d; d++) {
			int ol = t - d;
			for (int s = 0; s < (S >> d); s++) {
				int& v = g[ol][s | (S >> d)];
				if (v ^ -inf) {
					vmax(f[s + 1], v + c[t] - c[t + cto[s] + 1] - ::s[i]);
				}
			}	
		}
		for (int j = t - 12; j > 0; j--) {
			vmax(f[1], g[j][1] + c[t] - c[t + 1] - ::s[i]);
		}
		for (int s = 1; s < S; s++) {
			vmax(g[t][s | S], f[s]);
			vmax(ans, f[s]);
		}
		for (int s = S2 - 1; s > 1; s--) {
			vmax(g[t][s >> 1], g[t][s]);
		}
	}
	cout << ans << '\n';
	return 0;
}