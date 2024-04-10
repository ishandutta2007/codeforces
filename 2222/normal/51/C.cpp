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

int n;
ll x[222222];
ll p[3];

bool check(ll D) {
	ll x0 = 0;
	REP (i, 3) {
		x0 = *upper_bound(x, x + n, x0);
		p[i] = x0 + D;
		x0 += 2 * D;
	}
	return x0 >= x[n - 1];
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	REP (i, n) {
		int y;
		scanf("%d", &y);
		x[i] = y * 2ll;
	}
	x[n] = -1ull/4;
	sort(x, x + n);
	ll L = 0, R = -1u/2;
	for (; L <= R; ) {
		ll D = (L + R) / 2;
		check(D) ? R = D - 1 : L = D + 1;
	}
	check(L);
	REP (i, 3) p[i] = min(p[i], 2000000000ll);
	printf("%.1lf\n", (double)(L * 0.5));
	printf("%.1lf %.1lf %.1lf\n"
	, (double)(p[0] * 0.5)
	, (double)(p[1] * 0.5)
	, (double)(p[2] * 0.5));
	return 0;
}