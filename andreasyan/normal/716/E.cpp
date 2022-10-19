#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005;

long long phi(long long n)
{
    long long ans = n;
    for (long long i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            ans -= ans / i;
        }
    }
    if (n > 1)
        ans -= ans / n;
    return ans;
}

int n;
long long M;
vector<pair<int, int> > a[N];

long long astt(long long x, long long n)
{
    long long ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * x) % M;
        x = (x * x) % M;
        n /= 2;
    }
    return ans;
}

long long rast[N], ast[N];
void pre()
{
    long long u = astt(10, phi(M) - 1);
    ast[0] = 1;
    rast[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        ast[i] = (ast[i - 1] * 10) % M;
        rast[i] = (rast[i - 1] * u) % M;
    }
}

bool c[N];
int q[N];
void dfsq(int x, int p)
{
    q[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (c[h])
            continue;
        if (h == p)
            continue;
        dfsq(h, x);
        q[x] += q[h];
    }
}

int dfsc(int x, int p, int xx)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (c[h])
            continue;
        if (h == p)
            continue;
        if (q[h] > q[xx] / 2)
            return dfsc(h, x, xx);
    }
    return x;
}

long long ans;
map<long long, int> mp;

long long d[N], u[N];
int dd[N];
void dfs0(int x, int p, int dp)
{
    if (x != p)
    {
        dd[x] = dd[p] + 1;
        d[x] = (d[p] * 10 + dp) % M;
        u[x] = (dp * ast[dd[x] - 1] + u[p]) % M;
        if (d[x] == 0)
            ++ans;
        if (u[x] == 0)
            ++ans;
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (c[h])
            continue;
        if (h == p)
            continue;
        dfs0(h, x, a[x][i].second);
    }
}

void dfs(int x, int p, int y)
{
    mp[(d[x] * rast[dd[x]]) % M] += y;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (c[h])
            continue;
        if (h == p)
            continue;
        dfs(h, x, y);
    }
}

void dfs1(int x, int p)
{
    ans += mp[(M - u[x]) % M];
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (c[h])
            continue;
        if (h == p)
            continue;
        dfs1(h, x);
    }
}

void solv(int x)
{
    u[x] = d[x] = dd[x] = 0;
    dfs0(x, x, x);
    mp.clear();
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (c[h])
            continue;
        dfs(h, x, 1);
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (c[h])
            continue;
        dfs(h, x, -1);
        dfs1(h, x);
        dfs(h, x, 1);
    }
}

int main()
{
    scanf("%d%d", &n, &M);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x].push_back(m_p(y, z));
        a[y].push_back(m_p(x, z));
    }
    pre();
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        dfsq(x, x);
        x = dfsc(x, x, x);
        solv(x);
        c[x] = true;
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i].first;
            if (c[h])
                continue;
            q.push(h);
        }
    }
    cout << ans << endl;
    return 0;
}