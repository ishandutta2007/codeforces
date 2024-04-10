#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200005;

int n, k;
vector<int> a[N];
bool c[N];

int q[N], d[N];

int ans;

void dfs(int x, int p)
{
    if (c[x])
        q[x]++;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        d[h] = d[x] + 1;
        dfs(h, x);
        q[x] += q[h];
    }
    if (c[x])
        ans += d[x];
}

void dfs1(int x, int p, int qq)
{
    bool z = false;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        if (q[h] - qq > q[x] - q[h])
        {
            ans -= ((q[x] - q[h]) * d[x]) * 2;
            dfs1(h, x, qq + q[x] - q[h]);
            z = true;
            break;
        }
    }
    if (!z)
        ans -= ((q[x] - qq) / 2 * d[x]) * 2;

}

int32_t main()
{
    cin >> n >> k;
    for (int i = 0; i < k + k; ++i)
    {
        int x;
        cin >> x;
        c[x] = true;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 0);
    dfs1(1, 0, 0);
    cout << ans << endl;
    return 0;
}