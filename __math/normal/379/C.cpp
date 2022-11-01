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

int n;
int a[3 * ten(5)];

int main(){
	cin >> n;
	FOR(i, n) cin >> a[i];

	vector<Pii> vp(n);
	FOR(i, n) vp[i].first = a[i], vp[i].second = i;
	sort(vp.begin(), vp.end());

	int cur = 0;

	vector<int> ans(n);
	FOR(i, n) {
		cur = max(cur, vp[i].first);
		ans[vp[i].second] = cur;
		cur++;
	}

	FOR(i, n) printf("%d%c",ans[i],i==n-1?'\n':' ');

	return 0;
}