#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
 
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
 
 
const int p = 998244353;
 
 
int mul(int a, int b) {
    return (1LL * a%p * b%p) % p;
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
 
const int INF = 1000000000;
 
vector<int> t(10000000);
 
void build(vector<int> &a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}
 
int get_min(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INF;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(get_min(v*2, tl, tm, l, min(r, tm)), get_min(v*2+1, tm+1, tr, max(l, tm+1), r));
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
 
 
    int n, m;
    cin>>n>>m;
    vector<int> temp(m);
    for (int i = 0; i<m; i++) cin>>temp[i];
    vector<int> a;
    a.push_back(temp[0]);
    for (int i = 1; i<m; i++) if (temp[i]!=temp[i-1]) a.push_back(temp[i]);
    m = a.size();
 
 
    vector<int> low(n+1, INF);
    vector<int> high(n+1, -1);
 
    for (int i = 0; i<m; i++) {high[a[i]] = max(high[a[i]], i); low[a[i]] = min(low[a[i]], i);}
 
    build(a, 1, 0, m-1);
    for (int i = 1; i<=n; i++)
    {
        int k = get_min(1, 0, m-1, low[i], high[i]); if (k<i) {cout<<0; return 0;}
    }
 
 
 
 
    vector<vector<int>> dp(m, vector<int>(m));
 
    /*for (int i = 0; i<m; i++) cout<<a[i]<<' ';
    cout<<endl;
    for (int i = 1; i<=n; i++) cout<<low[i]<<' ';
    cout<<endl;
    for (int i = 1; i<=n; i++) cout<<high[i]<<' ';
    cout<<endl;
    cout<<"LOL"<<endl;*/
 
    for (int t = 0; t<m; t++)
    {
        for (int l = 0; l+t<m; l++)
        {
            int r = l+t;
            int minn = INF;
            bool check = true;
            for (int i = l; i<=r; i++)
            {
                minn = min(minn, a[i]);
                if (low[a[i]]<l||high[a[i]]>r) check = false;
            }
            int res = 1;
            if (!check) continue;
            vector<int> min_val;
            for (int i = l; i<=r; i++) if (a[i]==minn) min_val.push_back(i);
            for (int i = 0; i<min_val.size()-1; i++) if (min_val[i]+1<min_val[i+1]) res = mul(res, dp[min_val[i]+1][min_val[i+1]-1]);
            int L = min_val[0];
            int R = min_val[min_val.size()-1];
 
            int left = 1;
            if (L>l) left = mul(2, dp[l][L-1]);
            int L1 = L-1;
            while (L1>l)
            {
                L1 = low[a[L1]];
                if (L1>l) left = add(left, mul(dp[l][L1-1], dp[L1][L-1]));
                L1--;
            }
            int right = 1;
            if (R<r) right = mul(2, dp[R+1][r]);
            int R1 = R+1;
            while (R1<r)
            {
                R1 = high[a[R1]];
                if (R1<r) right = add(right, mul(dp[R+1][R1], dp[R1+1][r]));
                R1++;
            }
            dp[l][r] = mul(res, mul(left, right));
 
        }
    }
    cout<<dp[0][m-1];
 
}