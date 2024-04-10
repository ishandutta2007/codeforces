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

const int MOD =  31607;

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
const int LIM = 300000;

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

/*
struct DSU
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



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin>>n;

    int a[n][n];
    int inva[n][n];

    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
        {
            cin>>a[i][j]; a[i][j] = mul(a[i][j], inv(10000));
            inva[i][j] = inv(a[i][j]);
        }

    vector<vector<int>> vals(n, vector<int>(1<<n)), invals(n, vector<int>(1<<n));
    for (int i = 0; i<n; i++)
    {
        vals[i][0] = 1;
        invals[i][0] = 1;
        for (int mask = 1; mask<(1<<n); mask++)
        {
            int bit = 0; while ((mask&(1<<bit))==0) bit++;
            vals[i][mask] = mul(vals[i][mask^(1<<bit)], a[bit][i]);
            invals[i][mask] = mul(invals[i][mask^(1<<bit)], inva[bit][i]);
        }
        //for (int mask = 0; mask<(1<<n); mask++) vals[i][mask] = sub(1, vals[i][mask]);
    }

    //cout<<vals[1][3]<<endl;

    int tot_prob = 1; for (int i = 0; i<n; i++) for (int j = 0; j<n; j++) tot_prob = mul(tot_prob, a[i][j]);

    int tot = 0;

    vector<int> cols(n);

    for (int mask = 0; mask<(1<<(n+2)); mask++)
    {
        int prob = tot_prob;
        int cnt = 0;

        for (int i = 0; i<n; i++) cols[i] = (1<<n) - 1;

        for (int i = 0; i<n; i++) cols[i]^=((mask)%(1<<n));

        for (int i = 0; i<n; i++) if (mask&(1<<i))
            {
                cnt++;
            }

        if (mask&(1<<n))
        {
            cnt++;
            for (int i = 0; i<n; i++) if (cols[i]&(1<<i)) cols[i]^=(1<<i);
        }
        if (mask&(1<<(n+1)))
        {
            cnt++;
            for (int i = 0; i<n; i++) if (cols[i]&(1<<(n-1-i))) cols[i]^=(1<<(n-1-i));
        }

        int prob_all = 1;
        for (int i = 0; i<n; i++)
        {
            prob = mul(prob, invals[i][cols[i]]);
            prob = mul(prob, sub(1, vals[i][cols[i]]));
        }


        //cout<<mask<<' '<<prob_all<<' '<<prob<<endl;


        if (cnt%2==0) tot = add(tot, prob); else tot = sub(tot, prob);

        //Found 1 - need
    }

    cout<<sub(1, tot);

}

/*
1
5000
 */