#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;
struct ban
{
    int i;
    int x, y, z;
    ban()
    {
        i = 0;
        x = y = z = 0;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.z < b.z;
}

int n, m;
ban b[N];

vector<int> a[N];
int c[N];

bool dfs(int x)
{
    c[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
        {
            if (dfs(h))
                return true;
        }
        else if (c[h] == 1)
            return true;
    }
    c[x] = 2;
    return false;
}

bool stg(int x)
{
    for (int i = 1; i <= n; ++i)
        a[i].clear();
    memset(c, 0, sizeof c);
    for (int i = x + 1; i <= m; ++i)
    {
        a[b[i].x].push_back(b[i].y);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            if (dfs(i))
                return false;
        }
    }
    return true;
}

int u[N];
vector<int> v;
void dfs1(int x)
{
    c[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            dfs1(h);
    }
    v.push_back(x);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        b[i].i = i;
        scanf("%d%d%d", &b[i].x, &b[i].y, &b[i].z);
    }
    sort(b + 1, b + m + 1);
    int l = 0, r = m;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    printf("%d ", b[ans].z);
    for (int i = 1; i <= n; ++i)
        a[i].clear();
    memset(c, 0, sizeof c);
    for (int i = ans + 1; i <= m; ++i)
    {
        a[b[i].x].push_back(b[i].y);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
            dfs1(i);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
        u[v[i]] = i;
    vector<int> yans;
    for (int i = 1; i <= ans; ++i)
    {
        if (u[b[i].x] > u[b[i].y])
            yans.push_back(b[i].i);
    }
    printf("%d\n", yans.size());
    for (int i = 0; i < yans.size(); ++i)
        printf("%d ", yans[i]);
    printf("\n");
    return 0;
}