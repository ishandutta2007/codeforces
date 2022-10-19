#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N];
vector<int> g[N];

bool c[N];
int q[N];

void dfs0(int x, int p)
{
    q[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (c[h])
            continue;
        dfs0(h, x);
        q[x] += q[h];
    }
}
int dfs(int x, int p, int xx)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (c[h])
            continue;
        if (q[h] > q[xx] / 2)
            return dfs(h, x, xx);
    }
    return x;
}

int center(int x)
{
    dfs0(x, x);
    return dfs(x, x, x);
}

long long ans;

vector<int> v;
void dfs1(int x, int p, int xx)
{
    v.push_back(xx);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (c[h])
            continue;
        if (h == p)
            continue;
        dfs1(h, x, xx ^ a[h]);
    }
}

const int m = 20;

void solv(int y)
{
    v.clear();
    dfs1(y, y, a[y]);

    int q[m][2] = {};
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if ((v[i] & (1 << j)))
                q[j][1]++;
            else
                q[j][0]++;
        }
    }

    for (int i = 0; i < v.size(); ++i)
        ans += v[i];

    for (int ii = 0; ii < g[y].size(); ++ii)
    {
        int h = g[y][ii];
        if (c[h])
            continue;
        v.clear();
        dfs1(h, y, a[h]);

        for (int i = 0; i < v.size(); ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (((a[y] ^ v[i]) & (1 << j)))
                    q[j][1]--;
                else
                    q[j][0]--;
            }
        }

        for (int i = 0; i < v.size(); ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if ((v[i] & (1 << j)))
                    ans += ((1 << j) * 1LL * q[j][0]);
                else
                    ans += ((1 << j) * 1LL * q[j][1]);
            }
        }

        for (int i = 0; i < v.size(); ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (((a[y] ^ v[i]) & (1 << j)))
                    q[j][1]++;
                else
                    q[j][0]++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        int y = center(x);
        solv(y);
        c[y] = true;
        for (int i = 0; i < g[y].size(); ++i)
        {
            int h = g[y][i];
            if (c[h])
                continue;
            q.push(h);
        }
    }

    for (int i = 1; i <= n; ++i)
        ans += a[i];
    ans /= 2;
    cout << ans << endl;
    return 0;
}