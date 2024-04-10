#include <bits/stdc++.h>
using namespace std;
const int N = 300005, INF = 1000000009;

int n;
int a[N];
multiset<int> s;
vector<int> g[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = INF;
    for (int x = 1; x <= n; ++x)
    {
        int yans = a[x];
        s.erase(s.find(a[x]));
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            yans = max(yans, a[h] + 1);
            s.erase(s.find(a[h]));
        }
        if (!s.empty())
            yans = max(yans, *(--s.end()) + 2);
        ans = min(ans, yans);
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            s.insert(a[h]);
        }
        s.insert(a[x]);
    }
    cout << ans << endl;
    return 0;
}