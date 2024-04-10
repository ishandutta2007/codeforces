#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
}*/

int INF = 1e9;


struct SegTree
{
    vector<int> t, lazy;
    int N;
    void push(int v) {
        t[v*2] += lazy[v];
        lazy[v*2] += lazy[v];
        t[v*2+1] += lazy[v];
        lazy[v*2+1] += lazy[v];
        lazy[v] = 0;
    }

    void update(int v, int tl, int tr, int l, int r, int addend) {
        if (l > r)
            return;
        if (l == tl && tr == r) {
            t[v] += addend;
            lazy[v] += addend;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(v*2, tl, tm, l, min(r, tm), addend);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return INF;
        if (l <= tl && tr <= r)
            return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        return min(query(v*2, tl, tm, l, min(r, tm)),
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

    SegTree(int n)
    {
        t.resize(4*n);
        lazy.resize(4*n);
        N = n;
    }

    void upd(int l, int r, int add)
    {
        update(1, 0, N-1, l, r, add);
    }

    int minn(int l, int r)
    {
        return query(1, 0, N-1, l, r);
    }
};


void solve()
{
    int n;
    cin>>n;
    vector<int> a(n); for (int i = 0; i<n; i++) cin>>a[i];
    vector<int> pos;

    for (int i = 0; i<n; i++) if (a[i]==0) pos.push_back(i);
    int cnt = pos.size();
    SegTree segtree(cnt);

    if (cnt<=1) {cout<<0<<endl; return;}

    for (int i = 0; i<cnt; i++)
    {
        segtree.upd(i, i, cnt-1 + i);
    }

    vector<int> last(n+1, -1);

    int ans = 1e9;
    for (int i = 0; i<cnt-1; i++)
    {
        for (int j = pos[i]+1; j<pos[i+1]; j++)
        {
            int prv = last[a[j]];
            int idx = lower_bound(pos.begin(), pos.end(), prv) - pos.begin();
            segtree.upd(idx, i, 1);
            last[a[j]] = j;
        }
        ans = min(ans, segtree.minn(0, cnt-1) - (i+1));
    }

    cout<<min(ans, cnt/2)<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();

}
/*
1
12
0 1 0 2 2 2 0 0 3 3 4 0
 */