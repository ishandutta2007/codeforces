#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
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
#include <bitset>
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

#pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

vector<int> e[ten(5) * 3];
int a[ten(5) * 3];

Pll dfs(int v){
	vector<Pll> rts;
	for (auto to : e[v]) {
		if (to < v) continue;
		auto r = dfs(to);
		rts.push_back(r);
	}

	ll child_even = 0, child_odd = numeric_limits<ll>::min() / 16;
	for (auto kv : rts) {
		ll neven = max(child_even + kv.first, child_odd + kv.second);
		ll nodd = max(child_even + kv.second, child_odd + kv.first);
		child_even = max(child_even, neven);
		child_odd = max(child_odd,nodd);
	}
	Pll ret(child_even,max( child_even + a[v] , child_odd) );

	return ret;
}

int main() {
	int n; scanf("%d", &n);
	FOR(i, n){
		int p; scanf("%d%d", &p, a + i);
		if (p != -1) {
			p--;
			e[p].push_back(i);
			e[i].push_back(p);
		}
	}

	Pll ans = dfs(0);
	cout << max(ans.first,ans.second) << endl;

	return 0;
}