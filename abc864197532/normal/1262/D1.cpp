#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second
#define MAXN 200000

bool cmp (pii a, pii b) {
    if (a.X != b.X) return a.X > b.X;
    return a.Y < b.Y;
}
struct Treap {
	Treap *l, *r;
	int pri, key;
	int sz;
	Treap (int _key) {
		key = _key;
		l = r = NULL;
		pri = rand();
		sz = 1;
	}
};

inline sz(Treap *t) {
	return t ? t -> sz : 0;
}

inline void pull (Treap *t) {
	t->sz = sz(t -> l) + 1 + sz(t -> r);
}

Treap* merge(Treap *a, Treap *b) {
	if (!a or !b) return a ? a : b;
	if (a->pri > b->pri) {
		a -> r = merge(a -> r, b);
		pull(a);
		return a;
	} else {
		b -> l = merge(a, b -> l);
		pull(b);
		return b;
	}
}

void spilt(Treap* t, int x, Treap *&a, Treap *&b) {
	if (!t) a = b = NULL;
	else if (t->key <= x) {
		a = t;
		spilt(t->r, x, a->r, b);
		pull(a);
	} else {
		b = t;
		spilt(t->l, x, a, b->l);
		pull(b);
	}
}

int kth(Treap *t, int k) {
	int lsz = sz(t->l) + 1;
	if (lsz < k) return kth(t->r, k - lsz);
	else if (lsz == k) return t->key;
	else return kth(t->l, k);
}

Treap* insert(Treap* t, int k) {
	Treap *tl, *tr;
	spilt(t, k, tl, tr);
	return merge(tl, merge(new Treap(k), tr));
}

int main () {
    int n, m, a, b;
    cin >> n;
    pii input[n];
    int back[n];
    fop (i,0,n) {
        cin >> input[i].X;
        back[i] = input[i].X;
        input[i].Y = i;
    }
    sort(input, input + n, cmp);
    vector <pair <pii, int>> query;
    cin >> m;
    fop (i,0,m) {
        cin >> a >> b;
        query.pb({{a, b}, i});
    }
    sort(query.begin(), query.end());
    Treap* t = NULL;
    int ans[m], now = 0;
    fop (i,0,m) {
        while (now < n and now < query[i].X.X) {
            t = insert(t, input[now].Y);
            now++;
        }
        ans[query[i].Y] = kth(t, query[i].X.Y);
    }
    fop (i,0,m) cout << back[ans[i]] << '\n';
}