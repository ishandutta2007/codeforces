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
ll x[ten(5)], y[ten(5)];
int m;
int a[ten(5)], b[ten(5)];

vector<int> e[ten(5)];
int parent[20][ten(5)], depth[ten(5)];

void dfs(int v, int p, int d) {
	parent[0][v] = p;
	depth[v] = d;
	FOR(i, sz(e[v])) {
		int t = e[v][i];
		if (t != p) dfs(t, v, d + 1);
	}
}

void init() {
	for (int i = n - 1; i >= 0; i--) parent[0][i] = -2;
	for (int i = n - 1; i >= 0; i--) if (parent[0][i] == -2) dfs(i, -1, 0);
	FOR(k,19){
		FOR(i, n) {
			if (parent[k][i] < 0) parent[k + 1][i] = -1;
			else parent[k + 1][i] = parent[k][parent[k][i]];
		}
	}
}

int lca(int u, int v) {
	if (depth[u] > depth[v]) swap(u, v);
	FOR(k, 20) {
		if ((depth[v] - depth[u]) >> k & 1) {
			v = parent[k][v];
		}
	}
	if (u == v) return u;
	for (int k = 19; k >= 0; k--) {
		if (parent[k][u] != parent[k][v]) {
			u = parent[k][u];
			v = parent[k][v];
		}
	}
	return parent[0][u];
}

int main() {
	scanf("%d", &n);
	FOR(i, n) scanf("%I64d%I64d",x + i, y + i);
	scanf("%d", &m);
	FOR(i, m) scanf("%d%d", a + i, b + i);

	vector<int> sk;
	sk.push_back(n - 1);
	for(int i = n-2; i >= 0; i--){
		while (sz(sk) >= 2) {
			int a = sk[sz(sk) - 1], b = sk[sz(sk) - 2];
			if ( (y[a] - y[i]) * (x[b] - x[i]) < (y[b] - y[i]) * (x[a] - x[i])){
				sk.pop_back();
			} else {
				break;
			}
		}
		e[sk.back()].push_back(i);
		sk.push_back(i);
	}

	init();

	vector<int> ans;
	FOR(i, m) {
		int x = lca(a[i] - 1, b[i] - 1);
		ans.push_back(x + 1);
	}

	FOR(i,sz(ans)) printf("%d ",ans[i]);

	return 0;
}