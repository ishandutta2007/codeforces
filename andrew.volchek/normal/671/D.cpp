#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>
#include <limits>
#include <tuple>
#include <complex>


using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = acos(-1.0l);

template<typename T>
T abs(T x) {
	return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
	return x * x;
}

template<typename T>
void chmin(T &x, T y) {
	x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
	x = max(x, y);
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
	s << "(" << x.fst << ", " << x.snd << ")";
	return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
	s << "[";
	bool was = false;
	for (auto it : x) {
		if (was) {
			s << ", ";
		}
		was = true;
		s << it;
	}
	s << "]";
	return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
	s << "{";
	bool was = false;
	for (auto it : x) {
		if (was) {
			s << ", ";
		}
		was = true;
		s << it;
	}
	s << "}";
	return s;
}

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
	for (int i = 0; i < sz; i++) {
		s << x[i];
	}
	return s;
}


//-----------------------------------------------------------------------------

const int maxn = 3e5 + 5;

struct S {
	ll delta;
	set<pair<ll, int>> s;
	map<int, ll> t;
	S() {
		delta = 0;
	}

	void insert(int id, ll cost) {
		t[id] = cost - delta;
		s.insert(mp(cost - delta, id));
	}

	void erase(int id) {
		s.erase(mp(t[id], id));
		t.erase(id);
	}

	ll getMin() {
		return delta + s.begin()->fst;
	}
};

typedef S* pS;

void merge(pS *from, pS *to) {
	if ((*from)->s.size() > (*to)->s.size()) {
		swap(*from, *to);
	}

	for (auto p : (*from)->s) {
		(*to)->insert(p.snd, p.fst + (*from)->delta);
	}

	delete *from;
}

pS a[maxn];
vector<int> bs[maxn], es[maxn];
ll cost[maxn];
vector<int> g[maxn];
ll dp[maxn];
vector<int> ch[maxn];
vector<int> order;

void dfs(int v, int pr) {
	for (int to : g[v]) {
		if (to != pr) {
			ch[v].pb(to);
			dfs(to, v);
		}
	}
	order.pb(v);
}

int main() {

	srand(1234);

#ifdef LOCAL
	freopen("a.in", "r", stdin);
	//freopen("b1.out", "w", stdout);
#endif


	int n, m;
	scanf("%d %d", &n, &m);

	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}

	for (int i = 1; i <= n; i++) {
		a[i] = new S();
	}

	for (int i = 0; i < m; i++) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		bs[u].pb(i);
		if (v == 1) {
			v = 0;
		}
		es[v].pb(i);
		cost[i] = c;
	}

	dfs(1, -1);

	for (int v : order) {
		ll sum = 0;
		for (int to : ch[v]) {
			sum += dp[to];
		}
		for (int to : ch[v]) {
			a[to]->delta += sum - dp[to];
		}

		for (int id : bs[v]) {
			a[v]->insert(id, cost[id] + sum);
		}

		for (int to : ch[v]) {
			merge(&a[to], &a[v]);
		}

		for (int id : es[v]) {
			a[v]->erase(id);
		}

		if (a[v]->s.empty()) {
			cout << -1 << endl;
			return 0;
		}

		dp[v] = a[v]->getMin();
	}

	cout << dp[1] << endl;

	return 0;
}