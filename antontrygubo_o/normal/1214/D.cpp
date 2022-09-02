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

int n, m;
vector<vector<bool>> visited1;
vector<vector<bool>> visited2;

vector<vector<int>> a;
void dfs1(int x, int y)
{
    visited1[x][y] = true;
    if (x+1<n && a[x+1][y]==0 && !visited1[x+1][y]) dfs1(x+1, y);
    if (y+1<m && a[x][y+1]==0 && !visited1[x][y+1]) dfs1(x, y+1);
}

void dfs2(int x, int y)
{
    visited2[x][y] = true;
    if (x-1>=0 && a[x-1][y]==0 && !visited2[x-1][y]) dfs2(x-1, y);
    if (y-1>=0 && a[x][y-1]==0 && !visited2[x][y-1]) dfs2(x, y-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n>>m;

    vector<string> s(n);
    for (int i = 0; i<n; i++) cin>>s[i];
    a = vector<vector<int>> (n, vector<int>(m));
    for (int i = 0; i<n; i++)
        for (int j  = 0; j<m; j++) if (s[i][j]=='.') a[i][j] = 0; else a[i][j] = 1;

    /*for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<m; j++) cout<<a[i][j]<<' ';
        cout<<endl;
    }*/

    visited1 = vector<vector<bool>> (n, vector<bool>(m));
    visited2 = vector<vector<bool>> (n, vector<bool>(m));
    dfs1(0, 0);
    dfs2(n-1, m-1);


    /*for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<m; j++) cout<<visited1[i][j]<<' ';
        cout<<endl;
    }

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<m; j++) cout<<visited2[i][j]<<' ';
        cout<<endl;
    }*/




    vector<int> cnt(n+m);
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++) if (visited1[i][j] && visited2[i][j]) cnt[i+j]++;

    int minn = 3;
    for (int i = 1; i<=m+n-3; i++) minn = min(minn, cnt[i]);
    cout<<minn;



}