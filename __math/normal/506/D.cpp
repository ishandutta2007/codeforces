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
const int C = ten(5) + 10;

vector<int> e[C];
bool used[C];

void add_edge(int a, int b){
	e[a].push_back(b); e[b].push_back(a);
}
void rem_edge_and_rem_used(int a, int b){
	e[a].pop_back(); e[b].pop_back();
	used[a] = false; used[b] = false;
}

vector<int> grp;
void dfs(int v){
	used[v] = true;
	grp.push_back(v);
	for (auto to : e[v]) if (!used[to]) dfs(to);
}

#include <unordered_set>

int main(){
	int n, m; scanf("%d%d", &n, &m);
	static vector<Pii> vc[C];
	FOR(i, m){
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		a--; b--; c--;
		vc[c].push_back(Pii(a, b));
	}

	vector<vector<int> > unis;

	FOR(i, ten(5)) if (sz(vc[i])) {
		//add
		for (auto& kv : vc[i]) add_edge(kv.first, kv.second);
		for (auto& kv : vc[i]) {
			if (!used[kv.first]) {
				grp.clear();
				dfs(kv.first);
				unis.push_back(grp);
			}
		}
		//rem
		for (auto& kv : vc[i]) rem_edge_and_rem_used(kv.first, kv.second);
	}

	const int K = 100;

	static vector<int> mp[C];
	vector<vector<int> > x;

	for (auto& gp : unis) {
		if (sz(gp) < K) {
			FOR(i, sz(gp)) for (int j = i + 1; j < sz(gp); j++) {
				int u = gp[i], v = gp[j];
				if (u > v) swap(u, v);
				mp[u].push_back(v);
			}
		} else {
			x.push_back(gp);
		}
	}
	FOR(i, C) sort(mp[i].begin(), mp[i].end());
	for (auto& a : x) sort(a.begin(), a.end());

	int q; scanf("%d", &q);
	FOR(i, q){
		int a, b; scanf("%d%d", &a, &b);
		a--; b--;
		if (a > b) swap(a, b);
		auto pr = equal_range(mp[a].begin(), mp[a].end(), b);
		int ans = pr.second - pr.first;
		for (auto& v : x) {
			if (binary_search(v.begin(), v.end(), a) &&
				binary_search(v.begin(), v.end(), b))
				ans++;
		}
		printf("%d\n", ans);
	}


}