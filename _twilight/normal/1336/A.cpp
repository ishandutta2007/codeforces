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

const int N = 2e5 + 5;

int n, m;
int sz[N], dep[N];
bool vis[N];
vector<int> G[N];

void dfs(int p, int fa) {
	dep[p] = dep[fa] + 1;
	sz[p] = 1;
	for (auto e : G[p]) {
		if (e ^ fa) {
			dfs(e, p);
			sz[p] += sz[e];
		}
	}
}

pli calc(int p, int fa) {
	int t = vis[p];
	pli rt (0, t);
	for (auto e : G[p]) {
		if (e ^ fa) {
			auto x = calc(e, p);
			rt.fi += x.fi;
			rt.sc += x.sc;
		}
	}	
	if (!t)
		rt.fi += rt.sc;
	return rt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	vector<int> id;
	for (int i = 1; i <= n; i++) {
		id.pb(i);
	}
	dfs(1, 0);
	sort(id.begin(), id.end(), [&] (int x, int y) { return dep[x] - sz[x] > dep[y] - sz[y];	});
	for (int i = 0; i < m; i++) {
		vis[id[i]] = true;
	}
	ll ans = calc(1, 0).fi;
	cout << ans << '\n';
	return 0;
}