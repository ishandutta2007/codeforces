#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int manh(int a, int b, int c, int d)
{
    return max(abs(a - c), abs(b - d));
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    map<pair<int, int>, vector<int>> pts;
    int x[k], y[k];
    for(int i = 0; i < k; i++)
    {
        cin >> x[i] >> y[i];
        pts[{1, y[i] - x[i]}].push_back(i);
        pts[{-1, y[i] + x[i]}].push_back(i);
    }
    vector<int> ans(k, -1);
    char pos = 'd';
    pair<int, int> cur = {1, 0};
    int type[2] = {1, 1};
    int cx = 0, cy = 0;
    int t = 0;
    while(true)
    {
        //cout << t << ' ' << cx << ' ' << cy << ' ' << type[0] << ' ' << type[1] << endl;
        for(auto it: pts[{type[1] / type[0], cy - type[1] / type[0] * cx}])
            if(ans[it] == -1)
                ans[it] = t + manh(cx, cy, x[it], y[it]);
        if((type[0] == 1 ? n - cx : cx) < (type[1] == 1 ? m - cy : cy))
        {
            int dt = type[0] == 1 ? n - cx : cx;
            cx += type[0] * dt;
            cy += type[1] * dt;
            type[0] *= -1;
            t += dt;
        }
        else if((type[0] == 1 ? n - cx : cx) > (type[1] == 1 ? m - cy : cy))
        {
            int dt = type[1] == 1 ? m - cy : cy;
            cx += type[0] * dt;
            cy += type[1] * dt;
            type[1] *= -1;
            t += dt;
        }
        else
        {
            break;
        }
    }
    for(auto it: ans)
        cout << it << "\n";
    return 0;
}