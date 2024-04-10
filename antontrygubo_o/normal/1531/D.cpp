#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

#define mp make_pair


int MOD =  998244353;



int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=MOD) s-=MOD;
    return s;
}

int sub(int a, int b) {
    int s = (a+MOD-b);
    if (s>=MOD) s-=MOD;
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
    return po(n, MOD-2);
}


mt19937 rnd(time(0));

/*
const int LIM = 1000;

vector<int> facs(LIM), invfacs(LIM);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<LIM; i++) facs[i] = mul(facs[i-1], i);
    invfacs[LIM-1] = inv(facs[LIM-1]);
    for (int i = LIM-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
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
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return find_set(parent[v]);
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

const int INF = 1e9;
const int N = (1<<18);

struct SegmentTree
{
    vector<int> t, lazy;

    int n;

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
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return -INF;
        if (l <= tl && tr <= r)
            return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        return max(query(v*2, tl, tm, l, min(r, tm)),
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }


    SegmentTree()
    {
        t.resize(N); lazy.resize(N);
    }

    SegmentTree(int _n)
    {
        t.resize(N); lazy.resize(N);
        n = _n;
    }


    void upd(int l, int r, int addend)
    {
        update(1, 0, n-1, l, r, addend);
    }

    int query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }

    int find_max()
    {
        int L = 0; int R = n-1;
        while (R-L>1)
        {
            int mid = (L+R)/2;
            if (query(mid, n-1)>=1) L = mid;
            else R = mid;
        }
        return L;
    }

};

const string U = "unlock";
const string L = "lock";

set<int> l, u;

SegmentTree tr;

void push(int unlocker)
{
    auto r = *(l.lower_bound(unlocker));
    auto kek = (u.upper_bound(unlocker));
    if (kek!=u.end()) r = min(r, *kek);
    tr.upd(unlocker+1, r-1, 1);
}

void unpush(int unlocker)
{
    auto r = *(l.lower_bound(unlocker));
    auto kek = (u.upper_bound(unlocker));
    if (kek!=u.end()) r = min(r, *kek);
    tr.upd(unlocker+1, r-1, -1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<string> s(n+3);
    s[0] = U;
    s[1] = "blue";
    s[n+2] = L;
    for (int i = 2; i<=n+1; i++) cin>>s[i];

    for (int i = 0; i<=n+2; i++)
    {
        if (s[i]==L) l.insert(i);
        else if (s[i]==U) u.insert(i);
    }

    tr = SegmentTree(n+3);

    for (auto it: u) tr.upd(it, it, -INF);
    for (auto it: l) tr.upd(it, it, -INF);

    //Add 1 on every segment of form: [U, U], and [U, L]

    for (auto it: u) push(it);

    int ans = tr.find_max();
    cout<<s[ans]<<endl;

    int t; cin>>t;

    while (t--)
    {
        int idx; string s_new;
        cin>>idx>>s_new;
        idx++;

        int prv = *(prev(u.lower_bound(idx)));
        auto kek = l.lower_bound(idx);

        if (kek!=l.begin())
        {
            kek = prev(kek);
            prv = max(prv, (*kek));
        }

        if (s[idx]==L || s[idx]==U)
        {
            if (s[idx]==U) unpush(idx);
            tr.upd(idx, idx, INF);
        }

        if (s[prv]==U) unpush(prv);

        if (s[idx]==L) l.erase(idx);
        if (s[idx]==U) u.erase(idx);

        s[idx] = s_new;

        if (s[idx]==L) l.insert(idx);
        if (s[idx]==U) u.insert(idx);

        if (s[idx]==L || s[idx]==U)
        {
            if (s[idx]==U) push(idx);
            tr.upd(idx, idx, -INF);
        }

        if (s[prv]==U) push(prv);

        cout<<s[tr.find_max()]<<endl;

    }



}