#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 42, mod = 1e9 + 7;
int par[maxn], sz[maxn];

int fact[maxn];
vector<pair<int, int>> mask[maxn];
map<vector<pair<int, int>>, int> cnt;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    fact[0] = 1;
    for(int i = 1; i < maxn; i++)
        fact[i] = 1LL * i * fact[i - 1] % mod;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int g;
        cin >> g;
        map<int, int> cnt;
        for(int i = 0; i < g; i++)
        {
            int t;
            cin >> t;
            cnt[t]++;
        }
        for(auto it: cnt)
            mask[it.first].push_back({i, it.second});
    }
    for(int i = 1; i <= m; i++)
        cnt[mask[i]]++;
    int ans = 1;
    for(auto it: cnt)
        ans = 1LL * ans * fact[it.second] % mod;
    cout << ans << endl;
    return 0;
}