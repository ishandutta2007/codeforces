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

/*
const int LIM = 1e6 + 5;

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
        else
        {
            auto par = find_set(parent[v]);
            parent[v] = par;
            return par;
        }
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

void solve()
{
    int n, m;
    cin>>n>>m;

    vector<string> s(n);
    for (int i = 0; i<n; i++) cin>>s[i];

    int mod;
    if (n%3==0) mod = 1;
    else if (n%3==1) mod = 0;
    else if (n%3==2) mod = 0;

    vector<vector<char>> c(n, vector<char>(m));

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
        {
            c[i][j] = s[i][j]; if (i%3 == mod) c[i][j] = 'X';
        }

    for (int i = mod; i+3<=n-1; i+=3)
    {
        if (m>=2 && (s[i+1][1] == 'X' || s[i+2][1]=='X'))
        {
            c[i+1][1] = 'X'; c[i+2][1] = 'X';
        }
        else
        {
            c[i+1][0] = 'X'; c[i+2][0] = 'X';
        }
    }

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<m; j++) cout<<c[i][j];
        cout<<endl;
    }
    //cout<<endl;

}

/*
first column
every third row

 */

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t; while(t--) solve();
}