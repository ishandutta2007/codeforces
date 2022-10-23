#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e5 + 10;
int p[N], n, ip[N], vis[N];
vi a[N];

void dfs(int u)
{
    for (int x : a[u])
    {
        cout << x << " ";
        if (!a[x].empty()) dfs(x);
    }
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> p[i], ip[p[i]] = i, vis[i] = 0, a[i].clear();
        vector<vi> cycle;
        for (int i = 1; i <= n; ++i)
        if (!vis[i])
        {
            int x = i;
            vi vt;
            while (!vis[x])
            {
                vis[x] = 1;
                vt.eb(x);
                x = ip[x];
            }
            if ((int)vt.size() > 1) rotate(vt.begin(), vt.begin() + 1, vt.end());
            a[vt.back() - 1] = vt;
            cycle.eb(vt);
        }
        dfs(0);
        cout << "\n";
    }
    return 0;
}