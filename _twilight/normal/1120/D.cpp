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

const int N = 2e5 + 5;


int n;
int c[N];
ll f[N][2];
boolean g[N][2];
vector<int> G[N];

void dfs(int p, int fa) {
	if (p > 1 && vsize(G[p]) == 1u) {
		f[p][1] = 0, f[p][0] = c[p];
		return;
	} else {
		f[p][1] = llf, f[p][0] = 0;
	}
	for (auto e : G[p]) {
		if (e == fa)
			continue;
		dfs(e, p);
		f[p][1] = min(f[e][0] + f[p][1], f[p][0] + f[e][1]);
		f[p][0] = f[e][0] + f[p][0];
	}
	vmin(f[p][0], f[p][1] + c[p]);
}

vector<int> S;
void dfs2(int p, int fa) {
	if (p == 1) {
		g[p][0] = true;
		g[p][1] = false;
	}
	if (fa)
		G[p].erase(find(G[p].begin(), G[p].end(), fa));
	vector<ll> pr0 {0}, sf0 {0};
	for (auto e : G[p])
		pr0.pb(pr0.back() + f[e][0]);
	reverse(G[p].begin(), G[p].end());
	for (auto e : G[p])
		sf0.pb(sf0.back() + f[e][0]);
	reverse(G[p].begin(), G[p].end());
	reverse(sf0.begin(), sf0.end());
	int deg = vsize(G[p]);
	if (g[p][0]) {
		if (f[p][0] == f[p][1] + c[p]) {
			S.pb(p);
			vector<int> qaq;
			for (int i = 0; i < deg; i++) {
				int e = G[p][i];
				if (pr0[i] + sf0[i + 1] + f[e][1] == f[p][1]) {
					qaq.pb(e);
					g[e][1] = true;
				}
			}
			if (vsize(qaq) == 1) {
				for (auto e : G[p])
					if (e ^ qaq.back())
						g[e][0] = true;
			} else {
				for (auto e : G[p])
					g[e][0] = true;
			}
		}
		if (f[p][0] == pr0.back())
			for (auto e : G[p])
				g[e][0] = true;
	}
	if (g[p][1]) {
		vector<int> qaq;
		for (int i = 0; i < deg; i++) {
			int e = G[p][i];
			if (pr0[i] + sf0[i + 1] + f[e][1] == f[p][1]) {
				qaq.pb(e);
				g[e][1] = true;
			}
		}
		if (vsize(qaq) == 1) {
			for (auto e : G[p])
				if (e ^ qaq.back())
					g[e][0] = true;
		} else {
			for (auto e : G[p])
				g[e][0] = true;
		}
	}
	for (auto e : G[p])
		dfs2(e, p);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 0);
	dfs2(1, 0);
	cout << f[1][0] << " " << S.size() << '\n';
	sort(S.begin(), S.end());
	for (auto e : S)
		cout << e << ' ';
 	return 0;
}