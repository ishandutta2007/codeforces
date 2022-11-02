#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 100009;
vector<int> a[MAX_N];
int n, m;
map<int, int> mp;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x - 1].push_back(-y);
    }
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < m; i++)
    {
        if (a[i].empty())
            continue;
        sort(a[i].begin(), a[i].end());
        if (-a[i][0] > 0)
        {
            mp.emplace(i, -a[i][0]);
            cur -= a[i][0];
        }
    }
    ans = cur;
    for (int j = 1; !mp.empty(); j++)
    {
        cur = 0;
        vector<int> er;
        for (auto e = mp.begin(); e != mp.end(); e++)
        {
            int i = (*e).first;
            int w = (*e).second;
            if (a[i].size() <= j || w - a[i][j] <= 0)
                er.push_back(i);
            else
            {
                (*e).second -= a[i][j];
                cur += (*e).second;
            }
        }
        for (int i : er)
            mp.erase(i);
        ans = max(ans, cur);
    }
    cout << ans;
}