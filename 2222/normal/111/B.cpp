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

int n;
int x[100500], y[100500];
	
map<int, vi> d;

vi divs(int i, int n) {
	vi v;
	int x = 1;
	for (; x * x < n; ++x) {
		if (n % x == 0) {
			v.pb(x);
			v.pb(n / x);
		}
	}
	if (x * x == n) {
		v.pb(x);
	}
	for (int x : v) d[x].pb(i);
	return v;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	REP (i, n) {
		cin >> x[i] >> y[i];
		vi t = divs(i, x[i]);
		int res = 0;
		for (int x : t) {
			vi &q = d[x];
			if (lower_bound(all(q), i - y[i])[0] == i) ++res;
		}
		cout << res << endl;
	}
	return 0;
}