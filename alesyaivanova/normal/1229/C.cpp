#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double

const int MAXN = 100009;
vector<int> g[MAXN];
int c[MAXN];
vector<int> kek[MAXN];
int n, m;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        c[i] = i;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
        if (a > b)
            kek[b].pb(a);
        else
            kek[a].pb(b);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (int)kek[i].size() * ((int)g[i].size() - (int)kek[i].size());
    cout << ans << "\n";
    int q;
    cin >> q;
    for (int j = n; j < n + q; j++)
    {
        int v;
        cin >> v;
        v--;
        for (int to : kek[v])
        {
            kek[to].pb(v);
            ans += ((int)g[to].size() - (int)kek[to].size()) - ((int)kek[to].size() - 1);
        }
        ans -= (int)kek[v].size() * ((int)g[v].size() - (int)kek[v].size());
        kek[v].resize(0);
        c[v] = j;
        cout << ans << "\n";
    }
}