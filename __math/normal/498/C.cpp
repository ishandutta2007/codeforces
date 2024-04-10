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


struct E {
	int to, rev, cap;
	E(int to, int rev, int cap) : to(to), rev(rev), cap(cap) {}
};

const int MAX_V = 5000;
int level[MAX_V], iter[MAX_V];
vector<E> e[MAX_V];

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
		while ((f = dfs(s, t, INF)) > 0) {
			flow += f;
		}
	}
}

bool prime[1000001]; //10^6
vector<int> prs;
//f
void init_prime() {
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i < sizeof(prime); i++) if (prime[i])
		for (int j = i * 2; j < sizeof(prime); j += i) prime[j] = false;
	for (int i = 2; i < sizeof(prime); i++) if (prime[i]) prs.push_back(i);
}

map<int, int> fac(int n) {
	map<int, int> ret;
	for (auto p : prs) {
		if (p * p > n) break;
		if (n % p != 0) continue;
		int cnt = 0;
		while (n % p == 0) n /= p, cnt++;
		ret[p] = cnt;
	}
	if (n != 1) ret[n] = 1;
	return ret;
}

int main() {
	init_prime();
	int n, m; cin >> n >> m;
	vector<map<int, int> > vm;
	map<Pii, int> mp;
	int cn = 0;
	FOR(i, n) {
		int a; cin >> a;
		vm.push_back(fac(a));
		for (auto kv : vm.back()) {
			mp[Pii(i, kv.first)] = cn;
			cn++;
		}
	}
	FOR(i, m) {
		int x, y; cin >> x >> y;
		x--; y--;
		if (x & 1) swap(x, y);
		// x is even
		for (auto kv : vm[x]) {
			if (vm[y].count(kv.first)) {
				int from = mp[Pii(x, kv.first)];
				int to = mp[Pii(y, kv.first)];
				add_directed_edge(from, to, kv.second);
			}
		}
	}
	const int S = cn++;
	const int T = cn++;
	FOR(i, n) {
		for (auto kv : vm[i]) {
			if (i % 2 == 0) {
				add_directed_edge(S, mp[Pii(i, kv.first)], kv.second);
			} else {
				add_directed_edge(mp[Pii(i, kv.first)], T, kv.second);
			}
		}
	}

	int ans = max_flow(S, T);
	cout << ans << endl;
}