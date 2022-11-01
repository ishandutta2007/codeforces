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

int n, m, G, S;
vector < pair <pii, pii> > e;
int p[222];

vi adj[222];

vi path;
multiset<int> vs;

int f[222][222];

bool dfs(int x, int y, int prev = -1) {
	path.pb(x);
	if (x == y) return true;
	for (vi :: iterator i = adj[x].begin(); i != adj[x].end(); ++i) {
		if (*i == prev) continue;
		if (dfs(*i, y, x)) return true;
	}
	path.pop_back();
	return false;
}

void remedge(int x, int y) {
	for (vi :: iterator i = adj[x].begin(); i != adj[x].end(); ++i)
		if (*i == y) {
			swap(*i, adj[x].back());
			adj[x].pop_back();
			return;
		}
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> m >> G >> S;
	for (int x, y, g, s; m > 0; --m) {
		scanf("%d%d%d%d", &x, &y, &g, &s);
		e.pb(make_pair(pii(g, s), pii(x - 1, y - 1)));
	}
	sort(all(e));
	ll res = -1;
	int k = 0;
	for (vector < pair <pii, pii> > :: iterator i = e.begin(); i != e.end(); ++i) {
		int x = i->Y.X, y = i->Y.Y;
		if (dfs(x, y)) {
			int rx = x, ry = y, z = i->X.Y;
			for (int j = 0; j + 1 < path.size(); ++j) 
				if (f[path[j]][path[j + 1]] > z) 
					z = f[rx = path[j]][ry = path[j + 1]];
			if (z > i->X.Y) {
				vs.erase(vs.find(z));
//				cout << "- " << rx + 1 << ' ' << ry + 1 << endl;
				remedge(rx, ry);
				remedge(ry, rx);
				vs.insert(i->X.Y);
				f[x][y] = f[y][x] = i->X.Y;
				adj[x].pb(y);
				adj[y].pb(x);
//				cout << "+ " << x + 1 << ' ' << y + 1 << endl;
			}
			path.clear();
		} else {
			vs.insert(i->X.Y);
			f[x][y] = f[y][x] = i->X.Y;
			adj[x].pb(y);
			adj[y].pb(x);
			++k;
//				cout << "+ " << x + 1 << ' ' << y + 1 << endl;
		}
		if (k + 1 == n) {
			ll g = i->X.X, s = *vs.rbegin();
			ll score = g * G + s * S;
			if (res < 0 || score < res) res = score;
		}
	}
	cout << res << endl;
	return 0;
}