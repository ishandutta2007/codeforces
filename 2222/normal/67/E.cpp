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

int n;
pii p[1111];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	REP (i, n) cin >> p[i].X >> p[i].Y;
	if (p[0].X > p[1].X) 
		REP (i, n) {
			p[i].X = -p[i].X;
			p[i].Y = -p[i].Y;
		}
	p[n] = p[0];
	int x0 = p[0].X, x1 = p[1].X, y = p[0].Y;
	FOR (i, 1, n) {
		int j = (i + 1) % n;
		ll a = p[i].Y - p[j].Y;
		ll b = p[j].X - p[i].X;
		ll c = p[i].X * a + p[i].Y * b;
		int L = x0, R = x1, x;
		bool l = (x0 * a + y * b <= c);
		bool r = (x1 * a + y * b <= c);
		if (l && r) continue;
		if (l) {
			for (; L <= R; ) {
				x = (L + R) / 2;
				x * a + y * b <= c ? L = x + 1 : R = x - 1;
			}
			x1 = R;
		} else if (r) {
			for (; L <= R; ) {
				x = (L + R) / 2;
				x * a + y * b <= c ? R = x - 1 : L = x + 1;
			}
			x0 = L;
		} else {
			puts("0");
			return 0;
		}
	}
	cout << max(0, x1 - x0 + 1) << endl;
	return 0;
}