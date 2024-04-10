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

int n, m, Q;

struct point { int x, y; } p[1111];
struct circle { int x, y, r; } c[1111];

bool operator < (const circle &a, const circle &b) { return a.r < b.r; }

vi adj[1111];
int f[1111];
int a[1111][1111];

bool contains(const circle &a, const circle &b) {
	ll dx = a.x - b.x, dy = a.y - b.y, dr = a.r - b.r;
	return dx * dx + dy * dy < dr * dr;
}

bool contains(const circle &a, const point &b) {
	ll dx = a.x - b.x, dy = a.y - b.y, dr = a.r;
	return dx * dx + dy * dy < dr * dr;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> m >> Q;
	REP (i, n) scanf("%d%d", &p[i].x, &p[i].y);
	REP (i, m) scanf("%d%d%d", &c[i].r, &c[i].x, &c[i].y);
	sort(c, c + m);
	REP (i, m) {
		int j = i + 1;
		for (; j < m; ++j) 
			if (contains(c[j], c[i])) 
				break;
		adj[i].pb(j);
		adj[j].pb(i);
	}
	REP (i, n) {
		int j = 0;
		for (; j < m; ++j)
			if (contains(c[j], p[i]))
				break;
		f[i] = j;
	}
	CL(a, -1);
	REP (i, m + 1) {
		int *d = a[i];
		queue <int> Q;
		Q.push(i);
		d[i] = 0;
		for (; Q.size(); ) {
			int x = Q.front(); 
			Q.pop();
			for (vi :: iterator y = adj[x].begin(); y != adj[x].end(); ++y)
				if (d[*y] < 0) {
					d[*y] = d[x] + 1;
					Q.push(*y);
				}
		}
	}
	REP (i, Q) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x, --y;
		printf("%d\n", a[f[x]][f[y]]);
	}
	return 0;
}