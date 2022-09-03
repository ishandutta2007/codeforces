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
const int LIM = 3e5 + 5;

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

const int N = 100000;

ll nxt(ll i, int op, ll x)
{
    if (op==1)
    {
        if (x%N) x = (x/N) + 1;
        else x/=N;
        return i+x;
    }
    else
    {
        x = i*x;
        if (x%N) return (x/N) + 1;
        else return x/N;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m; cin>>n>>m;
    vector<ll> t(n), x(n), y(n); for (int i = 0; i<n; i++) cin>>t[i]>>x[i]>>y[i];

    vector<int> guys(m+1, -1);
    guys[0] = 0;

    vector<int> when(m+1, -1);
    when[0] = 0;

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<=m; j++) if (guys[j]!=-1 && guys[j]<y[i])
        {
            ll can = nxt(j, t[i], x[i]);
            if (can<=m)
            {
                if (guys[can]==-1)
                {
                    guys[can] = guys[j] + 1; when[can] = i+1;
                }
                guys[can] = min(guys[can], guys[j] + 1);
            }
        }
        
        for (int j = 0; j<=m; j++) guys[j] = min(guys[j], 0);
    }

    for (int i = 1; i<=m; i++) cout<<when[i]<<' ';

}