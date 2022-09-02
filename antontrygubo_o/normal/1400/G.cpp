#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;


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


vector<vector<int>> G;

vector<vector<int>> components;
vector<bool> visited;

vector<int> current;

void dfs(int v)
{
    visited[v] = true;
    current.push_back(v);
    for (auto it: G[v]) if (!visited[it]) dfs(it);
}

vector<int> sosdp(vector<bool> A, int N)
{
    vector<int> F(1<<N);
    for(int i = 0; i<(1<<N); ++i)
        F[i] = A[i];
    for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
            if(mask & (1<<i))
                F[mask] += F[mask^(1<<i)];
        }
    return F;
}


vector<vector<int>> process(vector<int> component)
{
    int n = component.size();
    vector<bool> independent(1<<n);
    independent[0] = true;
    for (int mask = 1; mask<(1<<n); mask++)
    {
        int set = 0;
        while ((mask&(1<<set))==0) set++;
        independent[mask] = independent[mask^(1<<set)];
        for (int bit = 0; bit<n; bit++) if (mask&(1<<bit))
        {
            if (find(G[component[set]].begin(), G[component[set]].end(), component[bit]) != G[component[set]].end()) independent[mask] = false;
        }
    }

    vector<int> cnt_bits(1<<n);
    for (int i = 1; i<(1<<n); i++) cnt_bits[i] = i%2 + cnt_bits[i/2];

    vector<vector<bool>> independent_sz(n+1, vector<bool>(1<<n));
    for (int i = 0; i<(1<<n); i++) if (independent[i]) independent_sz[cnt_bits[i]][i] = true;

    vector<vector<int>> cnt_good(n+1);
    for (int i = 0; i<=n; i++) cnt_good[i] = sosdp(independent_sz[i], n);

    return cnt_good;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    init();

    int n, m;
    cin>>n>>m;

    vector<int> st(n+1), en(n+1);

    vector<int> l(n), r(n);

    for (int i = 0; i<n; i++)
    {
        cin>>l[i]>>r[i];
        st[l[i]]++; en[r[i]]++;
    }

    G.resize(n);
    for (int i = 0; i<m; i++)
    {
        int u, v;
        cin>>u>>v; u--; v--;
        G[u].push_back(v); G[v].push_back(u);
    }

    visited.resize(n);
    for (int i = 0; i<n; i++) if (!visited[i])
    {
        current.clear();
        dfs(i);
        if (current.size()>1) components.push_back(current);
    }

    vector<vector<vector<int>>> data;
    for (auto it: components) data.push_back(process(it));

    int total = 0;

    int cur = 0;

    for (int sz = 1; sz<=n; sz++)
    {
        cur+=st[sz];

        int weirdos = 0;
        for (auto comp: components)
        {
            for (auto x: comp) if (l[x]<=sz && r[x]>=sz) weirdos++;
        }

        vector<int> cnt(21);
        cnt[0] = 1;
        for (int i = 0; i<components.size(); i++)
        {
            int mask = 0;
            for (int j = 0; j<components[i].size(); j++)
            {
                int node = components[i][j];
                if (l[node]<=sz && r[node]>=sz) mask+=(1<<j);
            }
            vector<int> cnt1(21);
            for (int take_tot = 0; take_tot<=20; take_tot++)
            {
                for (int take_cur = 0; take_cur<=min(take_tot, (int)components[i].size()); take_cur++)
                    cnt1[take_tot] = add(cnt1[take_tot], mul(cnt[take_tot - take_cur], data[i][take_cur][mask]));
            }
            cnt = cnt1;
        }
        for (int i = 0; i<=20; i++)
        {
            total = add(total, mul(cnt[i], C(cur - weirdos, sz - i)));
        }

        cur-=en[sz];
    }

    cout<<total;

}