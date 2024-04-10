#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using ll = long long;
using ld = long double;



#define mp make_pair
/*
const int p = 998244353;

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


mt19937 rnd(time(0));

/*
const int N = 1200000;

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
}

*/


/*struct DSU
{
    vector<int> sz;
    vector<int> parent;

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
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

struct SegTree
{
    int n;
    vector<int> t;

    void update(int v, int tl, int tr, int l, int r, int maximizer) {
        if (l > r || tl > r || tr < l)
            return;
        if (l == tl && r == tr) {
            t[v] = max(t[v], maximizer); return;
        } else {
            int tm = (tl + tr) / 2;
            update(v*2, tl, tm, l, min(r, tm), maximizer);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, maximizer);
        }
    }

    int query(int v, int tl, int tr, int pos)
    {
        if (tl==tr) return t[v];
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                return max(t[v], query(v*2, tl, tm, pos));
            else
                return max(t[v], query(v*2+1, tm+1, tr, pos));
        }
    }

    int upd(int l, int r, int maximizer)
    {
        //cout<<"Maximize: "<<l<<' '<<r<<' '<<maximizer<<endl;
        update(1, 0, n-1, l, r, maximizer);
    }

    int query(int pos)
    {
        return query(1, 0, n-1, pos);
    }

    SegTree(int N)
    {
        n = N+1;
        t.resize(1<<19);
    }

};



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) {cin>>a[i]; a[i]--;}

    /*for (auto it: a) cout<<it<<' ';
    cout<<endl;*/

    bool all0 = true;
    for (auto it: a) if (it!=0) all0 = false;
    if (all0) {cout<<1<<endl; return 0;}

    vector<vector<int>> pos(n+2);

    for (int i = 0; i<=n+1; i++)
    {
        pos[i].push_back(-1);
    }

    for (int i = 0; i<n; i++) pos[a[i]].push_back(i);

    for (int i = 0; i<=n+1; i++)
    {
        pos[i].push_back(n);
    }

    SegTree tree(n);

    for (int i = 0; i<=n+1; i++)
    {
        //cout<<i<<": "<<endl;
        bool exists = false;
        for (int j = 0; j+1<pos[i].size(); j++) if (pos[i][j]+1<n)
        {
            //cout<<pos[i][j]+1<<' '<<tree.query(pos[i][j]+1)<<endl;
            if (tree.query(pos[i][j]+1)<pos[i][j+1]) exists = true;
        }
        if (!exists) {cout<<i+1; return 0;}
        for (int j = 0; j+1<pos[i].size(); j++) tree.upd(pos[i][j]+1, pos[i][j+1], pos[i][j+1]);
    }


}