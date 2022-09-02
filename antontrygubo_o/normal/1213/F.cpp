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

vector<vector<int>> g, gr;

const int N = 200005;

int timer = 0;

vector<bool> visited(N);
vector<int> t_out(N);

vector<bool> visited2(N);


void dfs1(int i)
{
    visited[i] = true;
    timer++;
    for (auto it: g[i]) if (!visited[it]) dfs1(it);
    timer++;
    t_out[i] = timer;
}

vector<vector<int>> components;

vector<int> cur;

void dfs2(int i)
{
    visited2[i] = true;
    cur.push_back(i);
    for (auto it: gr[i]) if (!visited2[it]) dfs2(it);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, k;
    cin>>n>>k;
    g.resize(n+1);
    gr.resize(n+1);

    vector<int> p(n);
    vector<int> q(n);
    for (int i = 0; i<n; i++) cin>>p[i];
    for (int i = 0; i<n; i++) cin>>q[i];
    for (int i = 0; i<n-1; i++)
    {
        g[p[i]].push_back(p[i+1]);
        gr[p[i+1]].push_back(p[i]);
        g[q[i]].push_back(q[i+1]);
        gr[q[i+1]].push_back(q[i]);
    }

    for (int i  = 1; i<=n; i++) if (!visited[i]) dfs1(i);
    vector<pair<int, int>> topsort;
    for (int i = 1; i<=n; i++) topsort.push_back(mp(t_out[i], i));
    sort(topsort.begin(), topsort.end());
    for (int i = n-1; i>=0; i--) if (!visited2[topsort[i].second])
        {
            cur.clear();
            dfs2(topsort[i].second);
            components.push_back(cur);
        }

    /*for (int i = 1; i<=n; i++) cout<<t_out[i]<<' ';
    cout<<endl;*/




    /*for (auto it: components)
    {
        for (auto x: it) cout<<x<<' ';
        cout<<endl;
    }*/

    if (components.size()<k) {cout<<"NO"; return 0;}
    cout<<"YES"<<endl;
    vector<char> s(n+1);
    for (int i = 0; i<k; i++)
    {
        for (auto it: components[i]) s[it] = 'a'+i;
    }
    for (int i = k; i<components.size(); i++)
    {
        for (auto it: components[i]) s[it] = 'a'+k-1;
    }
    for (int i = 1; i<=n; i++) cout<<s[i];


}