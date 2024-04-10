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

vector<ll> v;
ll a, b;

void go(ll x) {
	if (x > 1000000000000000) return;
	if (x >= a) v.pb(x);
	go(x * 10 + 4);
	go(x * 10 + 7);
}

int main() {
	cin >> a >> b;
	go(0);
	sort(all(v));
	ll res = 0;
	for (ll x : v) {
		res += ll(x) * (min(x, b) - a + 1);
		a = x + 1;
		if (a > b) break;
	}
	cout << res << endl;
	return 0;
}