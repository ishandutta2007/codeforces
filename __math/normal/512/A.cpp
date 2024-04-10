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
template<class T> void chmax(T& a, T b) { a = max(a, b); }
template<class T> void chmin(T& a, T b) { a = min(a, b); }

#pragma comment(linker,"/STACK:36777216")

typedef vector<set<int> > Graph;

bool visit(const Graph &g, int v, vector<int> &order, vector<int> &color) {
	color[v] = 1;
	for (auto to : g[v]) {
		if (color[to] == 2) continue;
		if (color[to] == 1) return false;
		if (!visit(g, to, order, color)) return false;
	}
	order.push_back(v); color[v] = 2;
	return true;
}
bool topological_sort(const Graph &g, vector<int> &order) {
	order.clear();
	int n = g.size();
	vector<int> color(n);
	for (int u = n - 1; u >= 0; u--) if (!color[u] && !visit(g, u, order, color)) return false;
	reverse(order.begin(), order.end());
	return true;
}

int main(){
	int n; cin >> n;
	vector<string> v(n);
	FOR(i, n) cin >> v[i];

	bool ok = true;
	Graph g(26);
	FOR(i, n - 1){
		for (int j = i + 1; j < n; j++) {
			int m = min(sz(v[i]), sz(v[j]));
			bool pushed = false;
			FOR(k, m){
				if (v[i][k] != v[j][k]) {
					g[v[i][k] - 'a'].insert(v[j][k] - 'a');
					pushed = true;
					break;
				}
			}
			if (!pushed) {
				if (sz(v[i]) > sz(v[j])) ok = false;
			}
			if (!ok) break;
		}
	}

	vector<int> anses;
	if (ok) {
		ok = topological_sort(g, anses);
	}

	if (!ok) {
		puts("Impossible");
	} else {
		string ans;
		FOR(i, 26) ans.push_back(anses[i] + 'a');
		cout << ans << endl;
	}

}