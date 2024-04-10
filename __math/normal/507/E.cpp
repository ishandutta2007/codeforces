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

struct Q {
	int cost;
	int worked;
	Q(int cost, int worked) : cost(cost), worked(worked){}
	Q(){}
	bool operator<(const Q& l) const {
		if (cost != l.cost) return cost < l.cost;
		return worked > l.worked;
	}
	bool operator>(const Q& l) const {
		if (cost != l.cost) return cost > l.cost;
		return worked < l.worked;
	}
	};

typedef Q cost_type;

struct edge {
	int to;
	cost_type cost;
	edge(){}
	edge(int to, cost_type cost) : to(to), cost(cost) {}
};

typedef pair<cost_type, int> P;

void dijkstra(int s, vector<P::first_type>& cost_table, vector<vector<edge> >& edges, vector<int>* _prev = NULL){

	//init
	cost_table.resize((int)edges.size());
	fill(cost_table.begin(), cost_table.end(), Q(ten(8),0));
	if (_prev) _prev->resize((int)edges.size());
	if (_prev) fill(_prev->begin(), _prev->end(), -1);

	priority_queue<P, vector<P>, greater<P> > q;
	q.push(P(Q(0,0), s));
	cost_table[s] = Q(0, 0);

	while (!q.empty()) {
		P p = q.top(); q.pop();
		int v = p.second;
		if (cost_table[v] < p.first) continue;
		for (int i = 0; i < (int)edges[v].size(); i++) {
			edge& e = edges[v][i];
			Q ncost(p.first.cost + e.cost.cost, p.first.worked + e.cost.worked);
			if (cost_table[e.to] > ncost) {
				cost_table[e.to] = ncost;
				if (_prev) (*_prev)[e.to] = v;
				q.push(P(cost_table[e.to], e.to));
			}
		}
	}
}

void get_path(int t, vector<int>& prev, vector<int>& path){
	for (; t != -1; t = prev[t]) path.push_back(t);
	reverse(path.begin(), path.end());
}

int main(){
	int n, m; scanf("%d%d", &n, &m);
	map<Pii, int> mp;
	FOR(i, m){
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		x--; y--;
		mp[Pii(x, y)] = z;
	}

	vector<P::first_type> costs;
	vector<vector<edge> > edges(n);
	for (auto kv : mp) {
		edges[kv.first.first].push_back(edge(kv.first.second, Q(1, kv.second)));
		edges[kv.first.second].push_back(edge(kv.first.first, Q(1, kv.second)));
	}
	vector<int> prev;
	dijkstra(0, costs, edges, &prev);
	vector<int> path;
	get_path(n - 1, prev, path);

	set<Pii> used_uv;
	FOR(i, sz(path) - 1){
		used_uv.insert(Pii(path[i], path[i + 1]));
		used_uv.insert(Pii(path[i + 1], path[i]));
	}

	vector<tuple<int,int,int> > anses;
	for (auto kv : mp) {
		int o = used_uv.count(kv.first) ^ kv.second;
		if (o) {
			anses.emplace_back(kv.first.first, kv.first.second, kv.second ^ 1);
		}
	}

	printf("%d\n", sz(anses));
	for (auto abc : anses) {
		int a, b, c; tie(a, b, c) = abc;
		printf("%d %d %d\n", a + 1, b + 1, c);
	}
}