#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <limits>
#include <ctime>
#include <cassert>

#define pb push_back
#define mp make_pair
#define rn(n) int n; cin >> n;
#define fi(n) for (int i = 0; i < n; ++i)
#define fie(n) for (int i = 1; i <= n; ++i)
#define fir(l, r) for (int i = (l); i <= (r); ++i)
#define fj(n) for (int j = 0; j < n; ++j)
#define fje(n) for (int j = 1; j <= n; ++j)
#define fjr(l, r) for (int j = (l); j <= (r); ++j)
#define fv(i, n) for (int i = 0; i < n; ++i)
#define fve(i, n) for (int i = 1; i <= n; ++i)
#define fvr(j, l, r) for (int j = (l); j <= (r); ++j)
#define sc(n) scanf("%d", &n)
#define scc(n) scanf("%c", &n)
#define scs(n) scanf("%s", &n)
#define scl(n) scanf("%lld", &n)
#define endl '\n'
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define fll(x, a) memset(x, a, sizeof(x))
#define clr(x) memset(x, 0, sizeof(x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
#ifndef _getchar_nolock
#define _putchar_nolock putchar_unlocked
#define _getchar_nolock getchar_unlocked
#endif
//#define int ll

#pragma warning (disable : 4996)
#pragma optimize ("gtsy", on)
//#pragma comment(linker, "/STACK:536870912")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef vector <char> vc;

const ld EPS = 1e-8;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;
const int N = 28;

vi f(N);

void dfs_sz(int v, vector<vii> & a, vi & sz, vi& p) {
	sz[v] = 1;
	for (int i = 0; i < a[v].size(); ++i) {
		if (a[v][i].first == p[v])
			continue;
		p[a[v][i].first] = v;
		dfs_sz(a[v][i].first, a, sz, p);
		sz[v] += sz[a[v][i].first];
	}
	return;
}

int dfs(int v, vector<vii>& a, vc& used, vi& sz, vi& p, int x) {
	if (sz[v] == x)
		return v;
	for (int i = 0; i < a[v].size(); ++i) {
		if (a[v][i].first == p[v] || used[a[v][i].second])
			continue;
		int u = dfs(a[v][i].first, a, used, sz, p, x);
		if (u != -1)
			return u;
	}
	return -1;
}

bool check(int v, int x, vector<vii>& a, vc& used, vi& sz, vi& p) {
	if (x <= 1)
		return 1;
	int u = dfs(v, a, used, sz, p, f[x - 2]);
	if (u == -1) {
		u = dfs(v, a, used, sz, p, f[x - 1]);
		if (u == -1)
			return 0;
		for (int i = 0; i < a[u].size(); ++i) {
			if (a[u][i].first == p[u]) {
				used[a[u][i].second] = 1;
				break;
			}
		}
		int cur = p[u];
		while (cur != -1) {
			sz[cur] -= sz[u];
			cur = p[cur];
		}
		p[u] = -1;
		return check(v, x - 2, a, used, sz, p) && check(u, x - 1, a, used, sz, p);
	}
	for (int i = 0; i < a[u].size(); ++i) {
		if (a[u][i].first == p[u]) {
			used[a[u][i].second] = 1;
			break;
		}
	}
	int cur = p[u];
	while (cur != -1) {
		sz[cur] -= sz[u];
		cur = p[cur];
	}
	p[u] = -1;
	return check(v, x - 1, a, used, sz, p) && check(u, x - 2, a, used, sz, p);
}

vii gen(int x) {
	vii a, b;
	for (int i = 2; i <= x; ++i) {
		vii c = b;
		for (int i = 0; i < b.size(); ++i) {
			b[i].first += a.size() + 1;
			b[i].second += a.size() + 1;
		}
		int u = rand() % (a.size() + 1), v = rand() % (b.size() + 1);
		for (auto p : a)
			b.push_back(p);
		b.push_back({ u, v + a.size() + 1 });
		a = c;
	}
	return b;
}

//#define GEN

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	f[0] = f[1] = 1;
	for (int i = 2; i < N; ++i)
		f[i] = f[i - 1] + f[i - 2];

#ifdef GEN
	int x1;
	cin >> x1;
	int n = f[x1];
	vector<vii> a(n);
	vii inp = gen(x1);
	for (int i = 0; i < n - 1; ++i) {
		int u = inp[i].first, v = inp[i].second;
		a[u].push_back({ v, i });
		a[v].push_back({ u, i });
}
#else
	int n;
	cin >> n;
	vector<vii> a(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		a[u].push_back({ v, i });
		a[v].push_back({ u, i });
	}
#endif
	int x = -1;
	for (int i = 0; i < N; ++i) {
		if (n == f[i]) {
			x = i;
			break;
		}
	}
	if (x == -1) {
		cout << "NO";
		return 0;
	}
	vi sz(n), p(n, -1);
	dfs_sz(0, a, sz, p);

	vc used(n - 1);
	if (check(0, x, a, used, sz, p))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}