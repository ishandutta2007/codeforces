#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
/*#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
#define mp make_pair
#define what_is(x) cerr << #x << " is " << x << endl;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

/*
const int p = 1e9 + 7;


int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p;
    return s;
}

int sub(int a, int b) {
    int s = (a-b);
    s = s%p;
    if (s<0) s+=p;
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}
*/
vector<int> Z(vector<int> s)
{
    int n = s.size();
    vector<int> z(n);
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            z[i] = R-L; R--;
        } else {
            int k = i-L;
            if (z[k] < R-i+1) z[i] = z[k];
            else {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                z[i] = R-L; R--;
            }
        }
    }
    return z;
}

mt19937 rnd(time(0));
/*
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct CHT : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};
*/

vector<int> d;
vector<vector<int>> G;
vector<int> parent;

void dfs(int v, int p = -1)
{
    for (auto it: G[v]) if (it!=p)
    {
        parent[it] = v;
        d[it] = d[v] + 1;
        dfs(it, v);
    }
}

vector<int> visited;


int maxx = 0;

void dfs1(int v, int p = -1)
{
    for (auto it: G[v]) if (!visited[it] && it!=p)
    {
        d[it] = d[v] + 1;
        dfs1(it, v);
        maxx = max(maxx, d[it]);
    }
}


vector<int> color;

void dfs_2(int v, int p = -1)
{
    for (auto it: G[v]) if (it!=p)
    {
        color[it] = 3 - color[v];
        dfs_2(it, v);
    }
}

int k, n;

void dfs_3(int v, int p = -1)
{
    for (auto it: G[v]) if (!visited[it] && it!=p)
    {
        color[it] = (color[v]+k-1)%k;
        dfs_3(it, v);
    }
}

void dfs_4(int v, int p = -1)
{
    for (auto it: G[v]) if (!visited[it] && it!=p)
        {
            color[it] = (color[v]+1)%k;
            dfs_4(it, v);
        }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n>>k;
    G.resize(n+1);
    int u, v;
    for (int i = 0; i<n-1; i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    if (k==2)
    {
        cout<<"YES"<<endl;
        color.resize(n+1);
        color[1] = 1;
        dfs_2(1);
        for (int i = 1; i<=n; i++) cout<<color[i]<<' ';
        return 0;
    }


    d.resize(n+1);
    parent.resize(n+1);
    d[1] = 0;
    dfs(1);
    int s = 1;
    for (int i = 1; i<=n; i++) if (d[i]>d[s]) s = i;
    d[s] = 0;
    dfs(s);
    int f = 1;
    for (int i = 1; i<=n; i++) if (d[i]>d[f]) f = i;
    parent[s] = s;
    vector<int> diam;
    diam.push_back(f);
    while (diam.back()!=s) diam.push_back(parent[diam.back()]);

    int L = diam.size();
    visited.resize(n+1);
    for (auto it: diam) visited[it] = true;

    vector<int> ans(L);
    for (int i = 0; i<L; i++)
    {
        d[diam[i]] = 0;
        maxx = 0;
        dfs1(diam[i]);
        ans[i] = maxx;
        int m = min(i+1, L-i);
        if (ans[i]>0 && ans[i]+m>=k) {cout<<"No"; return 0;}
    }

    /*for (auto it: diam) cout<<it<<' ';
    cout<<endl;*/

    color.resize(n+1);
    for (int i = 0; i<L; i++) color[diam[i]] = i%k;

    for (int i = 0; i<L/2; i++)
    {
        dfs_3(diam[i]);
    }
    for (int i = L/2; i<L; i++) dfs_4(diam[i]);
    cout<<"Yes"<<endl;
    for (int i = 1; i<=n; i++) cout<<color[i]+1<<' ';

}