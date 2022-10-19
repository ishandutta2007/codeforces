#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;

int n;
vector<int> a[N];
vector<pair<int, int> > b[N];

pair<int, int> d[N];
void dfs0(int x, int p)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        d[x] = max(d[x], m_p(d[h].first + 1, d[h].second));
    }
    if (d[x].first == 0)
        d[x].second = x;
}

void dfs(int x, int p, pair<int, int> dp)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
        {
            b[x].push_back(m_p(dp.first + 1, dp.second));
            continue;
        }
        b[x].push_back(m_p(d[h].first + 1, d[h].second));
    }
    pair<int, int> max1 = m_p(0, 0), max2 = m_p(0, 0);
    for (int i = 0; i < b[x].size(); ++i)
    {
        if (b[x][i] >= max1)
        {
            max2 = max1;
            max1 = b[x][i];
        }
        else if (b[x][i] >= max2)
        {
            max2 = b[x][i];
        }
    }
    if (m_p(dp.first + 1, dp.second) >= max1)
    {
        max2 = max1;
        max1 = m_p(dp.first + 1, dp.second);
    }
    else if (m_p(dp.first + 1, dp.second) >= max2)
    {
        max2 = m_p(dp.first + 1, dp.second);
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        if (b[x][i] == max1)
            dfs(h, x, max2);
        else
            dfs(h, x, max1);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    bool z = false;
    for (int x = 1; x <= n; ++x)
    {
        if (a[x].size() >= 3)
        {
            z = true;
            break;
        }
    }
    if (!z)
    {
        printf("%d\n", n - 1);
        for (int x = 1; x <= n; ++x)
        {
            if (a[x].size() == 1)
            {
                printf("%d ", x);
            }
        }
        for (int x = 1; x <= n; ++x)
        {
            if (a[x].size() == 2)
            {
                printf("%d\n", x);
                break;
            }
        }
        return 0;
    }
    dfs0(1, 1);
    dfs(1, 1, m_p(-1, 1));
    int ans = 0;
    for (int x = 1; x <= n; ++x)
    {
        sort(b[x].begin(), b[x].end());
        reverse(b[x].begin(), b[x].end());
        if (a[x].size() >= 3)
        {
            ans = max(ans, b[x][0].first + b[x][1].first + b[x][2].first);
        }
    }
    printf("%d\n", ans);
    for (int x = 1; x <= n; ++x)
    {
        if (a[x].size() >= 3)
        {
            if (b[x][0].first + b[x][1].first + b[x][2].first == ans)
            {
                printf("%d %d %d\n", b[x][0].second, b[x][1].second, b[x][2].second);
                break;
            }
        }
    }
    return 0;
}