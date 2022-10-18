#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1.5e6;
vector<int> qui[maxn], quo[maxn];

signed main()
{
    //freopen("../input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int d[m], f[m], t[m], c[m];
    set<pair<int, int>> in[n + 1], out[n + 1];
    for(int i = 0; i < m; i++)
    {
        cin >> d[i] >> f[i] >> t[i] >> c[i];
        if(f[i] != 0 && t[i] != 0)
            continue;
        if(t[i] == 0)
            qui[d[i]].push_back(i);
        else if(d[i] >= k)
            out[t[i]].insert({c[i], d[i]}),
            quo[d[i]].push_back(i);
    }
    int ans = 1e18;
    int sumo = 0, sumi = 0;
    int empty_o = 0;
    int empty_i = n;
    for(int i = 1; i <= n; i++)
    {
        if(out[i].empty())
            empty_o++;
        else
            sumo += out[i].begin()->first;
    }
    for(int i = 0; i < maxn; i++)
    {
        if(i + k - 1 < maxn)
        for(auto it: quo[i + k - 1])
        {
            sumo -= out[t[it]].begin()->first;
            out[t[it]].erase({c[it], d[it]});
            if(out[t[it]].empty())
                empty_o++;
            else
                sumo += out[t[it]].begin()->first;
        }
        if(empty_o == 0 && empty_i == 0)
            ans = min(ans, sumo + sumi);
        for(auto it: qui[i])
        {
            if(in[f[it]].empty())
                empty_i--;
            else
                sumi -= in[f[it]].begin()->first;
            in[f[it]].insert({c[it], d[it]});
            sumi += in[f[it]].begin()->first;
        }
    }
    if(ans == 1e18)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}