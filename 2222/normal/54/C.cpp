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

int a[20], m;

ll IS(ll a, ll b, ll x, ll y) { 
	x = max(a, x);
	y = min(b, y);
	return max(0ll, y - x + 1);
}

ll Solve(ll a, ll b) {
	ll res = 0;
	ll x = 1, y = 1;
	for (; x > 0 && x <= b; ) {
		res += IS(a, b, x, y);
		x *= 10;
		y = y * 10 + 9;
	}
	return res;		
}

long double P[1024];

double F[1024][1024];

double f(int i, int k) {
	if (k == 0) return 1;
	if (i < 0) return 0;
	double &res = F[i][k];
	if (res < -1) res = P[i] * f(i - 1, k - 1) + (1 - P[i]) * f(i - 1, k);
	return res;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	int n;
	cin >> n;
	REP (i, n) {
		ll l, r;
		cin >> l >> r;
		P[i] = (long double)Solve(l, r) / (r - l + 1);
	}
	int k;
	cin >> k;
	CL(F, -2);
	printf("%.12lf\n", (double)f(n - 1, (k * n + 99) / 100));
	return 0;
}