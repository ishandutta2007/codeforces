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

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	int n, x, m, y;
	cin >> n >> x >> m >> y;
	if (x > y) swap(x, y), swap(n, m);
	ll res = n + m + 1;
	for (; n > 0 || m > 0; ) {
		if (n < m) {
			swap(n, m);
			swap(x, y);
			x *= -1;
			y *= -1;
		}
		int r = n--, a, b;
		if (x - r <= y && y <= x + r) {
			a = 1 + min(y - (x - r), (x + r) - y);
			b = min(m, max(y - (x - r), (x + r) - y) - 1);
		} else {
			a = max(1, y - (x + r) + 1);
			b = min(m, y - (x - r) - 1);
		}
		if (a > b) continue;
		int d = 2 * (b - a + 1);
		if (x - r <= y && y <= x + r)
			for (int s = -1; s < 2; s += 2) {
				int p = x + r * s;
				int q = abs(y - p);
				if (1 <= q && q <= m) ++d;
			}
		res += d - 1;
	}
	cout << res << endl;
	return 0;
}