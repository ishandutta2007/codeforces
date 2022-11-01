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
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
ll fastMin(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ x; }
ll fastMax(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int a[ten(5)];

int main() {
	int n; scanf("%d", &n);
	FOR(i, n) scanf("%d", a+ i );
	
	vector<Pii> v, ls;
	vector<Pii> nw;
	v.emplace_back(a[0], 1);
	ls.emplace_back(0, a[0]);
	for (int i = 1; i < n; i++) {
		nw.clear();
		FOR(j, sz(ls)) {
			auto g = gcd(ls[j].second, a[i]);
			if (sz(nw) != 0 && nw.back().second == g) {
				nw[sz(nw) - 1].first = ls[j].first;
				continue;
			}
			nw.emplace_back(ls[j].first, g);
		}
		if (sz(nw) == 0 || nw.back().second != a[i]) nw.emplace_back(i, a[i]);
		else nw[sz(nw) - 1].first = i;
		int last = -1;
		FOR(j, sz(nw)) {
			int dif = nw[j].first - last;
			v.emplace_back(nw[j].second, dif);
			last = nw[j].first;
		}
		ls.swap(nw);
	}

	map<int, ll> mp;
	FOR(i, sz(v)) {
		mp[v[i].first] += v[i].second;
	}

	int q; scanf("%d", &q);
	FOR(i, q) {
		int x; scanf("%d", &x);
		printf("%I64d\n",mp[x]);
	}

	return 0;
}