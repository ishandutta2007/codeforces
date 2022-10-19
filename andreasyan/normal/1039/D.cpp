#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005;

int n;
vector<int> a[N];

pair<int, int> dp[N];

vector<int> v;
void dfs0(int x, int p)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
    }
    v.push_back(x);
}

void solvv(int k)
{
    memset(dp, 0, sizeof dp);
    for (int ii = 0; ii < n; ++ii)
    {
        int x = v[ii];
        int max1 = 0, max2 = 0;
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            dp[x].first += dp[h].first;
            if (dp[h].second >= max1)
            {
                max2 = max1;
                max1 = dp[h].second;
            }
            else if (dp[h].second > max2)
                max2 = dp[h].second;
        }
        if (max1 + max2 + 1 >= k)
            dp[x].first++;
        else
            dp[x].second = max1 + 1;
    }
}

int ans[N];

bool c[N];
int solv(int k)
{
    if (!c[k])
    {
        c[k] = true;
        solvv(k);
        ans[k] = dp[1].first;
    }
    return ans[k];
}

int ka()
{
    int x = 0;
    while (1)
    {
        char y;
        y = getchar();
        if ('0' <= y && y <= '9')
        {
            x *= 10;
            x += (y - '0');
        }
        else
            return x;
    }
}

char t[10];
void tp(int x)
{
    if (!x)
    {
        putchar('0');
    }
    else
    {
        int u = 0;
        while (x)
        {
            t[++u] = (x % 10) + '0';
            x /= 10;
        }
        for (int i = u; i >= 1; --i)
            putchar(t[i]);
    }
    putchar('\n');
}

int main()
{
    n = ka();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        x = ka();
        y = ka();
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs0(1, 1);
    for (int i = 1; i <= n; ++i)
    {
        int u = solv(i);
        if (i <= 500)
            continue;
        if (u == 0)
            break;
        int k = i;
        int l = i, r = n;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (solv(m) == u)
            {
                k = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        for (int j = i + 1; j <= k; ++j)
            ans[j] = u;
        i = k;
    }
    for (int i = 1; i <= n; ++i)
        tp(ans[i]);
    return 0;
}