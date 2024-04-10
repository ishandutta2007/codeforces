#include <bits/stdc++.h>

using namespace std;

struct node
{
    node* L, *R;
    int x, y, sz;
    node(int x) : x(x)
    {
        y = rand();
        sz = 1;
        L = R = 0;
    }
};

typedef node* treap;

int sz(treap t) { return t ? t->sz : 0; }
void recalc(treap t) { if(t) t->sz = 1 + sz(t->L) + sz(t->R); }

void merge(treap L, treap R, treap &T)
{
    if (!L || !R) { T = L ? L : R; return; }
    if (L->y > R->y) { merge(L->R, R, L->R); T = L; }
    else { merge(L, R->L, R->L); T = R; }
    recalc(T);
}

void split(treap T, treap& L, treap &R, int key)
{
    if (!T) { L = R = 0; return; }
    if (T->x < key) { split(T->R, T->R, R, key); L = T; }
    else { split(T->L, L, T->L, key); R = T; }
    recalc(T);
}

void insert(treap& t, int key)
{
    treap l, r;
    split(t, l, r, key);
    merge(l, new node(key), l);
    merge(l, r, t);
}

int count(treap& T, int l, int r)
{
    treap L, M, R;
    split(T, L, M, l);
    split(M, M, R, r + 1);
    int ans(sz(M));
    merge(L, M, M);
    merge(M, R, T);
    return ans;
}

map<int, treap> mp;

struct pt { int x, r, q; };

bool operator<(pt a, pt b) { return a.r < b.r; }

typedef
long long ll;

void test()
{
    treap tr = 0;
    while (true)
    {
        int t;
        cin >> t;
        if (t) {
            int l, r; cin >> l >> r;
            cout << count(tr, l, r) << endl;
        } else {
            int x; cin >> x; insert(tr, x);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<pt> a(n);
    for (pt& p : a) cin >> p.x >> p.r >> p.q;
    sort(a.rbegin(), a.rend());
    ll sum = 0;
    for (pt& p : a)
    {
        for (int q(p.q - k); q <= p.q + k; ++q)
            if (mp.count(q))
                sum += count(mp[q], p.x - p.r, p.x + p.r);
        if (!mp.count(p.q)) mp[p.q] = 0;
        insert(mp[p.q], p.x);
    }
    cout << sum;
}