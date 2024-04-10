#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
    return x * x;
}

struct node
{
    ll key;
    int pr;
    node *l, *r;
    int sz;
    node()
    {
        l = r = NULL;
        pr = rand();
        sz = 1;
    }
    void update()
    {
        sz = 1;
        if (l)
            sz += l->sz;
        if (r)
            sz += r->sz;
    }
};

typedef node* pnode;

pnode merge(pnode l, pnode r)
{
    if (!l || !r)
        return l ? l : r;
        
    if (l->pr > r->pr)
    {
        l->r = merge(l->r, r);
        l->update();
        return l;
    }
    else
    {
        r->l = merge(l, r->l);
        r->update();
        return r;
    }
}

void split(pnode v, pnode &l, pnode &r, ll key)
{
    if (!v)
    {
        l = r = NULL;
        return;
    }
    
    if (v->key <= key)
    {
        l = v;
        split(v->r, l->r, r, key);
    }
    else
    {
        r = v;
        split(v->l, l, r->l, key);
    }
    
    if (l)
        l->update();
    if (r)
        r->update();
}

const int maxn = 100005;

vector < pair < int, ll > > g[maxn];

ll maxD[maxn];

void dfs(int v, int p)
{
    for (auto to : g[v])
    {
        if (to.fst == p)
            continue;
        dfs(to.fst, v);
        maxD[v] = max(maxD[to.fst] + to.snd, maxD[v]);
    }
}

void dfs2(int v, int p, ll up)
{
    maxD[v] = max(maxD[v], up);
    
    ll m1 = -1e18, m2 = -1e18;
    
    for (auto to : g[v])
    {
        if (to.fst == p)
            continue;
        ll x = maxD[to.fst] + to.snd;
        if (x > m1)
        {
            m2 = m1;
            m1 = x;
        }
        else if (x > m2)
            m2 = x;
    }
    
    
    for (auto to : g[v])
    {
        if (to.fst == p)
            continue;
            
        ll x = maxD[to.fst] + to.snd;
        
        ll nup = up;
        
        if (x == m1)
            nup = max(nup, m2);
        else
            nup = max(nup, m1);
            
        dfs2(to.fst, v, nup + to.snd);
    }
}


pnode dfsMerge(pnode v, pnode acc)
{
    if (v == NULL)
        return acc;
        
    auto res = dfsMerge(v->l, acc);
    res = dfsMerge(v->r, res);
    
    pnode l, c, r;
    split(res, l, r, v->key - 1);
    c = new node();
    c->key = v->key;
    res = merge(l, merge(c, r));
    return res;
}

vector < ll > queries;
vector < int > ans[maxn];

int getSize(pnode v)
{
    return v ? v->sz : 0;
}

pnode dfs3(int v, int p)
{
    pnode res = new node();
    res->key = maxD[v];
    
    for (auto to : g[v])
    {
        if (to.fst == p)
            continue;
            
        auto x = dfs3(to.fst, v);
        
        if (getSize(x) < getSize(res))
            res = dfsMerge(x, res);
        else
            res = dfsMerge(res, x);
    }
    
    for (ll x : queries)
    {
        pnode l, r;
        split(res, l, r, maxD[v] + x);
        ans[v].pb(getSize(l));
        res = merge(l, r);
    }
    
    return res;
}


void gen()
{
    ofstream out("a.in");
    out << 100000 << endl;
    for (int i = 2; i <= 100000; i++)
    {
        int u = rand() % (i - 1) + 1;
        out << i << " " << u << " " << rand() % 1000000 << endl;
    }
    out << 50 << endl;
    for (int i = 0; i < 50; i++)
        out << rand() % 100000000 << endl;
    out.close();
}

int main()
{
    //srand(time(NULL));
    //gen();
    //freopen("a.in", "r", stdin);
    
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        g[u].pb(mp(v, c));
        g[v].pb(mp(u, c));
    }
    
    dfs(1, -1);
    dfs2(1, -1, 0);
    
    int root = 1;
    for (int i = 1; i <= n; i++)
        if (maxD[i] < maxD[root])
            root = i;
            
    int q;
    scanf("%d", &q);
    
    for (int i = 0; i < q; i++)
    {
        ll x;
        cin >> x;
        queries.pb(x);
    }

    dfs3(root, -1);
    
    for (int i = 0; i < q; i++)
    {
        int x = 0;
        for (int j = 1; j <= n; j++)
            x = max(x, ans[j][i]);
        cout << x << endl;
    }

    return 0;
}