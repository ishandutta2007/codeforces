#include <bits/stdc++.h>

using namespace std;


signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int p[n], a[n], b[n];
    for(auto &it: p)
        cin >> it;
    set<pair<int, int>> lol[5];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        lol[a[i]].insert({p[i], i});
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
        lol[b[i]].insert({p[i], i});
    }
    int m;
    cin >> m;
    while(m--)
    {
        int c;
        cin >> c;
        if(lol[c].empty())
            cout << -1 << "\n";
        else
        {
            cout << lol[c].begin()->first << "\n";
            int k = lol[c].begin()->second;
            lol[a[k]].erase({p[k], k});
            lol[b[k]].erase({p[k], k});
        }
    }
}