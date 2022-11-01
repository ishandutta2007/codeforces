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

vector<int> e[400];

bool used[400];
void dfs(int v) {
	used[v] = true;
	for (auto to : e[v]) {
		if (!used[to]) dfs(to);
	}
}

int main() {
	int n, m; cin >> n >> m;
	string rows, cols;
	cin >> rows >> cols;

	FOR(i, n) FOR(j, m) {
		if (rows[i] == '>') {
			if (j != m - 1) e[i*m + j].push_back(i*m + j + 1);
		} else {
			if (j != 0) e[i*m + j].push_back(i*m + j - 1);
		}
		if (cols[j] == 'v') {
			if (i != n - 1) e[i*m + j].push_back((i + 1)*m + j);
		} else {
			if (i != 0) e[i*m + j].push_back((i - 1)*m + j);
		}
	}

	bool ans = true;
	FOR(i, n*m) {
		memset(used, 0, sizeof(used));
		dfs(i);
		FOR(j, n*m) if (!used[j])ans = false;
	}

	puts(ans ? "YES" : "NO");

	
	return 0;
}