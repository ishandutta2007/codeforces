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

int n, m, f, p, a[1024][1024];
set <int> row[1024], col[1024];
int r[1024], c[1024];
set <pii> w;

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> m >> f;
	fill(r, r + 1024, 1);
	fill(c, c + 1024, 1);
	REP (i, f) {
		int x, y, z;
		cin >> x >> y >> z;
		a[--x][--y] = z;
		r[x] *= z;
		c[y] *= z;
	}
	cin >> p;
	int res = 1;
	REP (i, n) REP (j, m)
		if (!a[i][j]) {
			row[i].insert(j);
			col[j].insert(i);
			w.insert(pii(i, j));
		} 
	queue <int> Qr, Qc;
	REP (i, n) if (sz(row[i]) == 1)
		Qr.push(i);
	REP (j, m) if (sz(col[j]) == 1)
		Qc.push(j);
	for (; ; ) {
		bool ok = true;
		for (; sz(Qr) || sz(Qc); ) {
			ok = false;
			if (sz(Qr)) {
				int i = Qr.front();
				Qr.pop();
				if (row[i].size() == 0) continue;
				int j = *row[i].begin();
				row[i].clear();
				a[i][j] = -r[i];
				w.erase(pii(i, j));
				r[i] *= a[i][j];
				c[j] *= a[i][j];
				col[j].erase(i);
				if (sz(col[j]) == 1)
					Qc.push(j);
			} else {
				int j = Qc.front();
				Qc.pop();
				if (col[j].size() == 0) continue;
				int i = *col[j].begin();
				col[j].clear();
				a[i][j] = -c[j];
				w.erase(pii(i, j));
				r[i] *= a[i][j];
				c[j] *= a[i][j];
				row[i].erase(j);
				if (sz(row[i]) == 1)
					Qr.push(i);
			}
		}
		if (sz(w)) {
			ok = false;
			pii t = *w.begin();
			a[t.X][t.Y] = 1;
			w.erase(w.begin());
			row[t.X].erase(t.Y);
			col[t.Y].erase(t.X);
			res = (res + res) % p;
			if (sz(row[t.X]) == 1)
				Qr.push(t.X);
			if (sz(col[t.Y]) == 1)
				Qc.push(t.Y);
		}
		if (ok) break;
	}
	REP (i, n) if (r[i] == 1) res = 0;
	REP (j, m) if (c[j] == 1) res = 0;
	cout << res << endl;
	return 0;
}