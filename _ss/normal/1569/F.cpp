#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e2 + 10;
int a[N][N], n, m, k, adj[N][N], dp[N][6];

bool check(vi lef, vi rig)
{
    int d = n / 2;
    for (int i = 0; i < d; ++i)
        for (int j = 0; j < d; ++j)
            adj[i][j] = (a[lef[i]][lef[j]] && a[rig[i]][rig[j]]) || (a[lef[i]][rig[j]] && a[rig[i]][lef[j]]);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < d; ++i)
        if (a[lef[i]][rig[i]]) dp[1 << i][i] = 1;
    for (int mask = 1; mask < (1 << d); ++mask)
        for (int pos = 0; pos < d; ++pos)
            if (dp[mask][pos])
                for (int nxt = 0; nxt < d; ++nxt)
                    if (((mask >> nxt) & 1) == 0 && adj[pos][nxt]) dp[mask | (1 << nxt)][nxt] = 1;
    for (int i = 0; i < d; ++i)
        if (dp[(1 << d) - 1][i]) return true;
    return false;
}

set<vector<vi>> st[10];

void gen(vi &lef, vi &rig, vector<vi> vt, int id)
{
    if (id == n / 2)
    {
        st[vt.size()].insert(vt);
        return;
    }
    for (int i = 0; i < (int)vt.size(); ++i)
    {
        vector<vi> tmp = vt;
        tmp[i].eb(lef[id]);
        tmp[i].eb(rig[id]);
        sort(all(tmp[i]));
        gen(lef, rig, tmp, id + 1);
    }
    vt.pb({lef[id], rig[id]});
    gen(lef, rig, vt, id + 1);
}

int fact[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1, u, v; i <= m; ++i)
    {
        cin >> u >> v;
        u--;
        v--;
        a[u][v] = a[v][u] = 1;
    }
    for (int mask = 0; mask < (1 << n); ++mask)
        if (__builtin_popcount(mask) == n / 2 && mask & 1)
        {
            vi lef, rig;
            for (int i = 0; i < n; ++i)
                if ((mask >> i) & 1) lef.eb(i);
                else rig.eb(i);
            while (true)
            {
                int flag = 1;
                for (int i = 0; i < n / 2; ++i)
                    if (lef[i] > rig[i]) flag = 0;
                if (flag && check(lef, rig))
                {
                    vector<vi> vt;
                    gen(lef, rig, vt, 0);
                }
                if (!next_permutation(all(rig))) break;
            }
        }
    fact[0] = 1;
    for (int i = 1; i <= k; ++i) fact[i] = fact[i - 1] * i;
    ll res = 0;
    for (int i = 1; i <= min(k, n / 2); ++i)
    {
        res += (ll)fact[k] / fact[k - i] * st[i].size();
        /*cout << i << " " << st[i].size() << "\n";
        for (vector<vi> vt : st[i])
        {
            for (int j = 0; j < i; ++j)
            {
                for (int x : vt[j]) cout << x << " ";
                cout << "\n";
            }
            cout << "\n";
        }
        cout << "\n";*/
    }
    cout << res;
    return 0;
}