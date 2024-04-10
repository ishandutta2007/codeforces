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

const int mod = 1000000007;

int n;
pii p[5555];

set<int> get(int x0, int y0, int x1, int y1) {
	if (x0 > x1) swap(x0, x1);
	if (y0 > y1) swap(y0, y1);
	set<int> res;
	REP (i, n) if (x0 <= p[i].X && p[i].X <= x1 && y0 <= p[i].Y && p[i].Y <= y1) res.insert(i);
	return res;
}

bool check(const set<int> &A, const set<int> &B) {
	REP (i, n)
		if (!A.count(i) && !B.count(i))
			return false;
	return true;
}

int common(const set<int> &A, const set<int> &B) {
	int res = 0;
	REP (i, n)
		if (A.count(i) && B.count(i))
			++res;
	return res;
}

bool check(int d) {
	int x0 = p[0].X, y0 = p[0].Y, x1 = x0, y1 = y0;
	REP (i, n) {
		x0 = min(x0, p[i].X);
		y0 = min(y0, p[i].Y);
		x1 = max(x1, p[i].X);
		y1 = max(y1, p[i].Y);
	}
	set<int> A[4];
	A[0] = get(x0, y0, x0 + d, y0 + d);
	A[1] = get(x1, y0, x1 - d, y0 + d);
	A[2] = get(x0, y1, x0 + d, y1 - d);
	A[3] = get(x1, y1, x1 - d, y1 - d);
	REP (j, 4) REP (i, j)
		if (check(A[i], A[j]))
			return true;
	return false;
}

int count(int d) {
	int x0 = p[0].X, y0 = p[0].Y, x1 = x0, y1 = y0;
	REP (i, n) {
		x0 = min(x0, p[i].X);
		y0 = min(y0, p[i].Y);
		x1 = max(x1, p[i].X);
		y1 = max(y1, p[i].Y);
	}
	set<int> A[4];
	A[0] = get(x0, y0, x0 + d, y0 + d);
	A[1] = get(x1, y0, x1 - d, y0 + d);
	A[2] = get(x0, y1, x0 + d, y1 - d);
	A[3] = get(x1, y1, x1 - d, y1 - d);
	int res = 0;
	set<pair<set<int>, set<int>>> U;
	REP (i, 4) REP (j, 4) 
		if (check(A[i], A[j]) && U.count({A[i], A[j]}) == 0) {
			U.insert({A[i], A[j]});
			int k = common(A[i], A[j]), z = 1;
			for (; k > 0; --k)
				if ((z += z) >= mod)
					z -= mod;
			if ((res += z) >= mod)
				res -= mod;
		}
	return res;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	REP (i, n) {
		int x, y;
		cin >> x >> y;
		p[i] = {x + y, x - y};
	}
	int L = 0, R = 20000, V;
	for (; L <= R; ) {
		V = (L + R) / 2;
		check(V) ? R = V - 1 : L = V + 1;
	}
	cout << L << endl;
	cout << count(L) << endl;
	return 0;
}