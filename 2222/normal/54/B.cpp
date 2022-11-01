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

char a[32][32];
char t[32][32];

void rotate(int n) {
	REP (j, n) REP (i, j) swap(t[i][j], t[j][i]);
	REP (i, n) reverse(t[i], t[i] + n);
}

string get(int n, int m) {
	string res;
	REP (i, n) REP (j, m) res += t[i][j];
	if (n == m) {
		REP (k, 3) {
			rotate(n);
			string v;
			REP (i, n) REP (j, m) v += t[i][j];
			res = min(res, v);
		}
		rotate(n);
	} else {
		string v;
		for (int i = n; i --> 0; )
			for (int j = m; j --> 0; )
				v += t[i][j];
		res = min(res, v);
	}
	return res;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	set <pii> res;
	int n, m;
	cin >> n >> m;
	REP (i, n) cin >> a[i];
	for (int x = 1; x <= n; ++x) if (n % x == 0)
		for (int y = 1; y <= m; ++y) if (m % y == 0) {
			set <string> S;
			int N = n / x, M = m / y;
			CL(t, 0);
			REP (i, N) REP (j, M) {
				REP (ii, x) REP (jj, y) t[ii][jj] = a[i * x + ii][j * y + jj];
				S.insert(get(x, y));
			}
			if (sz(S) == N * M) res.insert(pii(x * y, x));
		}
	cout << res.size() << endl;
	pii ex = *res.begin();
	cout << ex.Y << ' ' << ex.X / ex.Y << endl;
	return 0;
}