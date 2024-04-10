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

const int N = 5e5 + 5;

int n;
int tg[N << 1];
int fd[N], fu[N];
vector<int> G[N];
vector<pii> Gd[N];

void dfs1(int p, int fa) {
	fd[p] = 0;
	for (auto e : G[p]) {
		if (e ^ fa) {
			dfs1(e, p);
			vmax(fd[p], fd[e] + 1);
		}
	}
}
void dfs2(int p, int fa) {
	int mx = fu[p];
	for (auto e : G[p]) {
		if (e ^ fa) {
			vmax(fu[e], mx + 1);
			vmax(mx, fd[e] + 1);
		}
	}
	reverse(G[p].begin(), G[p].end());
	mx = 0;
	for (auto e : G[p]) {
		if (e ^ fa) {
			vmax(fu[e], mx + 1);
			vmax(mx, fd[e] + 1);
		}
	}
	reverse(G[p].begin(), G[p].end());
	for (auto e : G[p]) {
		if (e ^ fa) {
			dfs2(e, p);
		}
	}
}

void dfs3(int p, int fa) {
	vmax(tg[1], vsize(G[p]) + 1);
	vector<int> d;
	auto& D = Gd[p];
	for (auto e : G[p])
		if (e ^ fa)
			d.pb(fd[e] + 1);
	if (fa)
		d.pb(fu[p]);
	sort(d.begin(), d.end());
	for (auto t : d) {
		if (D.empty() || D.back().fi ^ t) {
			D.eb(t, 1);
		} else {
			D.back().sc++;
		}
	}
//	cerr << p << " " << Vmsg(D) << '\n';
	auto& Dfa = Gd[fa];
	auto itx = lower_bound(Dfa.begin(), Dfa.end(), pii(fd[p] + 1, 0));
	auto ity = lower_bound(D.begin(), D.end(), pii(fu[p], 0));
	if (fa) (*itx).sc--, (*ity).sc--;
	vector<pii> E;
	auto p1 = D.begin(), _p1 = D.end();
	auto p2 = Dfa.begin(), _p2 = Dfa.end();
	while (p1 != _p1 && p2 != _p2) {
		if ((*p1).fi == (*p2).fi) {
			E.eb((*p1).fi, (*p1).sc + (*p2).sc);
			p1++, p2++;
		} else if ((*p1).fi < (*p2).fi) {
			E.pb(*(p1++));
		} else {
			E.pb(*(p2++));
		}
	}
	while (p1 != _p1) E.pb(*p1++);
	while (p2 != _p2) E.pb(*p2++);
	int cnt = 0;
	reverse(E.begin(), E.end());
	for (auto e : E) {
		cnt += e.sc;
		vmax(tg[e.fi * 2], cnt);
	}
	if (fa) (*itx).sc++, (*ity).sc++;

	reverse(D.begin(), D.end());
	cnt = 0;
	for (auto e : D) {
		if (e.sc) {
			vmax(tg[e.fi * 2 + 1], cnt + 1);
			cnt += e.sc;
			vmax(tg[e.fi * 2], cnt);
			vmax(tg[e.fi * 2 - 1], cnt);
		}
	}
	reverse(D.begin(), D.end());

	for (auto e : G[p])
		if (e ^ fa)
			dfs3(e, p);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	dfs3(1, 0);
	for (int i = (n * 2); i > 1; i--) {
		tg[i] = max(tg[i], 1);
		vmax(tg[i - 2], tg[i]);
	}
	for (int i = 1; i <= n; i++) {
		cout << tg[i] << " ";
	}
	return 0;
}