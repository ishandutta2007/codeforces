#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

struct treap
{
    treap *l, *r;
    int x, y;
    ll push;
    ll dist;
    ll mn;
    treap(int x): x(x), y((rand() << 16) + rand()), dist(1e18), mn(1e18), push(1e18), l(0), r(0) {}
    treap() {}
};


void push(treap *t)
{
    if (!t)
    {
        return;
    }
    if (t->l)
    {
        t->l->dist = min(t->l->dist, t->push);
        t->l->mn = min(t->l->mn, t->push);
        t->l->push = min(t->l->push, t->push);
    }
    if (t->r)
    {
        t->r->dist = min(t->r->dist, t->push);
        t->r->mn = min(t->r->mn, t->push);
        t->r->push = min(t->r->push, t->push);
    }
    t->push = 1e18;
}


void recalc(treap *t)
{
    push(t);
    if (!t)
    {
        return;
    }
    t->mn = t->dist;
    if (t->l)
    {
        t->mn = min(t->mn, t->l->mn);
    }
    if (t->r)
    {
        t->mn = min(t->mn, t->r->mn);
    }
}

pair <treap *, treap *> split(treap *t, int x)
{
    if (!t)
    {
        return {0, 0};
    }
    if (x < t->x)
    {
        recalc(t);
        auto a = split(t->l, x);
        t->l = a.second;
        recalc(t->l);
        recalc(a.first);
        recalc(t);
        return {a.first, t};
    }
    else
    {
        recalc(t);
        auto a = split(t->r, x);
        t->r = a.first;
        recalc(t->r);
        recalc(a.second);
        recalc(t);
        return {t, a.second};
    }
}

treap *merge(treap *l, treap *r)
{
    recalc(l), recalc(r);
    if (!l)
    {
        return r;
    }
    if (!r)
    {
        return l;
    }
    if (l->y > r->y)
    {
        l->r = merge(l->r, r);
        recalc(l->r);
        recalc(l);
        return l;
    }
    else
    {
        r->l = merge(l, r->l);
        recalc(r->l);
        recalc(r);
        return r;
    }
}

struct edge
{
    int l, r;
    ll w;
};

void relax(treap *&t, int l, int r, ll x)
{
    auto a = split(t, r); 
    auto b = split(a.first, l - 1);
    if (b.second)
    {
        b.second->dist = min(b.second->dist, x);
        b.second->mn = min(b.second->mn, x);
        b.second->push = min(b.second->push, x);
        recalc(b.second);
    }
    a.first = merge(b.first, b.second);
    t = merge(a.first, a.second);
}

treap* get(treap *t)
{
    if (!t)
    {
        assert(0);
    }
    recalc(t);
    if (t->mn == t->dist)
    {
        return t;
    }
    else if (t->l && t->l->mn == t->mn)
    {
        return get(t->l);
    }
    else
    {
        return get(t->r);
    }
}

vector <edge> g[N];
ll d[N];

int t[4 * N];
int ind[4 * N];

void upd(int v, int l, int r, int i, int x)
{
    if (r - l == 1)
    {
        ind[v] = l;
        t[v] = x;
    }
    else
    {
        int m = (l + r) / 2;
        if (i < m)
        {
            upd(v * 2 + 1, l, m, i, x);
        }
        else
        {
            upd(v * 2 + 2, m, r, i, x);
        }
        if (t[v * 2 + 1] > t[v * 2 + 2])
        {
            t[v] = t[v * 2 + 1];
            ind[v] = ind[v * 2 + 1];
        }
        else
        {
            t[v] = t[v * 2 + 2];
            ind[v] = ind[v * 2 + 2];
        }
    }
}

pair <int, int> get(int v, int l, int r, int tl, int tr)
{
    if (tl >= r || tr <= l)
    {
        return {-1e9, 0};
    }
    if (tl >= l && tr <= r)
    {
        return {t[v], ind[v]};
    }
    else 
    {
        int tm = (tl + tr) / 2;
        return max(get(v * 2 + 1, l, r, tl, tm), get(v * 2 + 2, l, r, tm, tr));
    }
}

struct wtf
{
    ll v, l, r, w;
};

bool operator < (wtf a, wtf b)
{
    return a.l < b.l;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    treap *t = 0;
    ios::sync_with_stdio(0);
    int n, Q, s;
    cin >> n >> Q >> s;
    for (int i = 0; i < n; i++)
    {
        t = merge(t, new treap(i));
    }
    vector <wtf> kek;
    s--;
    for (int i = 0; i < Q; i++)
    {
        int tp;
        cin >> tp;
        if (tp == 1)
        {
            int v, u, w;
            cin >> v >> u >> w;
            v--, u--;
            g[v].push_back({u, u, w});
        }
        else if (tp == 2)
        {
            int v, l, r, w;
            cin >> v >> l >> r >> w;
            v--, l--, r--;
            g[v].push_back({l, r, w});
        }
        else
        {
            int v, l, r, w;
            cin >> v >> l >> r >> w;
            v--, l--, r--;
            kek.push_back({v, l, r, w});
        }
    }
    sort(kek.begin(), kek.end());
    int m = kek.size();
    for (int i = 0; i < m; i++)
    {
        upd(0, 0, m, i, kek[i].r);
    }
    relax(t, s, s, 0);
    int cnt = n;
    vector <ll> ans(n, 1e18);
    while (t)
    {
        treap *v = get(t);
        int ind = v->x;
        ll dist = v->mn;
        ans[ind] = dist;
        auto a = split(t, ind);
        auto b = split(a.first, ind - 1);
        t = merge(b.first, a.second);
        for (auto go : g[ind])
        {
            relax(t, go.l, go.r, dist + go.w);
        }
        if (!m || kek[0].l > ind)
        {
            continue;
        }
        else
        {
            int l = 0, r = m;
            while (l < r - 1)
            {
                int m = (l + r) / 2;
                if (kek[m].l <= ind)
                {
                    l = m;
                }
                else
                {
                    r = m;
                }
            }
            while (1)
            {
                auto a = get(0, 0, l + 1, 0, m);
                if (a.first < ind)
                {
                     break;
                }
                int go = kek[a.second].v;
                relax(t, go, go, dist + kek[a.second].w);
                upd(0, 0, m, a.second, -1e9);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == 1e18)
        {
            printf("%d ", -1);
        }
        else
        {
            printf("%lld ", ans[i]);
        }
    }
}