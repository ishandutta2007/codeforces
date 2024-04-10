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

void print(auto &a)
{
    for (auto s: a) cout<<s<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<(int)a.size(); i++) cin>>a[i];
}

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

vector<int> t(1000000);

void upd(int v, int tl, int tr, int idx, int val)
{
    if (tl==tr) {t[v] = val; return;}
    int mid = (tl+tr)/2;
    if (idx<=mid) upd(2*v, tl, mid, idx, val);
    else upd(2*v+1, mid+1, tr, idx, val);
    t[v] = t[2*v] + t[2*v+1];
}

int get(int v, int tl, int tr, int l, int r)
{
    if (r<l) return 0;
    if (tl==l&&tr==r) return t[v];
    int mid = (tl+tr)/2;
    return get(2*v, tl, mid, l, min(mid, r)) + get(2*v+1, mid+1, tr, max(mid+1, l), r);
}



int N = 200010;

ll cnt_different(int l, int r)
{
    if (l>r) return 0;
    ll temp = get(1, 0, N-1, l, r);
    return temp*(temp+1)/2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i<n; i++) cin>>a[i].first>>a[i].second;
    set<int> x;
    set<int> y;
    map<int, int> x1;
    map<int, int> y1;
    for (int i = 0; i<n; i++) {x.insert(a[i].first); y.insert(a[i].second);}
    int idx = 1;
    for (auto it: x) {x1[it] = idx; idx++;}
    idx = 1;
    for (auto it: y) {y1[it] = idx; idx++;}
    for (int i = 0; i<n; i++) {a[i].first = x1[a[i].first]; a[i].second = y1[a[i].second];}
    
    
    vector<int> cntx(N);
    for (auto it: a) cntx[it.first]++;
    vector<vector<int>> pos(N);
    for (auto it: a) pos[it.second].push_back(it.first);
    ll total = 0;
    for (int i = 0; i<N; i++) if (cntx[i]>0) upd(1, 0, N-1, i, 1);
    for (int i = 0; i<N; i++) sort(pos[i].begin(), pos[i].end());
    for (int i = 0; i<N; i++)
    {
        if (pos[i].size()==0) continue;
        total+= cnt_different(0, N-1);
        total-=cnt_different(0, pos[i][0]-1);
        total-=cnt_different(pos[i][pos[i].size()-1]+1, N-1);
        for (int j = 0; j+1<pos[i].size(); j++) total-=cnt_different(pos[i][j]+1, pos[i][j+1]-1);
        
        for (auto it: pos[i]) 
        {
            cntx[it]--;
            if (cntx[it]==0) upd(1, 0, N-1, it, 0);
        }
    }
    cout<<total;
    
}