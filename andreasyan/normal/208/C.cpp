#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n, m;
pair<int, int> b[N * N];
vector<int> a[N];

bool c[N];
int d[N];
void bfs()
{
    queue<int> q;
    c[1] = true;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (!c[h])
            {
                c[h] = true;
                d[h] = d[x] + 1;
                q.push(h);
            }
        }
    }
}

vector<int> g[N];

bool cc[N][N];
long long q[N][N * N];

void dfs(int x)
{
    c[x] = true;
    if (x == n)
    {
        q[n][0] = 1;
        return;
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
            dfs(h);
        if (!cc[x][h])
        {
            for (int j = 0; j <= n + n; ++j)
            {
                q[x][j] += q[h][j];
            }
        }
        else
        {
            for (int j = 0; j <= n; ++j)
            {
                q[x][j + 1] += q[h][j];
            }
        }
    }
}

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(11);
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i].first >> b[i].second;
        a[b[i].first].push_back(b[i].second);
        a[b[i].second].push_back(b[i].first);
    }
    bfs();
    for (int i = 0; i < m; ++i)
    {
        if (d[b[i].first] + 1 == d[b[i].second])
            g[b[i].first].push_back(b[i].second);
        if (d[b[i].second] + 1 == d[b[i].first])
            g[b[i].second].push_back(b[i].first);
    }
    long double ans = 0;
    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= n; ++y)
        {
            c[y] = false;
            memset(q[y], 0, sizeof q[y]);
        }
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            cc[x][h] = true;
            cc[h][x] = true;
        }
        dfs(1);
        long long gg = 0;
        long long qq = 0;
        for (int i = 0; i <= n + n; ++i)
        {
            gg += (q[1][i] * i);
            qq += (q[1][i]);
        }
        ans = max(ans, (long double)gg / qq);
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            cc[x][h] = false;
            cc[h][x] = false;
        }
    }
    cout << ans << endl;
    return 0;
}