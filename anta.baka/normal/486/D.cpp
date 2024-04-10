#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
const ull MOD = 1000000007;
int a[2000], d, n;
vector<vector<int> > tr;

void add(ull &a, ull b) {
    a += b;
    if(a >= MOD)
        a -= MOD;
}

void dfs(int v, vector<bool> &vz, int &rt, vector<ull> &dp) {
    for(int i=0, sz=(int)tr[v].size(); i<sz; i++)
        if(!vz[tr[v][i]] &&  a[tr[v][i]] <= d + a[rt] && (a[tr[v][i]] > a[rt] || (a[tr[v][i]] == a[rt] && tr[v][i] > rt))) {
            vz[tr[v][i]] = 1;
            dfs(tr[v][i], vz, rt, dp);
            dp[v] = (dp[v] * (dp[tr[v][i]] + 1)) % MOD;
        }
}

ull f(int v) {
    vector<bool> vz(n, 0);
    vz[v] = 1;
    vector<ull> dp(n, 1);
    dfs(v, vz, v, dp);
    return dp[v];
}

int main()
{
    cin >> d >> n;
    tr.resize(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=1, u, v; i<n; i++)
        cin >> u >> v, u--, v--, tr[u].pb(v), tr[v].pb(u);
    ull ans = 0;
    for(int i=0; i<n; i++)
        add(ans, f(i));
    cout << ans;
    return 0;
}