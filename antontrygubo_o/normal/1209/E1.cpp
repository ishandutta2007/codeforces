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
    if (s>=p) s-=p;
    return s;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
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
}*/

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
        return a /b - ((a ^ b) < 0 && a % b); }
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

void solve()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++) cin>>a[i][j];

    int best = 0;
    vector<int> maxx(m);
    for (int i = 0; i<m; i++)
    {
        for (int j = 0; j<n; j++) maxx[i] = max(maxx[i], a[j][i]);
    }


    /*for (auto it: maxx) cout<<it<<' ';
    cout<<endl;*/


    vector<int> m4;
    for (auto it: maxx) m4.push_back(it);
    sort(m4.begin(), m4.end());
    int temp = 0;
    for (int i = (int)m4.size()-1; i>=(int)m4.size() - min(n, m); i--) temp+=m4[i];
    best = max(best, temp);
    for (int i = 0; i<m; i++)
    {
        int t = 0;
        for (int j = 0; j<n; j++) t+=a[j][i];
        best = max(best, t);
    }

    for (int i = 0; i<m; i++)
    {
        int t = 0;
        int minn = a[0][i];
        for (int j = 0; j<n; j++)
        {
            t+=a[j][i];
            minn = min(minn, a[j][i]);
        }
        t-=minn;
        int M = 0;
        for (int j = 0; j<m; j++) if (j!=i) M = max(M, maxx[j]);
        t+=M;
        best = max(best, t);
    }

    if (n==4)
    {
        vector<int> best_close(m);
        vector<int> best_not_good(m);
        for (int i = 0; i<m; i++)
        {
            for (int k = 0; k<n; k++)
                for (int l = k+1; l<n; l++)
                {
                    if (k+2!=l) best_close[i] = max(best_close[i], a[k][i] + a[l][i]);
                    else best_not_good[i] = max(best_not_good[i], a[k][i] + a[l][i]);
                }
        }
        for (int i = 0; i<m; i++)
            for (int j = i+1; j<m; j++)
            {
                best = max(best, best_close[i] + best_close[j]);
                best = max(best, best_not_good[i] + best_not_good[j]);
            }
        
        if (m>=3) for (int i = 0; i<m; i++)
        {
            vector<int> good;
            for (int j = 0; j<m; j++) if (j!=i) good.push_back(maxx[j]);
            sort(good.begin(), good.end());
            best = max(best, max(best_close[i], best_not_good[i]) + good[good.size()-1] + good[good.size()-2]);
        }
        
    }
    cout<<best<<endl;
    return;


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    for (int i = 0; i<t; i++) solve();


}