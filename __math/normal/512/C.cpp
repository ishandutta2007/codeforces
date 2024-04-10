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

struct E {
	int to, rev, cap;
	E(int to, int rev, int cap) : to(to), rev(rev), cap(cap) {}
};

const int MAX_V = 1000;
int level[MAX_V], iter[MAX_V];
vector<E> e[MAX_V];

void add_undirected_edge(int f, int t, int c) {
	e[f].push_back(E(t, sz(e[t]), c));
	e[t].push_back(E(f, sz(e[f]) - 1, c));
}

void add_directed_edge(int f, int t, int c) {
	e[f].push_back(E(t, sz(e[t]), c));
	e[t].push_back(E(f, sz(e[f]) - 1, 0));
}

void bfs(int s) {
	memset(level, -1, sizeof(level));
	queue<int> q;
	level[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (auto t : e[v]) {
			if (t.cap > 0 && level[t.to] < 0) {
				level[t.to] = level[v] + 1;
				q.push(t.to);
			}
		}
	}
}

int dfs(int v, int t, int f) {
	if (v == t) return f;
	for (int &i = iter[v]; i < sz(e[v]); i++) {
		E& _e = e[v][i];
		if (_e.cap > 0 && level[v] < level[_e.to]) {
			int d = dfs(_e.to, t, min(f, _e.cap));
			if (d > 0) {
				_e.cap -= d;
				e[_e.to][_e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t) {
	int flow = 0;
	while (true) {
		bfs(s);
		if (level[t] < 0) return flow;
		memset(iter, 0, sizeof(iter));
		int f;
		while ((f = dfs(s, t, ten(8))) > 0) {
			flow += f;
		}
	}
}

bool prime[1000001]; //10^6

//f
void init_prime()
{
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i < sizeof(prime); i++) if (prime[i])
		for (int j = i * 2; j < sizeof(prime); j += i) prime[j] = false;
}

vector<int> used_edge[1000];
bool used_dfs[1000];

void dfs(int v,vector<int>& ret){
	ret.push_back(v);
	used_dfs[v] = true;
	for (auto to : used_edge[v]) {
		if (!used_dfs[to]) dfs(to, ret);
	}
}

vector<vector<int> > solve(vector<int>& a){
	const int n = sz(a);

	int odd = 0, even = 0, one = 0;
	for (auto i : a) {
		if (i == 1) one++;
		if (i % 2 == 0) even++;
		else odd++;
	}

	vector<Pii> odds, evens, ones;
	FOR(i, n) if (a[i] % 2 == 0) evens.push_back(Pii(i, a[i]));
	FOR(i, n) if (a[i] % 2 == 1) {
		if (a[i] != 1) {
			odds.push_back(Pii(i, a[i]));
		} else {
			if (sz(evens) > sz(odds)) odds.push_back(Pii(i, a[i]));
			else ones.push_back(Pii(i, a[i]));
		}
	}

	vector<vector<int> > ret;
	if (sz(odds) != sz(evens)) return vector<vector<int> >();
	if (1 <= sz(ones) && sz(ones) <= 2) return vector<vector<int> >();
	if (sz(ones) != 0) {
		ret.emplace_back();
		for (auto kv : ones) ret.back().push_back(kv.first);
	}

	const int src = sz(odds) + sz(evens);
	const int dest = src + 1;

	FOR(i, sz(odds)) FOR(j, sz(evens)){
		if (prime[odds[i].second + evens[j].second]) {
			add_directed_edge(odds[i].first, evens[j].first, 1);
		}
	}

	for (auto kv : odds) {
		add_directed_edge(src, kv.first, 2);
	}
	for (auto kv : evens) {
		add_directed_edge(kv.first, dest, 2);
	}

	int flow = max_flow(src, dest);
	if (flow != sz(odds) * 2) return vector<vector<int> >();

	for (auto kv : odds) {
		for (auto& edge : e[kv.first]) {
			if (edge.to == src) continue;
			if (edge.cap == 0) {
				//used edge
				used_edge[kv.first].push_back(edge.to);
				used_edge[edge.to].push_back(kv.first);
			}
		}
	}

	for (auto kv : odds) {
		int v = kv.first;
		if (!used_dfs[v]) {
			ret.emplace_back();
			dfs(v, ret.back());
		}
	}

	for (auto& x : ret) {
		FOR(i, sz(x)){
			int b = x[i];
			int c = x[(i+1) % sz(x)];
			// printf("a[%d] + a[%d] = %d\n",b + 1,c + 1, a[b]+a[c]);
			assert(a[b] + a[c]);
		}
	}

	return ret;
}

int main(){
	init_prime();

	int n; cin >> n;
	vector<int> a(n);
	FOR(i, n) cin >> a[i];

	auto ans = solve(a);
	if (sz(ans) == 0) {
		cout << "Impossible" << endl;
	} else {
		cout << sz(ans) << endl;
		for (auto& x : ans) {
			printf("%d ",sz(x));
			FOR(i, sz(x)) printf("%d%c",x[i] + 1,i==sz(x)-1?'\n':' ');
		}
	}
}