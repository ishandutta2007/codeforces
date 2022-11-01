#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int n, m;
vi adj[2222];

bool b[2222];
vi v;

void dfs(int x) {
	v.pb(x);
	b[x] = true;
	for (vi :: iterator i = adj[x].begin(); i != adj[x].end(); ++i)
		if (!b[*i]) dfs(*i);
}

vi a[2222];

int p[2222], q[2222];

int P(int i) { return p[i] == i ? i : p[i] = P(p[i]); }
int Q(int i) { return q[i] == i ? i : q[i] = Q(q[i]); }

void unite(int i, int j) { p[P(i)] = P(j); }

bool dfs_unite(int x, int y, int z = -1) {
	if (x == y) return true;
	for (vi :: iterator i = a[x].begin(); i != a[x].end(); ++i)
		if (*i != z && dfs_unite(*i, y, x)) {
			q[Q(x)] = Q(y);
			return true;
		}
	return false;
}

int mp[2222];

void set_mp() {
	UN(v);
	CL(mp, -1);
	REP (i, sz(v)) mp[v[i]] = i;
}

int f(int x, int prev = -1) {
	int res = 0;
	for (vi :: iterator i = a[x].begin(); i != a[x].end(); ++i)
		if (*i != prev) res = max(res, f(*i, x));
	return res + 1;
}

int solve() {
	int add = 0;
	set_mp();
	vector <pii> edges;
	REP (i, sz(v)) {
		int x = v[i];
		for (vi :: iterator j = adj[x].begin(); j != adj[x].end(); ++j) {
			if (~mp[*j]) {
				int k = mp[*j];
				if (i < k) edges.pb(pii(i, k));
			}
		}
		p[i] = q[i] = i;
	}
	for (vector <pii> :: iterator e = edges.begin(); e != edges.end(); ++e) {
		if (P(e->X) != P(e->Y)) {
			a[e->X].pb(e->Y);
			a[e->Y].pb(e->X);
			unite(e->X, e->Y);
		} else dfs_unite(e->X, e->Y);
	}
	REP (i, sz(v)) {
		a[i].clear();
		v[i] = Q(i);
	}
	add = sz(v);
	set_mp();
	add -= sz(v);
	int ee = 0;
	for (vector <pii> :: iterator e = edges.begin(); e != edges.end(); ++e) {
		int x = mp[Q(e->X)], y = mp[Q(e->Y)];
		if (x < 0 || y < 0 || x == y) continue;
		a[x].pb(y);
		a[y].pb(x);
		++ee;
	}
	int u = sz(v), res = u;
	if (u < 4) res = 0;
	else {
		add += 2;
		REP (i, u) if (sz(a[i]) == 1) {
			--add;
			res = min(res, u - f(i));
		}
	}
	REP (i, u) a[i].clear();
	return res + add;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	#if 1
	cin >> n >> m;
	REP (i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x, --y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	#else
	n = 2000;
	REP (i, 100000) {
		int x = rand() % n, y;
		do y = rand() % n; while (x == y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	#endif
	int res = -1;
	REP (i, n) {
		if (!b[i]) {
			++res;
			dfs(i);
			res += solve();
			v.clear();
		}
	}
	cout << res << endl;
	return 0;
}