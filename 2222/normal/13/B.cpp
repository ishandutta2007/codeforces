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

#define all(a)		(a).begin(),(a).end()
#define sz(a)		int((a).size())
#define FOR(i,a,b)	for(int i=a;i<b;++i)
#define REP(i,n)	FOR(i,0,n)
#define UN(v)		sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)		memset(a,b,sizeof a)
#define pb			push_back
#define X			first
#define Y			second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

ll det(int a, int b, int c, int d) { return a * ll(d) - b * ll(c); }

bool ch(int x0, int x1, int x) {
	x1 -= x0, x -= x0;
	x0 = min(x, x1 - x);
	x1 = max(x, x1 - x);
	if (x0 < 0 || 4 * x0 < x1) return false;
	return true;
}

struct line {
	int x1, y1, x2, y2;
	void read() { scanf("%d%d%d%d", &x1, &y1, &x2, &y2); }
	pii p1(){ return pii(x1, y1); }
	pii p2(){ return pii(x2, y2); }
	void rev() {
		swap(x1, x2);
		swap(y1, y2);
	}
	void shift(int x, int y) { x1 -= x, y1 -= y, x2 -= x, y2 -= y; }
	bool contains(const pii &p) { return det(x1 - p.X, y1 - p.Y, x2 - p.X, y2 - p.Y) == 0; }
	bool check(int x, int y) {
		return ch(min(x1, x2), max(x1, x2), x) && ch(min(y1, y2), max(y1, y2), y);
	}
};

inline ll d2(int x, int y){ return x * ll(x) + y * ll(y); }

bool solve(line a, line b, line c) {
	if (a.p1() == b.p1() || a.p1() == b.p2()) a.rev();
	if (b.p2() == a.p2()) b.rev();
	if (a.p2() != b.p1()) return false;
	pii q = a.p2();
	a.shift(q.X, q.Y);
	b.shift(q.X, q.Y);
	c.shift(q.X, q.Y);
	ll A = d2(a.x1, a.y1);
	ll B = d2(b.x2, b.y2);
	ll D = d2(a.x1 - b.x2, a.y1 - b.y2);
	if (D == 0 || A + B < D) return false;
	if (!a.contains(c.p1())) c.rev();
	if (!a.contains(c.p1()) || !b.contains(c.p2())) return false;
	return a.check(c.x1, c.y1) && b.check(c.x2, c.y2);
}

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	int T;
	for (cin >> T; T --> 0; ) {
		line a, b, c;
		a.read();
		b.read();
		c.read();
		puts(
			solve(a, b, c) ||
			solve(a, c, b) ||
			solve(b, a, c) ||
			solve(b, c, a) ||
			solve(c, a, b) ||
			solve(c, b, a) ? "YES" : "NO");
	}
	return 0;
}