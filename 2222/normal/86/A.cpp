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

ll f(ll x) {
	if (x < 10) return 9 - x;
	return f(x / 10) * 10 + (9 - (x % 10));
}

ll solve(ll x, ll y, ll z) {
	if (x > y) return 0;
	ll res = max(x * f(x), y * f(y));
	ll v = z / 2;
	if (x <= v && v <= y) 
		res = max(res, v * f(v));
	return res;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	ll a, b, best = 0;
	cin >> a >> b;
	for (ll X = 1; X <= b; X *= 10) {
		ll Y = X * 10 - 1;
		best = max(best, solve(max(X, a), min(Y, b), Y));
	}
	cout << best << endl;
	return 0;
}