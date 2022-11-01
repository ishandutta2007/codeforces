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

int n, f[100500], s[100500], cycle[100500];
vi a[100500];

void findCycles() {
	queue<int> Q;
	REP (i, n) if (cycle[i] == 0) Q.push(i);
	for (; Q.size(); ) {
		int x = f[Q.front()];
		Q.pop();
		if (--cycle[x] == 0) 
			Q.push(x);
	}
}

bool b[100500];
int px, py;

void dfs(int x) {
	b[x] = true;
	for (int y : a[x]) {
		if (cycle[x] && cycle[y]) {
			px = x;
			py = y;	
		}
		if (!b[y]) dfs(y);
	}
}

inline pii operator + (const pii &p, const pii &q) { return pii(p.X + q.X, p.Y + q.Y); }
inline pii operator - (const pii &p, const pii &q) { return pii(p.X - q.X, p.Y - q.Y); }

pair<pii, pii> MF[100500];
bool u[100500];

pair<pii, pii> F(int x, int prev) {
	pair<pii, pii> &res = MF[x];
	res = make_pair(pii(), pii());
	for (int y : a[x]) if (y != prev) {
		auto q = F(y, x);
		res.X = res.X + q.Y;
		if (!u[x] && !u[y]) res.Y = max(res.Y, q.X - q.Y + pii(1, s[x] != s[y]));
	}
	res.Y = res.X + res.Y;
	return res;
}

pii ff(int x) {
	auto res = F(x, -1);
	return max(res.X, res.Y);
}

void G(vector<pii> &ans, bool ok, int x, int prev) {
	auto &res = MF[x];
	if (!ok || res.X == res.Y) {
		for (int y : a[x]) if (y != prev) 
			G(ans, true, y, x);
	} else {
		for (int y : a[x]) if (y != prev) {
			auto &q = MF[y];
			if (ok && !u[x] && !u[y] && res.X + q.X - q.Y + pii(1, s[x] != s[y]) == res.Y) {
				ok = false;
				ans.pb(pii(x, y));
				G(ans, false, y, x);
			} else G(ans, true, y, x);
		}
	}
}

vector<pii> go(int x) {
	vector<pii> ans;
	auto res = MF[x];
	G(ans, res.Y > res.X, x, -1);
	return ans;
}

void remv(int x) {
	for(int y : a[x]) 
		a[y].erase(find(all(a[y]), x));
	a[x].clear();
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	REP (i, n) {
		scanf("%d%d", f + i, s + i);
		cycle[--f[i]]++;
	}
	findCycles();
	REP (i, n) {
		a[i].pb(f[i]);
		a[f[i]].pb(i);
	}
	int bf = 0;
	vector<pii> res;
	REP (i, n) if (!b[i]) {
		b[i] = true;
		px = -1;
		py = -1;
		dfs(i);
		if (~px) {
			a[px].erase(find(all(a[px]), py));
			a[py].erase(find(all(a[py]), px));
		}
		pii r1 = ff(i);
		vector<pii> m1 = go(i);
		if (~px) {
			u[px] = true;
			u[py] = true;
			pii r2 = ff(i) + pii(1, s[px] != s[py]);
			if (r2 > r1) {
				r1 = r2;
				m1 = go(i);
				m1.pb(pii(px, py));
			}
		}
		res.insert(res.end(), all(m1));
		bf += r1.Y;
	}
	cout << sz(res) << ' ' << bf << endl;
	for (auto t : res) 
		printf("%d %d\n", t.X + 1, t.Y + 1);
	return 0;
}