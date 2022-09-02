#include <bits/stdc++.h>


using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

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
}

/*struct DSU {
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

    DSU(int n) {
        sz.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) make_set(i);
    }
};*/

/*const int N = 1200000;

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
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/

const int N = 1<<20;
vector<ll> t(N);


ll sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<ll> a(n+2);
    for (int i = 1; i<=n; i++) cin>>a[i];
    vector<ll> c(n+2);
    for (int i = 1; i<=n; i++) cin>>c[i];

    a[0] = 0;
    a[n+1] = n+1;
    n+=2;

    int m;
    cin>>m;
    vector<ll> b(m+2);
    for (int i = 1; i<=m; i++) cin>>b[i];
    b[0] = 0;
    b[m+1] = n-1;
    m+=2;
    vector<vector<ll>> pos(n);
    for (int i = 0; i<n; i++) pos[a[i]].push_back(i);

    /*for (auto it: a) cout<<it<<' ';
    cout<<endl;
    for (auto it: c) cout<<it<<' ';
    cout<<endl;

    for (auto it: b) cout<<it<<' ';
    cout<<endl;*/

    vector<ll> res = {0};

    for (int i = 0; i<n; i++) if (a[i]>0) update(1, 0, n-1, i, c[i]);


    for (int i = 0; i<m; i++)
    {
        if (pos[b[i]].size()==0) {cout<<"NO"; return 0;}
    }

    for (int i = 1; i<m; i++)
    {
        vector<ll> res1;
        int cur = -1;
        ll best = 0;
        for (auto it: pos[b[i]])
        {
            if (it<pos[b[i-1]][0])
            {
                res1.push_back(INF);
                continue;
            }
            if (cur==-1)
            {
                cur = 0;
                best = res[0];
            }
            while (cur+1<pos[b[i-1]].size() && pos[b[i-1]][cur+1]<it)
            {
                best = min(best + sum(1, 0, n-1, pos[b[i-1]][cur] + 1, pos[b[i-1]][cur+1]), res[cur+1]);
                cur++;
            }
            res1.push_back(best + sum(1, 0, n-1, pos[b[i-1]][cur]+1, it-1));
        }
        for (auto &it: res1) if (it>INF/2) it = INF;

        for (int j = b[i-1]+1; j<=b[i]; j++)
            for (auto it: pos[j])
                update(1, 0, n-1, it, min(0ll, c[it]));

        res = res1;

        /*cout<<b[i]<<":"<<endl;
        cout<<"positions: "; for (auto it: pos[b[i]]) cout<<it<<' ';
        cout<<endl;
        for (auto it: res) cout<<it<<' ';
        cout<<endl;*/

    }
    if (res[0]==INF) cout<<"NO"<<endl;
    else cout<<"YES"<<endl<<res[0];


}