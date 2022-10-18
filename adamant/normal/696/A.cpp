#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    map<int, int> price;
    while(q--)
    {
        int t, u, v;
        cin >> t >> u >> v;
        map<int, int> path;
        do {path[u]--; u /= 2;} while(u > 0);
        do {path[v]--; v /= 2;} while(v > 0);
        for(auto it: path)
            path[it.first] += 2;
        if(t == 2)
        {
            int ans = 0;
            for(auto it: path)
                ans += price[it.first] * it.second;
            cout << ans << "\n";
        }
        else
        {
            int w;
            cin >> w;
            for(auto it: path)
                if(it.second)
                    price[it.first] += w;
        }
    }
	return 0;
}