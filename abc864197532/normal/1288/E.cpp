#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fop(i,m,n) for (int i = (m); i < (n); ++i)

struct Treap {
	Treap *l, *r;
	pii key;
	int pri, sz;
	Treap (pii _key) {
		key = _key;
		l = r = NULL;
		pri = rand();
		sz = 1;
	}
};

int size(Treap* t) {return t ? t->sz : 0;}
void pull(Treap* t) {t->sz = size(t->l) + 1 + size(t->r);}

Treap* merge(Treap* a, Treap* b) {
	if (!a or !b) return a ? a : b;
	else if (a->pri > b->pri) {
		a->r = merge(a->r, b);
		pull(a);
		return a;
	} else {
		b->l = merge(a, b->l);
		pull(b);
		return b;
	}
}

void split(Treap* t, pii k, Treap* &a, Treap* &b) {
	if (!t) a = b = NULL;
	else if (t->key <= k) {
		a = t;
		split(t->r, k, a->r, b);
		pull(a);
	} else {
		b = t;
		split(t->l, k, a, b->l);
		pull(b);
	}
}

Treap* insert(Treap* t, pii k) {
	Treap *tl, *tr;
	split(t, k, tl, tr);
	return merge(tl, merge(new Treap(k), tr));
}

Treap* remove(Treap* t, pii k) {
	Treap *tl, *tr;
	split(t, {k.first, k.second - 1}, tl, t);
	split(t, k, t, tr);
	return merge(tl, tr);
}

pii kth(Treap* t, int k) {
	if (size(t->l) + 1 < k) {
		return kth(t->r, k - size(t->l) - 1);
	} else if (size(t->l) == k) {
		return t->key;
	} else {
		return kth(t->l, k);
	}
}

int index(Treap* t, pii x) {
    if (!t) return -1;
	if (t->key > x) {
		return index(t->l, x);
	} else if (t->key == x) {
		return size(t->l);
	} else {
	    int k = index(t->r, x);
	    return k == -1 ? -1 : size(t->l) + 1 + k;
	}
}

int main () {
	srand(time(NULL));
	int n,m,tmp;
	cin >> n >> m;
	Treap* t = new Treap({m, 0});
	int minn[n], maxx[n], last[n];
	minn[0] = maxx[0] = 0;
	last[0] = m;
	fop (i,1,n) {
	    t = insert(t, {i + m, i});
	    minn[i] = maxx[i] = i;
	    last[i] = i + m;
	}
	fop (i,0,m) {
	    cin >> tmp;
	    tmp--;
	    minn[tmp] = 0;
	    maxx[tmp] = max(maxx[tmp], index(t, {last[tmp], tmp}));
	    t = remove(t, {last[tmp], tmp});
	    last[tmp] = m - i - 1;
	    t = insert(t, {last[tmp], tmp});
	}
	fop (i,0,n) {
	    maxx[i] = max(maxx[i], index(t, {last[i], i}));
	}
	fop (i,0,n) cout << minn[i] + 1 << ' ' << maxx[i] + 1 << endl;
}