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
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/

int n;

vector<vector<int>> G;

vector<ll> vals;

int dfs(int v, int par = -1)
{
    int cnt = 1;
    for (auto it: G[v]) if (it!=par)
    {
        int tmp = dfs(it, v);
        vals.push_back(1ll*tmp*(n-tmp));
        cnt+=tmp;
    }
    return cnt;
}

void solve()
{
    cin>>n;
    G.clear();
    G.resize(n);
    for (int i = 0; i<n-1; i++)
    {
        int u, v;
        cin>>u>>v;
        u--; v--;
        G[u].push_back(v); G[v].push_back(u);
    }

    int m;
    cin>>m;
    vector<int> a(m);
    for (int i = 0; i<m; i++) cin>>a[i];
    sort(a.begin(), a.end()); reverse(a.begin(), a.end());

    vals.clear();
    dfs(0);
    sort(vals.begin(), vals.end()); reverse(vals.begin(), vals.end());
    if (m<=n-1)
    {
        int answer = 0;
        for (int i = 0; i<m; i++) answer = add(answer, mul(vals[i]%p, a[i]));
        for (int i = m; i<n-1; i++) answer = add(answer, vals[i]%p);
        cout<<answer<<endl;
    }
    else
    {
        ll answer = vals[0]%p;
        for (int i = 0; i<m - (n-1) + 1; i++) answer = mul(answer, a[i]);
        for (int i = m - (n-1) + 1; i<m; i++) answer = add(answer, mul(a[i], vals[i - (m - (n-1) + 1) + 1]%p));
        cout<<answer<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();


}