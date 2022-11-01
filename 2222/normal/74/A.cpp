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
	int n;
	cin >> n;
	pair <int, string> res(-1000000000, "");
	REP (i, n) {
		pair <int, string> t;
		int plus, minus, a, b, c, d, e, score;
		cin >> t.Y >> plus >> minus >> a >> b >> c >> d >> e;
		t.X = plus * 100 - minus * 50 + a + b + c + d + e;
		res = max(res, t);
	}
	cout << res.Y << endl;
	return 0;
}