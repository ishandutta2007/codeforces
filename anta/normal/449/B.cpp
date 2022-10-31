#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

struct Edge {
	int u, v, x;
};

struct State {
	long long dist;
	int v;
	int prevEdge;
	State() { }
	State(long long dist_, int v_, int e_): dist(dist_), v(v_), prevEdge(e_) { }
	bool operator>(const State &that) const {
		if(dist != that.dist) return dist > that.dist;
		return prevEdge > that.prevEdge;
	}
};

/*
s_i 



*/
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector<Edge> edges;
	rep(i, m) {
		Edge e;
		scanf("%d%d%d", &e.u, &e.v, &e.x), e.u --, e.v --;
		edges.push_back(e);
		swap(e.u, e.v);
		edges.push_back(e);
	}
	rep(i, k) {
		int s, y;
		scanf("%d%d", &s, &y), s --;
		Edge e = { 0, s, y };
		edges.push_back(e);
	}
	vector<vi> g(n);
	rep(i, edges.size())
		g[edges[i].u].push_back(i);
	priority_queue<State,vector<State>,greater<State> > q;
	q.push(State(0, 0, -1));
	vector<bool> vis(n, false);
	vector<int> prevEdge(n, -1);
	while(!q.empty()) {
		State s = q.top(); q.pop();
		if(vis[s.v]) continue;
		vis[s.v] = true;
		prevEdge[s.v] = s.prevEdge;
		each(j, g[s.v]) {
			const Edge &e = edges[*j];
			q.push(State(s.dist + e.x, e.v, *j));
		}
	}
	int ans = 0;
	reu(i, m * 2, edges.size()) {
		const Edge &e = edges[i];
		assert(e.u == 0);
		ans += prevEdge[e.v] != i;
	}
	printf("%d\n", ans);
	return 0;
}