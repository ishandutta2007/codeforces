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
#include <list>
#include <cassert>
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
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

unsigned xor128() {
	static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}

typedef pii Val;
struct Node {
	unsigned priority;
	Node *ch[2];
	Val val; int size;
	//
	Node(Val v, unsigned p)
		: priority(p)
		, val(v), size(1) { ch[0] = ch[1] = NULL; }
};
int size(Node *x) { return !x ? 0 : x->size; }
Node *update(Node *x) {
	//
	if(!x) return x;
	x->size = size(x->ch[0]) + 1 + size(x->ch[1]);
	return x;
}
Node *link(Node *x, Node *c, bool b) {
	x->ch[b] = c; return update(x);
}
Node *merge(Node *x, Node *y) {
	x = update(x); y = update(y);
	if(!x || !y) return x ? x : y;
	if(x->priority < y->priority) {
		return link(x, merge(x->ch[1], y), 1);
	}else {
		return link(y, merge(x, y->ch[0]), 0);
	}
}
typedef pair<Node*, Node*> NPair;
NPair split(Node *t, int k) {
	if(!update(t)) return mp((Node*)NULL, (Node*)NULL);
	if(size(t->ch[0]) < k) {
		NPair u = split(t->ch[1], k - size(t->ch[0]) - 1);
		return mp(link(t, u.first, 1), u.second);
	}else {
		NPair u = split(t->ch[0], k);
		return mp(u.first, link(t, u.second, 0));
	}
}
Node *singleton(Val val) { return update(new Node(val, xor128())); }

int lowerbound(Node *t, Val x) {
	if(!update(t)) return 0;
	if(x <= t->val) {
		return lowerbound(t->ch[0], x);
	}else {
		return size(t->ch[0]) + 1 + lowerbound(t->ch[1], x);
	}
}
Node *insert(Node *t, Val x) {
	int k = lowerbound(t, x);
	NPair p = split(t, k);
	return merge(p.first, merge(singleton(x), p.second));
}

//erase
Node *erase(Node *t, Val x) {
	int k = lowerbound(t, x);
	NPair p = split(t, k);
	NPair q = split(p.second, 1);
	assert(q.first->val == x);	//
	delete q.first;
	return merge(p.first, q.second);
}

int col[100000];
vector<vi> g;
int number[100000];
int vertices[100000];
int numbers;
vector<pair<int,pii> > queries;
int parents[100000];
Node *ts[100000];
int rights[100000];
int ans[100000];
map<int,int> cs[100000];

void dfs(int i, int parent) {
	vertices[numbers] = i;
	number[i] = numbers ++;
	parents[i] = parent;
	each(j, g[i]) if(*j != parent)
		dfs(*j, i);
	rights[i] = numbers;
}
Node *inserts(Node *x, Node *y, map<int,int> &xa) {
	if(!y) return x;
	x = inserts(x, y->ch[0], xa);
	int c = y->val.second;
	if(xa.count(c)) {
		x = erase(x, mp(xa[c], c));
		x = insert(x, mp(xa[c] + y->val.first, c));
	}else {
		x = insert(x, y->val);
	}
	x = inserts(x, y->ch[1], xa);
	delete y;
	return x;
}
Node *mergetech(Node *x, Node *y, map<int,int> &xa, map<int,int> &ya) {
	if(size(x) < size(y))
		return inserts(y, x, ya);
	else
		return inserts(x, y, xa);
}
void mergetech2(map<int,int> &x, map<int,int> &y) {
	if(x.size() < y.size()) {
		mergetech2(y, x);
		y.swap(x);
		return;
	}
	each(i, y)
		x[i->first] += i->second;
	y.clear();
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%d", &col[i]);
	g.assign(n, vi());
	rep(i, n-1) {
		int a, b;
		scanf("%d%d", &a, &b);
		a --, b --;
		g[a].pb(b);
		g[b].pb(a);
	}
	numbers = 0;
	dfs(0, -1);
	queries.resize(m);
	rep(i, m) {
		int v, k;
		scanf("%d%d", &v, &k);
		v --;
		queries[i] = mp(number[v], mp(k, i));
	}
	sort(all(queries));
	reverse(all(queries));
	int qi = 0;
	for(int ii = n-1; ii >= 0; ii --) {
		int v = vertices[ii];
		int c = col[v];
		int x;
		if(!cs[v].count(c)) {
			x = 0;
		}else {
			x = cs[v][c];
			pii old = mp(x, c);
			ts[v] = erase(ts[v], old);
		}
		cs[v][c] ++;
		ts[v] = insert(ts[v], mp(cs[v][c], c));

		while(qi < m && queries[qi].first == ii) {
			int k = queries[qi].second.first;
			int l = lowerbound(ts[v], mp(k-1, INF));
			ans[queries[qi].second.second] = size(ts[v]) - l;
			qi ++;
		}

		if(parents[v] != -1) {
			ts[parents[v]] = mergetech(ts[parents[v]], ts[v], cs[parents[v]], cs[v]);
			mergetech2(cs[parents[v]], cs[v]);
		}
	}
	rep(i, m) printf("%d\n", ans[i]);
	return 0;
}