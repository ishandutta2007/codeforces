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

int x, y, d, n;
int dx[22], dy[22];

int F[444][444][2][2];

int go(int x, int y, bool p1, bool p2) {
	if (x * x + y * y > d * d) return 1;
	int &res = F[x + 222][y + 222][p1][p2];
	if (res == 0) {
		res = -1;
		if (p1) res = max(res, -go(y, x, p2, false));
		REP (k, n) {
			res = max(res, -go(x + dx[k], y + dy[k], p2, p1));
			if (res > 0) break;
		}
	//	cout << x << ' ' << y << ' ' << p1 << ' ' << p2 << ' ' << res << endl;
	}
	return res;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> x >> y >> n >> d;
	REP (i, n) cin >> dx[i] >> dy[i];
	puts(go(x, y, 1, 1) > 0 ? "Anton" : "Dasha");
	return 0;
}