#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int a[200000];

ll solve(vector<int>& l, vector<int>& r) {
	ll tmp = 0;

	for (int x : l) {
		int v = r.end() - lower_bound(r.begin(), r.end(), x);
		tmp += v;
	}
	return tmp;
}

int main(){
	int n;
	cin >> n;
	FOR(i, n) cin >> a[i];

	vector<int> l,r;
	FOR(i, n) if (a[i]) l.push_back(i); else r.push_back(i);
	
	ll ans = 0;
	ll l1 = solve(l, r);
	l.swap(r);
	FOR(i, sz(l)) l[i] = n - l[i];
	reverse(l.begin(), l.end());
	FOR(i, sz(r)) r[i] = n - r[i];
	reverse(r.begin(), r.end());
	ll l2 = solve(l, r);

	ans = min(l1, l2);
	cout << ans << endl;

	return 0;
}