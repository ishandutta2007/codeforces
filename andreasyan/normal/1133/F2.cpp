#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

int n, m, d;
vector<int> a[N];

int k;
int c[N];
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

vector<pair<int, int> > ans;

bool cc[N];

void dfs1(int x)
{
    cc[x] = true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!cc[h])
        {
            ans.push_back(m_p(x, h));
            dfs1(h);
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (y != 1)
            a[x].push_back(y);
        if (x != 1)
            a[y].push_back(x);
    }
    for (int i = 2; i <= n; ++i)
    {
        if (!c[i])
        {
            ++k;
            dfs(i);
        }
    }
    if (d < k)
    {
        printf("NO\n");
        return 0;
    }
    if (d > a[1].size())
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    set<int> s;
    for (int i = 0; i < a[1].size(); ++i)
    {
        int h = a[1][i];
        if (s.find(c[h]) == s.end())
        {
            ans.push_back(m_p(1, h));
            s.insert(c[h]);
            cc[h] = true;
        }
    }
    d -= k;
    for (int i = 0; i < a[1].size(); ++i)
    {
        int h = a[1][i];
        if (cc[h])
            continue;
        if (d > 0)
        {
            ans.push_back(m_p(1, h));
            cc[h] = true;
            --d;
        }
    }
    cc[1] = true;
    for (int i = 0; i < a[1].size(); ++i)
    {
        int h = a[1][i];
        if (cc[h])
            dfs1(h);
    }
    for (int i = 0; i < n - 1; ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}