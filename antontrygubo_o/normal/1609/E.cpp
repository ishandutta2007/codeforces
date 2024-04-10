#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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


const int LIM = 400005;

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
}


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

const int N = (1<<18);

struct node
{
    vector<vector<int>> dp;

    bool valid;

    node()
    {
        valid = false;
        dp = vector<vector<int>>(3, vector<int>(3));
    }

    node(char c)
    {
        valid = true;
        dp = vector<vector<int>>(3, vector<int>(3));
        dp[c-'a'][c-'a'] = 1;
    }

    void set_to(char c)
    {
        valid = true;
        for (int i = 0; i<3; i++) dp[i][i] = 0;
        dp[c-'a'][c-'a'] = 1;
    }
};

node merge(node a, node b)
{
    if (!a.valid) return b;
    if (!b.valid) return a;

    node res;
    res.valid = true;
    for (int i = 0; i<3; i++)
        for (int j = i; j<3; j++)
        {
            res.dp[i][j] = 1e9;
            for (int k = i; k<=j; k++)
            {
                if (res.dp[i][j] > a.dp[i][k] + b.dp[k][j]) res.dp[i][j] = a.dp[i][k] + b.dp[k][j];
            }
        }
    return res;
}

vector<node> t(N);

void build(string &s, int v, int tl, int tr) {
    if (tl == tr) {
        t[v].set_to(s[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(s, v*2, tl, tm);
        build(s, v*2+1, tm+1, tr);
        t[v] = merge(t[v*2], t[v*2+1]);
    }
}

node query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return node();
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return merge(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, char new_val) {
    if (tl == tr) {
        t[v].set_to(new_val);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = merge(t[v*2], t[v*2+1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q; cin>>n>>q;

    string s; cin>>s;
    build(s, 1, 0, n-1);

    while (q--)
    {
        int pos; char c; cin>>pos>>c; pos--;
        update(1, 0, n-1, pos, c);
        auto res = query(1, 0, n-1, 0, n-1);
        cout<<res.dp[0][2]<<'\n';
    }

}