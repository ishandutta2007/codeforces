#include <bits/stdc++.h>

using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    set<vector<int>> que;
    map<int, map<int, int>> used;
    int n;
    cin >> n;
    int t[n];
    for(int i = 0; i < n; i++)
        cin >> t[i];
    que.insert({0, 0, 0, 0});
    while(!que.empty())
    {
        auto top = *que.begin();
        que.erase(que.begin());
        int stage = top[0];
        int dir = top[1];
        int x = top[2];
        int y = top[3];
        for(int i = 0; i < t[stage]; i++)
        {
            used[x + i * dx[dir]][y + i * dy[dir]] = 1;
            //cout << x + i * dx[dir] << ' ' << y + i * dy[dir] << endl;
        }
        if(stage + 1 != n)
        {
            que.insert({stage + 1, (dir + 7) % 8, x + (t[stage] - 1) * dx[dir] + dx[(dir + 7) % 8], y + (t[stage] - 1) * dy[dir] + dy[(dir + 7) % 8]});
            que.insert({stage + 1, (dir + 1) % 8, x + (t[stage] - 1) * dx[dir] + dx[(dir + 1) % 8], y + (t[stage] - 1) * dy[dir] + dy[(dir + 1) % 8]});
        }
    }
    int ans = 0;
    for(auto it: used)
        ans += it.second.size();
    cout << ans << endl;
    return 0;
}