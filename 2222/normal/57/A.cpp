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
	pii p, q;
	int n;
	cin >> n >> p.X >> p.Y >> q.X >> q.Y;
	vector <pii> a;
	REP (i, n) a.pb(pii(0, i));
	REP (i, n) a.pb(pii(i, n));
	REP (i, n) a.pb(pii(n, n - i));
	REP (i, n) a.pb(pii(n - i, 0));
//	REP (i, sz(a)) cout << a[i].X << ' ' << a[i].Y << endl;
	int i = find(all(a), p) - a.begin(), j = find(all(a), q) - a.begin();
	if (i > j) swap(i, j);
	cout << min(j - i, sz(a) + i - j) << endl;
	return 0;
}