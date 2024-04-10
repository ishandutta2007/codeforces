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

int p =  998244353;

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

int po(int a, ll deg)
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
const int N = 1e6 + 5;

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

/*
struct DSU
{
    vector<int> sz;
    vector<int> parent;
    vector<bool> cycle;
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
        if (a==b) cycle[a] = true;
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
            if (cycle[b]) cycle[a] = true;
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        cycle.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/


void solve()
{
    int n, m; cin>>n>>m;
    vector<int> a(n), b(n), c(m);
    for (int i = 0; i<n; i++) cin>>a[i];
    for (int i = 0; i<n; i++) cin>>b[i];
    for (int i = 0; i<m; i++) cin>>c[i];

    vector<set<int>> need(n+1), have(n+1);
    for (int i = 0; i<n; i++)
    {
        if (a[i]==b[i]) have[a[i]].insert(i);
        else need[b[i]].insert(i);
    }

    if (need[c[m-1]].size() == 0 && have[c[m-1]].size() == 0) {cout<<"NO"<<endl; return;}

    vector<int> ops;
    for (auto x: c)
    {
        if (need[x].size())
        {
            auto val = *need[x].begin();
            need[x].erase(val); have[x].insert(val);
            ops.push_back(val);
            //cout<<"1"<<endl;
        }
        else if (have[x].size())
        {
            ops.push_back(*have[x].begin());
            //cout<<"2"<<endl;
        }
        else if (need[c[m-1]].size())
        {
            ops.push_back(*need[c[m-1]].begin());
            //cout<<"3"<<endl;
        }
        else
        {
            auto val = *have[c[m-1]].begin();
            have[c[m-1]].erase(val); need[c[m-1]].insert(val);
            ops.push_back(val);
            //cout<<"4"<<endl;
        }
    }

    for (int i = 1; i<=n; i++) if (need[i].size()) {cout<<"NO"<<endl; return;}
    cout<<"YES"<<endl;
    for (auto it: ops) cout<<it+1<<' ';
    cout<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) solve();

}
/*
1
5 2
1 2 2 1 1
1 2 2 1 1
3 3
 */