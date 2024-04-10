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

int n, x, y;
int a[100500], s[100500];

pair<ll, vi> solve() {
	ll score = 0;
	vi r(n);
	multiset<int> X(s, s + x), Y(s + x, s + n);
	REP (i, n) {
		auto p = X.find(a[i]);
		if (p != X.end()) {
			X.erase(p);
			r[i] = 1;
			score += a[i] * y;
		} else {
			Y.erase(Y.find(a[i]));
			r[i] = 2;
			score += a[i] * x;
		}
	}
	return {-score, r};
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> x >> y;
	REP (i, n) {
		scanf("%d", a + i);
		s[i] = a[i];
	}
	auto r = solve();
	sort(s, s + n);
	r = min(r, solve());
	reverse(s, s + n);
	r = min(r, solve());
	auto &res = r.Y;
	REP (i, sz(res)) {
		if (i) putchar(' ');
		printf("%d", res[i]);
	}
	puts("");
	return 0;
}