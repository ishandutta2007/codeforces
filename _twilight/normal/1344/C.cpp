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
char ans[N];
vector<int> G[N], rG[N];

bool vis[N], ins[N];
void dfs(int p) {
	vis[p] = ins[p] = true;
	for (auto e : G[p]) {
		if (!vis[e]) {
			dfs(e);
		} else if (ins[e]) {
			throw 1;
		}
	}
	ins[p] = false;
}

bool vispre[N], vissuf[N];

void labelsuf(int p) {
	if (vissuf[p]) return;
	if (!ans[p]) ans[p] = 'E';
	vissuf[p] = true;
	for (auto e : G[p]) {
		labelsuf(e);
	}
}
void labelpre(int p) {
	if (vispre[p]) return;
	if (!ans[p]) ans[p] = 'E';
	vispre[p] = true;
	for (auto e : rG[p]) {
		labelpre(e);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ans[i] = 0;
	}
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		G[v].push_back(u);
		rG[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		try {
			dfs(i);
		} catch (int) {
			cout << "-1" << '\n';
			return 0;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!ans[i]) {
			labelpre(i);
			ans[i] = 0;
			labelsuf(i);
			ans[i] = 'A';
			cnt++;
		} else {
			labelpre(i);
			labelsuf(i);
		}
	}
	cout << cnt << '\n';
	cout << (ans + 1) << '\n';
	return 0;
}