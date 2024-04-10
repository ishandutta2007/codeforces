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

int n, m;
char a[1024][1024];
int f[1025][1025];

void rotate() {
	REP (i, 1024) REP (j, i) swap(a[i][j], a[j][i]);
	REP (i, 1024) reverse(a[i], a[i] + 1024);
}

int sum(int x0, int y0, int x1, int y1) {
	++x1, ++y1;
	return f[x1][y1] + f[x0][y0] - f[x1][y0] - f[x0][y1];
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> m;
	REP (i, n) scanf("%s", a + i);
	ll res = 0;
	REP (rr, 4) {
		CL(f, 0);
		REP (i, 1024) REP (j, 1024) f[i + 1][j + 1] = (a[i][j] == '*') + f[i][j + 1] + f[i + 1][j] - f[i][j];
		REP (i, 1024) REP (j, 1024) if (a[i][j] == '*') 
			res += (ll)sum(i, 0, i, j - 1) * sum(0, j, i - 1, j);
		rotate();
	}
	cout << res << endl;
	return 0;
}