#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100005;

int n;
vector<int> a[N];

int c[N];

int k;
void dfs(int x)
{
    c[x] = k;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            dfs(h);
    }
}

int ans[N];
int32_t main()
{
    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 2; j * i <= n; ++j)
        {
            a[i].push_back(j * i);
            a[j * i].push_back(i);
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        if (!c[i])
        {
            ++k;
            dfs(i);
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int x = 0; x < a[i].size(); ++x)
        {
            int j = a[i][x];
            if (i % j == 0)
                ans[c[i]] += (i / j * 4);
        }
    }
    int maxu = 0;
    for (int i = 1; i <= k; ++i)
        maxu = max(maxu, ans[i]);
    cout << maxu << endl;
    return 0;
}