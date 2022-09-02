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

const int N = 1000000;

vector<ll> sz(N);
vector<int> par(N);

ll total = 0;

ll f(ll n)
{
    return n*(n-1)/2;
}

void init(int i)
{
    sz[i] = 1;
    par[i] = i;
}

int find_root(int i)
{
    if (par[i]==i) return i;
    par[i] = find_root(par[i]);
    return par[i];
}

void unite(int u, int v)
{
    u = find_root(u);
    v = find_root(v);
    if (u==v) return;
    if (sz[u]<sz[v]) swap(u, v);
    total+=sz[u]*sz[v];
    sz[u]+=sz[v];
    par[v] = u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    vector<pair<int, pair<int, int>>> a;
    int u, v, w;
    for (int i = 0; i<n-1; i++)
    {
        cin>>u>>v>>w;
        a.push_back(mp(w, mp(u, v)));
    }
    sort(a.begin(), a.end());

    for (int i = 1; i<=n; i++) init(i);

    vector<ll> res(200001);
    int cur = 0;
    for (int i = 1; i<=200000; i++)
    {
        while (cur<n-1 && a[cur].first<=i)
        {
            unite(a[cur].second.first, a[cur].second.second);
            cur++;
        }
        res[i] = total;
    }
    for (int i = 0; i<m; i++)
    {
        int q;
        cin>>q;
        cout<<res[q]<<' ';
    }


}