#include <bits/stdc++.h>
using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()

const int N = 1e3 + 10; 
const int M = 5e5 + 10000;

struct Edge {
	int v, u, c;
	Edge() { }
	Edge(int v, int u, int c): v(v), u(u), c(c) { }
	void read() {
		scanf("%d%d%d", &v, &u, &c); v--; u--;
	}
};

int n, q, m;
Edge edge[N * N];
vector < int > tree[M * 4]; 
pair < int, int > query[N];
int tmr;
pair < int, int > p[N];
int ver[N];

struct cmpE {
	bool operator () (int a, int b) {
		return edge[a].c > edge[b].c;
	}
};

pair < int, int > getId(int v) {
	if (ver[v] != tmr) {
		ver[v] = tmr;
		p[v] = mp(v, 0);
	}
	if (p[v].fr == v) return mp(v, 0);
	auto x = getId(p[v].fr);
	p[v] = mp(x.fr, (x.sc + p[v].sc) % 2);
	return p[v];
}

vector < int > go(vector < int > & e, bool & ok) {
	tmr++;
	vector < int > res;
	for (int i = 0; i < (int)e.size(); i++) {
		int id = e[i];
		int v = edge[id].v;
		int u = edge[id].u;
		auto x = getId(v);
		auto y = getId(u);
		if (x.fr != y.fr) {
			res.pb(id);
			p[x.fr] = mp(y.fr, (x.sc + y.sc + 1) % 2);
		}
		else {
			if (y.sc == x.sc) {
				res.pb(id);
				ok = 0;
				return res;
			}
		}
	}
	ok = 1;
	return res;
}


void build(int v, int ll, int rr) {
	if (ll + 1 == rr) {
		tree[v].pb(ll);
		return;
	}
	build(v * 2 + 1, ll, (ll + rr) / 2);
	build(v * 2 + 2, (ll + rr) / 2, rr);

	tree[v].resize(rr - ll);
	merge(all(tree[v * 2 + 1]), all(tree[v * 2 + 2]), tree[v].begin(), cmpE());
		
	bool flag = 0;
	tree[v] = go(tree[v], flag);
}

void read() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; i++) {
		edge[i].read();
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d%d", &l, &r); l--;
		query[i] = mp(l, r);
	}
}

vector < int > tmp;

void get(int v, int ll, int rr, int l, int r) {
	if (l >= rr || ll >= r) return;
	if (l <= ll && rr <= r) {
		tmp.insert(tmp.end(), all(tree[v]));
		return;
	}
	get(v * 2 + 1, ll, (ll + rr) / 2, l, r);
	get(v * 2 + 2, (ll + rr) / 2, rr, l, r);
}

void solve() {
	build(0, 0, m);

	for (int i = 0; i < q; i++) {
		int l, r;
		l = query[i].fr;
		r = query[i].sc;
		tmp.clear();
		get(0, 0, m, l, r);
		sort(all(tmp), cmpE());
		bool flag = 0;
		auto res = go(tmp, flag);
		if (flag){
			puts("-1");
		}
		else {
			assert(!res.empty());
			printf("%d\n", edge[res.back()].c);
		}
	}

}

int main(){
 	read();
	solve();
}