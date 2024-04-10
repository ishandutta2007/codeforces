#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;

int n, m;
vector<pair<int, int> > a[N];

bool c[N];
void bfs(int x, int d[])
{
    queue<int> q;
    memset(c, false, sizeof c);
    d[x] = 0;
    q.push(x);
    c[x] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i].first;
            if (!c[h])
            {
                c[h] = true;
                d[h] = d[x] + 1;
                q.push(h);
            }
        }
    }
}

int d1[N], dn[N];

vector<pair<int, int> > b[N];

int dp[N];
void dfs(int x)
{
    c[x] = true;
    for (int i = 0; i < b[x].size(); ++i)
    {
        int h = b[x][i].first;
        if (!c[h])
            dfs(h);
        dp[x] = max(dp[x], dp[h] + b[x][i].second);
    }
}

struct ban
{
    int x, y, z;
    ban(){}
    ban(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

vector<ban> ans;
set<pair<int, int> > s;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x].push_back(m_p(y, z));
        a[y].push_back(m_p(x, z));
    }
    bfs(1, d1);
    bfs(n, dn);
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int y = a[x][i].first;
            if (d1[x] + 1 + dn[y] == d1[n])
            {
                b[x].push_back(a[x][i]);
            }
        }
    }
    memset(c, false, sizeof c);
    dfs(1);
    int x = 1;
    while (x != n)
    {
        pair<int, int> y;
        for (int i = 0; i < b[x].size(); ++i)
        {
            int h = b[x][i].first;
            if (dp[x] == dp[h] + b[x][i].second)
            {
                y = b[x][i];
                break;
            }
        }
        if (y.second == 0)
            ans.push_back(ban(x, y.first, 1));
        s.insert(m_p(x, y.first));
        s.insert(m_p(y.first, x));
        x = y.first;
    }
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int y = a[x][i].first;
            if (x < y && s.find(m_p(x, y)) == s.end() && a[x][i].second == 1)
                ans.push_back(ban(x, y, 0));
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].z);
    return 0;
}