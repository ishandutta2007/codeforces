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

const int bzmax = 18;
const int V = 1 << 18;
const int N = 2e5 + 5;

int n;
int a[N], uf[N];
pii f[V][2], g[N];

int find(int x) {
	return uf[x] == x ? x : (uf[x] = find(uf[x]));
}
boolean unit(int x, int y) {
	x = find(x), y = find(y);
	return (x ^ y) ? (uf[x] = y, true) : false;
}

void _upd(pii* x, pii y) {
	if (y.sc == x->sc) {
		vmax(*x, y);
	} else if (y.fi > x->fi) {
		*(x + 1) = *x;
		*x = y;
	} else {
		vmax(*++x, y);
	}
}
void merge(pii* x, pii* y) {
	_upd(x, *y);
	_upd(x, *(++y));
}
pii query(pii* x, int t) {
	return x->sc == t ? *++x : *x;
}

ll Boruvka() {
	ll ret = 0;
	int cntcomp = ++n;
	for (int i = 1; i <= n; i++)
		uf[i] = i;
	while (cntcomp > 1) {
		for (int i = 0; i < V; i++)
			f[i][0] = f[i][1] = pii(-1, -1);
		for (int i = 1; i <= n; i++)
			_upd(f[a[i]], pii(a[i], find(i)));
		for (int i = 0; i < bzmax; i++) {
			for (int j = 0; j < V; j++) {
				if ((j >> i) & 1) {
					merge(f[j], f[j ^ (1 << i)]);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (find(i) == i) {
				g[i] = pii(-1, -1);
			}
		}
		for (int i = 1; i <= n; i++) {
			auto x = query(f[a[i] ^ (V - 1)], find(i));
			if (x.sc < 0)
				continue;
			x.fi += a[i];
			vmax(g[find(i)], x);
		}
		for (int i = 1; i <= n; i++) {
			if (find(i) == i) {
				assert(g[i].sc > 0);
				if (unit(i, g[i].sc)) {
					ret += g[i].fi;
				}
			}
		}
		cntcomp = 0;
		for (int i = 1; i <= n; i++)
			cntcomp += find(i) == i;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll ans = Boruvka();
	for (int i = 1; i <= n; i++)
		ans -= a[i];
	cout << ans << '\n';
	return 0;
}