#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
vector<pair<int, int> > a[N];

int maxu[N];
void dfs(int x, int p)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
            continue;
        dfs(h, x);
        maxu[x] = max(maxu[x], maxu[h] + a[x][i].second);
    }
}

int main()
{
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back(make_pair(y, z));
        a[y].push_back(make_pair(x, z));
        ans += (z * 2);
    }
    dfs(1, 1);
    ans -= maxu[1];
    cout << ans << endl;
    return 0;
}