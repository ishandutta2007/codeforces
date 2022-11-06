#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto x : (v))

typedef pair<int,int> pii;
typedef vector<int> vi;

struct node {
	node *l, *r;
	int ix, a, ta, b, tb, prio;

	node(int b, int ix) : l(NULL), r(NULL), ix(ix), a(0), ta(0), b(b), tb(0) {
		prio = (rand()<<16) + rand();
	}

	void push(){
		if(!ta && !tb) return;
		a += ta, b += tb;
		if(l){
			l->ta += ta;
			l->tb += tb;
		}
		if(r){
			r->ta += ta;
			r->tb += tb;
		}
		ta = 0, tb = 0;
	}
};

void split(node *t, int x, node* &l, node* &r){
	if(!t)
		l = r = NULL;
	else {
		t->push();
		if(x > t->b)
			split(t->r, x, t->r, r), l = t;
		else
			split(t->l, x, l, t->l), r = t;
	}
}

void insert(node *n, node* &t){
	if(!t)
		t = n;
	else {
		t->push();
		if(n->prio > t->prio)
			split(t, n->b, n->l, n->r), t = n;
		else
			insert(n, n->b + (rand()&1024 ? 0.5 : -0.5) > t->b ? t->r : t->l);
	}
}

void merge(node* &t, node *l, node *r){
	if(!l || !r)
		t = l ? l : r;
	else {
		l->push();
		r->push();
		if(l->prio > r->prio)
			merge(l->r, l->r, r), t = l;
		else
			merge(r->l, l, r->l), t = r;
	}
}

int main(){
	srand(312381290);
	int n;
	node *root = NULL;
	scanf("%d",&n);
	vector<pii> sh(n);
	rep(i,0,n){
		scanf("%d%d", &sh[i].second, &sh[i].first);
		sh[i].first *= -1;
	}
	sort(all(sh));
	int k;
	scanf("%d", &k);
	rep(i,0,k){
		int b;
		scanf("%d", &b);
		insert(new node(b, i), root);
	}
	trav(shirt, sh){
		int p = shirt.second;
		node *l, *r;
		split(root, p, l, r);
		if(r){
			r->ta++;
			r->tb -= p;
		}
		node *m;
		split(r, p, m, r);
		function<void(node*)> f = [&](node *t){
			if(!t)
				return;
			t->push();
			f(t->l), f(t->r);
			t->l = NULL, t->r = NULL;
			insert(t, l);
		};
		f(m);
		merge(root, l, r);
	}
	vi ans(k);
	function<void(node*)> f = [&](node *t){
		if(!t)
			return;
		t->push();
		ans[t->ix] = t->a;
		f(t->l), f(t->r);
	};
	f(root);
	trav(x, ans)
		printf("%d ", x);
	puts("");
}