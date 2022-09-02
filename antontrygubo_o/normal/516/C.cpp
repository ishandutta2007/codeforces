#include <bits/stdc++.h>


using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

const int p = 1000000007;


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

/*const int N = 1000000;

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

const int N = 1<<19;

struct dat {
    ll sum, pref, suff, ans;
};

vector<ll> a(N);
vector<ll> h(N);
vector<dat> t(N);

dat combine(dat l, dat r, ll dis) {
    dat res;
    res.sum = l.sum + r.sum + dis;
    res.pref = max(l.pref, l.sum + dis + r.pref);
    res.suff = max(r.suff, r.sum + dis + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + dis + r.pref);
    return res;
}

dat make_data(int val) {
    dat res;
    res.sum = 0; res.ans = 0;
    res.pref = res.suff = val;
    return res;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_data(h[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1], a[tm]);
    }
}

dat query(int v, int tl, int tr, int l, int r) {
    //cout<<v<<' '<<tl<<' '<<tr<<' '<<l<<' '<<r<<endl;
    if (l > r)
        return make_data(0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (l<=tm && tm<r) return combine(query(v*2, tl, tm, l, min(r, tm)),
                   query(v*2+1, tm+1, tr, max(l, tm+1), r), a[tm]);
    else return combine(query(v*2, tl, tm, l, min(r, tm)),
                        query(v*2+1, tm+1, tr, max(l, tm+1), r), 0);
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    for (int i = 0; i<n; i++) cin>>a[i];
    for (int i = n; i<2*n; i++) a[i] = a[i-n];
    for (int i = 0; i<n; i++) {cin>>h[i]; h[i]*=2;}
    for (int i = n; i<2*n; i++) h[i] = h[i-n];

    build(1, 0, 2*n-1);

    for (int i = 0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        a--; b--;
        int a1 = (b+1)%n;
        int b1 = (a+n-1)%n;
        a = a1; b = b1;
        if (b<a) b+=n;
        //cout<<a<<' '<<b<<endl;
        cout<<query(1, 0, 2*n-1, a, b).ans<<endl;
    }

}
/*
5 1
2 2 2 2 2
3 5 2 1 4
1 3
 */