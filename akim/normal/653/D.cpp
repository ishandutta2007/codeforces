#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <utility>
#include <iomanip>

using namespace std;

struct edge {
	long long a, b, f, c;
};

const long long inf = 1000 * 1000 * 1000;
const long long MAXN = 1050;

long long ia[MAXN], ib[MAXN], ic[MAXN];

long long n, m, x;
vector <edge> e;
long long pt[MAXN];
vector <long long> g[MAXN];
long long flow = 0;
queue <long long> q;
long long d[MAXN];
long long lim;
long long s, t;

void add_edge(long long a, long long b, long long c) {
	edge ed;

	//keep edges in vector: e[ind] - direct edge, e[ind ^ 1] - back edge

	ed.a = a; ed.b = b; ed.f = 0; ed.c = c;
	g[a].push_back(e.size());
	e.push_back(ed);

	ed.a = b; ed.b = a; ed.f = c; ed.c = c;
	g[b].push_back(e.size());
	e.push_back(ed);
}

bool bfs() {
	for (long long i = s; i <= t; i++)
		d[i] = inf;
	d[s] = 0;
	q.push(s);
	while (!q.empty() && d[t] == inf) {
		long long cur = q.front(); q.pop();
		for (size_t i = 0; i < g[cur].size(); i++) {
			long long id = g[cur][i];
			long long to = e[id].b;

			//prlong longf("cur = %d id = %d a = %d b = %d f = %d c = %d\n", cur, id, e[id].a, e[id].b, e[id].f, e[id].c);

			if (d[to] == inf && e[id].c - e[id].f >= lim) {
				d[to] = d[cur] + 1;
				q.push(to);
			}
		}
	}
	while (!q.empty())
		q.pop();
	return d[t] != inf;
}

bool dfs(long long v, long long flow) {
	if (flow == 0)
		return false;
	if (v == t) {
		//cout << v << endl;
		return true;
	}
	for (; pt[v] < g[v].size(); pt[v]++) {
		long long id = g[v][pt[v]];
		long long to = e[id].b;

		//prlong longf("v = %d id = %d a = %d b = %d f = %d c = %d\n", v, id, e[id].a, e[id].b, e[id].f, e[id].c);

		if (d[to] == d[v] + 1 && e[id].c - e[id].f >= flow) {
			long long pushed = dfs(to, flow);
			if (pushed) {
				e[id].f += flow;
				e[id ^ 1].f -= flow;
				return true;
			}
		}
	}
	return false;
}

void dinic() {
	for (lim = (1 << 30); lim >= 1;) {
		if (!bfs()) {
			lim >>= 1;
			continue;
		}

		for (long long i = s; i <= t; i++)
			pt[i] = 0;

		long long pushed;

		while (pushed = dfs(s, lim)) {
			flow = flow + lim;
		}

		//cout << flow << endl;
	}
}

long long main2(double sz) {

	e.clear();
	flow = 0;
	while(!q.empty()) q.pop();
	for(long long i = 0; i < MAXN; i++) {
		d[i] = 0;
		pt[i] = 0;
		g[i].clear();
	}
	lim = 0;

	s = 1; t = n;

	for (long long i = 0; i < m; i++) {
		long long a, b, c;
		a = ia[i];
		b = ib[i];
		c = (long long)((ic[i] * 1.) / sz);
//		scanf("%d %d %d", &a, &b, &c);
		add_edge(a, b, c);
//		cout << c << endl;
	}

	dinic();

	return flow;
}

int main() {
	scanf("%d%d%d", &n, &m, &x);
	for(long long i = 0; i < m; i++) {
		scanf("%d%d%d", &ia[i], &ib[i], &ic[i]);
	}

//	cout << main2(0.44444443);

//	return(0);

	double l = 0., r = 10000000.;
	for(long long i = 0; i < 150; i++) {
		double m = (l + r) / 2.;
		if(main2(m) >= x) {
			l = m;
		} else {
			r = m;
		}
	}
//	prlong longf("%.10lf\n", l);
	printf("%.10lf", l * x);

}