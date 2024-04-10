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

vector<vector<int>> anses;
vector<int> cur;

map<int, vector<int> > mp;
void dfs(map<int, vector<int> >::iterator it) {
	if (it == mp.end()) {
		anses.push_back(cur);
		return;
	}
	do {
		if (sz(anses) >= 3) return;
		for (auto i : it->second) cur.push_back(i);
		auto it2 = it;
		it2++;
		dfs(it2);
		for (auto i : it->second) cur.pop_back();
	}
	while (next_permutation(it->second.begin(), it->second.end()));
}

int main() {
	int n; cin >> n;
	vector<int> h(n);
	FOR(i, n) cin >> h[i];
	FOR(i, n) mp[h[i]].push_back(i+1);

	dfs(mp.begin());
	if (sz(anses) < 3) {
		puts("NO");
	} else {
		puts("YES");
		FOR(i, 3) {
			FOR(j, n) {
				printf("%d%c",anses[i][j],j==n-1?'\n':' ');
			}
		}
	}

}