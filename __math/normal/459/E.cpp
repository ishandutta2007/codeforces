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
ll fastMin(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ x; }
ll fastMax(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int main() {
	int n, m; scanf("%d%d", &n, &m);

	map <int, vector<Pii>> e;

	FOR(i, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--; v--;
		e[w].emplace_back(u, v);
	}

	vector<int> cur(n);
	for (auto kv : e) {
		map<int, int> mp;
		for (auto ij : kv.second) {
			int u = ij.first, v = ij.second;
			mp[v] = max(mp[v],cur[u] + 1);
		}
		for (auto ij : mp) {
			cur[ij.first] = max(cur[ij.first], ij.second);
		}
	}

	int ans = *max_element(cur.begin(), cur.end());

	cout << ans << endl;

	return 0;
}