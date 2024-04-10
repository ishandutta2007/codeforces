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


const int p = 1000000007;


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

vector<int> closest(vector<int> &a, int pos)
{
    if (pos<=a[0]) return {a[0]};
    if (pos>=a[a.size()-1]) return {a[a.size()-1]};
    auto it = lower_bound(a.begin(), a.end(), pos);
    int r = *it;
    it--;
    int l = *it;
    return {l, r};
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m, k, q;
    cin>>n>>m>>k>>q;
    vector<vector<int>> a(n);
    for (int i = 0; i<k; i++)
    {
        int x, y;
        cin>>x>>y;
        x--;
        a[x].push_back(y);
    }
    vector<int> can(q);
    for (int i = 0; i<q; i++) cin>>can[i];

    sort(can.begin(), can.end());

    for (int i = 0; i<n; i++) sort(a[i].begin(), a[i].end());
    vector<int> minn(n);
    vector<int> maxx(n);
    for (int i = 0; i<n; i++)
    {
        if (a[i].size()==0) {minn[i] = -1; maxx[i] = -1;}
        else {minn[i] = a[i][0]; maxx[i] = a[i][a[i].size() - 1];}
    }

    int last = n;
    for (int i = 0; i<n; i++) if (maxx[i]!=-1) last = i;
    if (last==0) {cout<<maxx[0]-1; return 0;}


    vector<int> cols = closest(can, maxx[0]);
    vector<ll> dp;
    for (auto it: cols) dp.push_back(maxx[0]-1 + abs(it - maxx[0]));

    /*for (auto it: cols) cout<<it<<' ';
    cout<<endl;
    for (auto it: dp) cout<<it<<' ';
    cout<<endl;*/

    for (int i = 1; i<last; i++)
    {
        if (minn[i]==-1) continue;
        vector<int> newcols;
        vector<ll> newdp;
        auto it1 = closest(can, minn[i]);
        auto it2 = closest(can, maxx[i]);
        for (auto it: it1) newcols.push_back(it);
        for (auto it: it2) newcols.push_back(it);
        int cnt = newcols.size();
        newdp.resize(cnt);
        for (int j = 0; j<cnt; j++)
        {
            newdp[j] = 1000000000000000;
            for (int prev = 0; prev<cols.size(); prev++)
            {
                int d = 1000000000;
                d = min(d, abs(cols[prev] - minn[i]) + abs(minn[i] - maxx[i]) + abs(maxx[i] - newcols[j]));
                d = min(d, abs(cols[prev] - maxx[i]) + abs(minn[i] - maxx[i]) + abs(minn[i] - newcols[j]));
                newdp[j] = min(newdp[j], dp[prev] + d);
            }
        }
        cols = newcols;
        dp = newdp;
    }
    ll answer = 1000000000000000000;
    for (int i = 0; i<cols.size(); i++)
    {
        int d = 1000000000;
        d = min(d, abs(cols[i] - minn[last]) + abs(minn[last] - maxx[last]));
        d = min(d, abs(cols[i] - maxx[last]) + abs(minn[last] - maxx[last]));
        answer = min(answer, dp[i] + d);
    }
    cout<<answer + last;

    /*cout<<endl;
    for (int i = 0; i<n; i++) cout<<minn[i]<<' ';
    cout<<endl;
    for (int i = 0; i<n; i++) cout<<maxx[i]<<' ';
    cout<<endl;*/

}