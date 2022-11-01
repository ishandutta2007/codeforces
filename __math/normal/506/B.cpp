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

const int MAX_V = ten(5) + 1;
int n;
vector<int> e[MAX_V],re[MAX_V];
vector<int> vs;
bool used[MAX_V];
int color[MAX_V];

void dfs(int v) {
	used[v] = true;
	for(auto i : e[v]) if (!used[i]) {
		dfs(i);
	}
	vs.push_back(v);
}
void rdfs(int v, int k) {
	used[v] = true;
	color[v] = k;
	for (auto i : re[v]) if (!used[i]) {
		rdfs(i, k);
	}
}

int scc() {
	memset(used, 0, sizeof(used));
	FOR(v, n) if (!used[v]) dfs(v);
	memset(used, 0, sizeof(used));
	int k = 0;
	for (int i = vs.size() - 1; i >= 0; i--) {
		if (!used[vs[i]]) rdfs(vs[i], k++);
	}
	return k;
}

bool used2[MAX_V];
vector<int> e2[MAX_V];
void dfs2(int v, vector<int>& ret){
	used2[v] = true;
	ret.push_back(v);
	for (auto to : e2[v]) {
		if (!used2[to]) dfs2(to, ret);
	}
}

int main(){
	int m; scanf("%d%d", &n, &m);
	vector<Pii> es;
	FOR(i, m){
		int a, b; scanf("%d%d", &a, &b);
		a--; b--;
		e[a].push_back(b);
		re[b].push_back(a);
		es.emplace_back(a, b);
	}
	int colors = scc();
	vector<vector<int>> cs(colors);
	FOR(i, n) cs[color[i]].push_back(i);
	static set<int> e22[MAX_V];

	for (auto kv : es) {
		int a = color[kv.first];
		int b = color[kv.second];
		e22[a].insert(b);
		e22[b].insert(a);
	}
	FOR(i, colors) e2[i].insert(e2[i].begin(), e22[i].begin(), e22[i].end());

	int ans = 0;
	FOR(i, colors){
		if (used2[i]) continue;
		vector<int> r;
		dfs2(i, r);
		int pts = 0;
		for (auto v : r) pts += sz(cs[v]);
		if (sz(r) == pts) ans += pts - 1;
		else ans += pts;
	}

	cout << ans << endl;
}