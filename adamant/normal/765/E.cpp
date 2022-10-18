#include <bits/stdc++.h>

using namespace std;

void fail()
{
    cout << -1 << endl;
    exit(0);
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> g[n];
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u - 1].insert(v - 1);
        g[v - 1].insert(u - 1);
    }
    set<int> pathes[n];
    int degree[n];
    set<pair<int, int>> lol;
    for(int i = 0; i < n; i++)
    {
        degree[i] = g[i].size();
        if(degree[i] == 1)
        {
            pathes[i] = {0};
            lol.insert({pathes[i].size(), i});
        }
    }
    while(!lol.empty())
    {
        int v = lol.begin()->second;
        //cout << v << ' ' << lol.begin()->first << ' ' << degree[v] << endl;
        lol.erase(begin(lol));
        if(degree[v] > 1)
            fail();
        if(degree[v] == 0)
        {
            if(pathes[v].size() > 2)
                fail();
            int ans = 0;
            for(auto it: pathes[v])
                ans += it;
            while(ans % 2 == 0)
                ans /= 2;
            cout << ans << endl;
            return 0;
        }
        if(pathes[v].size() > 1)
            fail();
        //cout << v << endl;
        int u = *begin(g[v]);
        pathes[u].insert(*begin(pathes[v]) + 1);
        //cout << "!! " << u << ' ' << *begin(pathes[u]) << ' ' << *begin(pathes[v]) << endl;
        degree[u]--;
        g[u].erase(v);
        if(degree[u] == 1)
            lol.insert({pathes[u].size(), u});
    }

}