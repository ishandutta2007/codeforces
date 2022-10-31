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

typedef char Val;
struct Node {
	int priority;
	Node *ch[2];
	Val val; int size;
	Node(Val v, int p)
		: priority(p)
		, val(v), size(1) { ch[0] = ch[1] = NULL; }
};
Val val(Node *x) { assert(x); return x->val; }
int size(Node *x) { return !x ? 0 : x->size; }

Node *update(Node *x) {
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
//split([0,k) , [k,n))
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
Node *singleton(Val val) { return update(new Node(val, rand())); }

string ans;
void traverse(Node *t) {
	if(!t) return;
	traverse(t->ch[0]);
	ans += t->val;
	traverse(t->ch[1]);
}

int a[1000000];
int main() {
	int n, Q;
	scanf("%d%d", &Q, &n);
	rep(i, n) {
		scanf("%d", &a[i]);
		a[i] --;
	}
	Node *t = NULL;
	int w = 0;
	rep(ii, Q) {
		int q;
		scanf("%d", &q);
		if(q != -1) {
			t = merge(t, singleton(char('0' + q)));
			w ++;
		}else {
			int x = upper_bound(a, a+n, w-1) - a;
			rep(i, x) {
				auto p = split(t, a[i] - i);
				auto q = split(p.second, 1);
				delete q.first;
				t = merge(p.first, q.second);
			}
			w -= x;
		}
	}
	traverse(t);
	if(ans.empty()) puts("Poor stack!");
	else puts(ans.c_str());
	return 0;
}