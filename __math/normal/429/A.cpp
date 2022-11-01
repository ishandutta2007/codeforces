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

typedef unsigned long long ull;

int n;
vector<int> e[ten(5) + 10];
int b[ten(5) + 10];
bool used[ten(5) + 10];
vector<int> ans;

void dfs(int v, int f1,int f2) {
	used[v] = true;
	if (f1 != b[v]) {
		ans.push_back(v);
		f1 ^= 1;
	}
	for (auto p : e[v]) if (!used[p]) {
		dfs(p, f2, f1);
	}
}

int main() {

	scanf("%d", &n);
	FOR(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	FOR(i, n) {
		int x;
		scanf("%d", &x);
		b[i] = (x == 1);
	}
	FOR(i, n) {
		int x;
		scanf("%d", &x);
		b[i] ^= (x == 1);
	}

	dfs(0, 0 , 0);

	printf("%d\n", sz(ans));
	FOR(i, sz(ans)) printf("%d\n", ans[i] + 1);

	return 0;
}