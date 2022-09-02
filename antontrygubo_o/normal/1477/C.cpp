#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair
/*
int p =  1e9 + 7;

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

int po(int a, ll deg)
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

mt19937 rnd(time(0));

/*
const int N = 2000005;

vector<int> facs(N), invfacs(N);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<N; i++) facs[i] = mul(facs[i-1], i);
    invfacs[N-1] = inv(facs[N-1]);
    for (int i = N-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/


/*struct DSU
{
    vector<int> sz;
    vector<int> parent;
    vector<bool> cycle;
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a==b) cycle[a] = true;
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
            if (cycle[b]) cycle[a] = true;
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        cycle.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/
/*
struct SegmentTree
{
    int N;
    vector<int> t;

    void build(int a[], int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int add) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            t[v] += add;
        } else {
            int tm = (tl + tr) / 2;
            update(v*2, tl, tm, l, min(r, tm), add);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
        }
    }

    int get(int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return t[v] + get(v*2, tl, tm, pos);
        else
            return t[v] + get(v*2+1, tm+1, tr, pos);
    }



};

void solve()
{
    int n, q;
    cin>>n>>q;

    string s, f;
    cin>>s>>f;
    vector<pair<int, int>> a(q);
    for (int i = 0; i<q; i++) cin>>a[i].first>>a[i].second;

    for (int i = 0; i<n; i++)
    {

    }


}*/

ll dist(pair<ll, ll> a, pair<ll, ll> b)
{
    return (a.first-b.first)*(a.first-b.first) +(a.second-b.second)*(a.second-b.second);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<pair<ll, ll>> a(n+1);
    for (int i = 1; i<=n; i++) cin>>a[i].first>>a[i].second;

    vector<int> answer = {1};
    vector<bool> free(n+1, true); free[1] = false;
    for (int i = 2; i<=n; i++)
    {
        int last = answer.back();
        ll best_res = 0;
        int idx = -1;
        for (int j = 1; j<=n; j++) if (free[j] && dist(a[last], a[j])>best_res)
        {
            best_res = dist(a[last], a[j]);
            idx = j;
        }
        answer.push_back(idx); free[idx] = false;
    }

    for (auto it: answer) cout<<it<<' ';
}