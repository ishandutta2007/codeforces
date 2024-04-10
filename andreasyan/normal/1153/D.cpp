#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n;
int t[N];
vector<int> a[N];

int q[N];
void dfs0(int x)
{
    if (a[x].empty())
        q[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        dfs0(h);
        q[x] += q[h];
    }
}

int dp[N];

void dfs(int x)
{
    if (a[x].empty())
    {
        dp[x] = 1;
        return;
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        dfs(h);
    }
    if (t[x] == 0)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            dp[x] += (dp[h] - 1);
        }
        dp[x]++;
    }
    else
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            dp[x] = max(dp[x], q[x] - q[h] + dp[h]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    for (int y = 2; y <= n; ++y)
    {
        int x;
        cin >> x;
        a[x].push_back(y);
    }
    dfs0(1);
    dfs(1);
    cout << dp[1] << endl;
    return 0;
}