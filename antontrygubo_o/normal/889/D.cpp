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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<ll> x(n);
    vector<ll> y(n);
    for (int i = 0; i<n; i++)
    {
        cin>>x[i]>>y[i];
        x[i]*=(2*n);
        y[i]*=(2*n);
    }
    ll totalx = 0;
    ll totaly = 0;
    for (int i = 0; i<n; i++)
    {
        totalx+=x[i];
        totaly+=y[i];
    }
    totalx/=n;
    totaly/=n;

    for (int i = 0; i<n; i++)
    {
        x[i]-=totalx;
        y[i]-=totaly;
    }

    //for (int i = 0; i<n; i++) cout<<x[i]<<' '<<y[i]<<endl;

    set<pair<ll, ll>> pt;
    for (int i = 0; i<n; i++) pt.insert(mp(x[i], y[i]));
    if (pt.find(mp(0, 0))!=pt.end()) pt.erase(mp(0, 0));
    while (true)
    {
        pair<int, int> kek;
        bool found = false;
        for (auto it: pt) if (pt.find(mp(-it.first, -it.second))!=pt.end())
            {
                kek = it;
                found = true;
                break;
            }
        if (found)
        {
            pt.erase(kek);
            pt.erase(mp(-kek.first, -kek.second));
            continue;
        }
        break;
    }

    vector<pair<ll, ll>> guys;
    for (auto it: pt) guys.push_back(it);
    if (guys.size()==0) {cout<<-1; return 0;}

    set<pair<ll, ll>> lines;

    n = guys.size();

    int counter = 0;

    for (int i = 0; i<n; i++)
    {
        ll x1 = (guys[0].first + guys[i].first)/2;
        ll y1 = (guys[0].second + guys[i].second)/2;
        if (x1<0) {x1*=-1; y1*=-1;}
        ll t = __gcd(abs(x1), abs(y1));
        x1/=t;
        y1/=t;
        if (lines.find(mp(x1, y1))!=lines.end()) continue;
        lines.insert(mp(x1, y1));
        x1 = (guys[0].first + guys[i].first)/2;
        y1 = (guys[0].second + guys[i].second)/2;
        vector<ll> kek;
        for (int j = 0; j<n; j++)
        {
            kek.push_back(guys[j].first*y1 - guys[j].second*x1);
        }
        sort(kek.begin(), kek.end());
        /*cout<<i<<": "<<endl;
        for (auto it: kek) cout<<it<<' ';
        cout<<endl;*/
        bool check = true;
        for (int j = 0; j<n; j++) if (kek[j]!=-kek[n-1-j]) check = false;
        if (check) counter++;
    }
    cout<<counter;


}