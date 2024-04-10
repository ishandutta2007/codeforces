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


const int MOD =  1e9 + 7;

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


/*const int LIM = 1e6 + 5;

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
        find_set(a);
        find_set(b);

        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        };
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

int process(int n)
{
    for (int i = 2; i*i<=n; i++)
    {
        while (n%(i*i)==0) n/=(i*i);
    }
    return n;
}

const int INF = 1e9;

void solve()
{
    int n, k; cin>>n>>k;
   // cout<<"SOLVING: "<<n<<' '<<k<<endl;

    vector<int> a(n); for (int i = 0; i<n; i++) cin>>a[i];
    for (int i = 0; i<n; i++) a[i] = process(a[i]);

    vector<vector<int>> dp(n+1, vector<int>(k+1, INF));

    vector<int> pre(n, -1);

    /*for (auto it: pre) cout<<it<<' ';
    cout<<endl;*/

    map<int, int> pos;
    for (int i = 0; i<n; i++)
    {
        if (pos.find(a[i])!=pos.end()) pre[i] = pos[a[i]];
        pos[a[i]] = i;
    }

    vector<vector<int>> pre_k(n+1, vector<int>(k+1));

    for (int i = 2; i<=n; i++)
        for (int cnt_eq = 0; cnt_eq<=k; cnt_eq++)
        {
            if (pre[i-1]==-1)
            {
                pre_k[i][cnt_eq] = pre_k[i-1][cnt_eq];
                continue;
            }

            if (pre[i-1]<pre_k[i-1][cnt_eq])
            {
                pre_k[i][cnt_eq] = pre_k[i-1][cnt_eq];
                continue;
            }

            pre_k[i][cnt_eq] = pre[i-1]+1; if (cnt_eq!=0) pre_k[i][cnt_eq] = min(pre_k[i][cnt_eq], pre_k[i-1][cnt_eq-1]);
            //Now we know that pre[i]>=pre_k[i-1][cnt_eq], this means we take min(pre[i], pre_k[i-1][cnt_eq]
        }

    /*cout<<"PRE_K: "<<endl;
    for (int i = 0; i<=n; i++)
    {
        for (auto x: pre_k[i]) cout<<x<<' ';
        cout<<endl;
    }
    cout<<"ENDED PRE_K"<<endl;*/

    for (int i = 0; i<=k; i++) dp[0][i] = 0;
    for (int i = 1; i<=n; i++)
    {
        for (int j = 0; j<=k; j++)
        {
            for (int take = 0; take<=j; take++)
            {
                int where = pre_k[i][take];
                dp[i][j] = min(dp[i][j], 1 + dp[where][j-take]);
            }
        }
    }

    cout<<dp[n][k]<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t; while (t--) solve();
}


/*
1
1 0
1
 */