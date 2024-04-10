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

vi v[26];

ll f(const string &b) {
	ll res = 0;
	REP (i, sz(b)) {
		int c = b[i] - 'a', d = sz(b);
		if (sz(v[c])) {
			d = abs(v[c][0] - i);
			d = min(d, abs(v[c].back() - i));
			vi :: iterator j = lower_bound(all(v[c]), i);
			if (j != v[c].end()) d = min(d, abs(*j - i));
			if (j != v[c].begin()) d = min(d, abs(j[-1] - i));
		}
		res += d;
	}
	return res;
}

char s[222222];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	int n, m;
	gets(s);
	sscanf(s, "%d%d", &n, &m);
	gets(s);
	REP (i, m) v[s[i] - 'a'].pb(i);
	REP (i, n) {
		gets(s);
		cout << f(s) << endl;
	}
	return 0;
}