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
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

vector<int> e[ten(5)];

int depth[ten(5)],child[ten(5)];
int n;

int dfs(int par, int v, int dep){
	depth[v] = dep;
	int sum = 1;
	for (auto to : e[v]) {
		if (to == par) continue;
		sum += dfs(v, to, dep + 1);
	}
	return child[v] = sum;
}

int main(){
	cin >> n;
	vector<pair<Pii, int> > v;
	FOR(i, n - 1){
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		e[a].push_back(b);
		e[b].push_back(a);
		v.emplace_back(Pii(a, b), c);
	}
	dfs(-1, 0, 0);

	vector<double> cmap;
	double all = double(n) * double(n - 1) * double(n - 2) / 6;
	FOR(i, n - 1){
		Pii p = v[i].first;
		int u = depth[p.first] > depth[p.second] ? p.first : p.second;
		double a = child[u];
		double b = n - child[u];

		double use = a * b * (b - 1) + a * (a - 1) * b;
		cmap.push_back(use / all);
	}

	vector<double> costs;
	FOR(i, n - 1) costs.push_back(v[i].second);
	double ans = 0;
	FOR(i, n - 1){
		ans += cmap[i] * costs[i];
	}

	int q; cin >> q;
	FOR(i, q){
		int a, b; cin >> a >> b;
		a--;
		ans -= cmap[a] * costs[a];
		costs[a] = b;
		ans += cmap[a] * costs[a];
		printf("%.10lf\n",ans);
	}


}