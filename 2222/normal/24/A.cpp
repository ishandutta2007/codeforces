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

int total, n;
vector <pii> a[111];
bool b[111];

int dfs(int x) {
	b[x] = true;
	for (vector <pii> :: iterator y = a[x].begin(); y != a[x].end(); ++y)
		if (!b[y->X]) 
			return y->Y + dfs(y->X);
	for (vector <pii> :: iterator y = a[x].begin(); y != a[x].end(); ++y)
		if (y->X == 0)
			return y->Y;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	REP (i, n) {
		int x, y, c;
		cin >> x >> y >> c;
		--x, --y;
		a[x].pb(pii(y, 0));
		a[y].pb(pii(x, c));
		total += c;
	}
	int res = dfs(0);
	cout << min(res, total - res) << endl;
	return 0;
}