#include <algorithm>
#include <iostream>
#include <assert.h>
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

int main() {
	int t1, t2, x1, x2, t0;
	cin >> t1 >> t2 >> x1 >> x2 >> t0;
	if (t1 == t2) {
		cout << x1 << ' ' << x2 << endl;
		return 0;
	}
	if (t0 == t2) {
		cout << 0 << ' ' << x2 << endl;
		return 0;
	}
	ll r1, r2, tot = 0;
	double bd = 1e111;
	for (int y1 = 0; y1 <= x1; ++y1) {
		int L = 0, R = x2;
		ll y2 = (ll(y1) * (t0 - t1)) / (t2 - t0) - 10;
		y2 = max(min(y2, (ll)x2), 0ll);
		REP (l, 20) {
			if (y2 <= x2 && y1 + y2) {
				double d = double(t1 * ll(y1) + t2 * ll(y2)) / (y1 + y2) - t0;
				if (d >= 0)
					if (d + 1e-9 < bd || d <= bd + 1e-9 && y1 + y2 > tot) {
						r1 = y1;
						r2 = y2;
						bd = d;
						tot = y1 + y2;
					}
			}
			++y2;
		}
	}
	cout << r1 << ' '  << r2 << endl;
	return 0;
}