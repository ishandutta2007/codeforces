#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int s;

int n, qq;
int p[N];
vector<int> g[N];
long long a[N], b[N];

int ti, tin[N], tout[N];
int rtin[N];
void dfs0(int x)
{
    tin[x] = ++ti;
    rtin[tin[x]] = x;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfs0(h);
    }
    tout[x] = ti;
}

vector<int> v[N];
bool so(const int& x, const int& y)
{
    return b[x] < b[y];
}

struct ban
{
    long long b, k;
    ban(){}
    ban(long long b, long long k)
    {
        this->b = b;
        this->k = k;
    }
    long long y(long long x)
    {
        return b + k * x;
    }
};
long double hat(const ban& a, const ban& b)
{
    return (long double)(b.b - a.b) / (a.k - b.k);
}

int ii[N];
vector<ban> t[N];
vector<long double> xx[N];
void ave(int i, ban u)
{
    while (t[i].size() >= 2)
    {
        if (u.k == t[i].back().k)
        {
            if (u.b > t[i].back().b)
            {
                t[i].pop_back();
                xx[i].pop_back();
                continue;
            }
            else
                return;
        }
        if (xx[i].back() >= hat(t[i].back(), u))
        {
            t[i].pop_back();
            xx[i].pop_back();
        }
        else
            break;
    }
    if (!t[i].empty())
        xx[i].push_back(hat(t[i].back(), u));
    t[i].push_back(u);
}

void bil(int i)
{
    ii[i] = 0;
    t[i].clear();
    xx[i].clear();
    for (int j = (int)v[i].size() - 1; j >= 0; --j)
    {
        int x = v[i][j];
        ave(i, ban(-a[x] * b[x], -b[x]));
    }
    for (int j = 0; j < v[i].size(); ++j)
    {
        int x = v[i][j];
        ave(i, ban(a[x] * b[x], b[x]));
    }
    while (ii[i] < xx[i].size() && 0 >= xx[i][ii[i]])
        ++ii[i];
}

long long d[N];
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &qq);
    for (int x = 2; x <= n; ++x)
    {
        scanf("%d", &p[x]);
        g[p[x]].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &b[i]);
    for (int x = 1; x <= n; ++x)
    {
        a[x] = a[p[x]] + a[x];
        b[x] = b[p[x]] + b[x];
    }
    for (int x = 1; x <= n; ++x)
        b[x] = abs(b[x]);
    dfs0(1);
//////////////////////////////////////////
    s = 200;
    for (int x = 1; x <= n; ++x)
    {
        v[tin[x] / s].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i == 1 || (i / s) != ((i - 1) / s))
        {
            sort(v[i / s].begin(), v[i / s].end(), so);
            bil(i / s);
        }
    }
    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int uu;
            long long aa;
            scanf("%d%lld", &uu, &aa);
            int l = tin[uu], r = tout[uu];
            if ((l / s) == (r / s))
            {
                for (int j = 0; j < v[l / s].size(); ++j)
                {
                    int x = v[l / s][j];
                    a[x] += d[l / s];
                }
                d[l / s] = 0;
                for (int j = l; j <= r; ++j)
                {
                    int x = rtin[j];
                    a[x] += aa;
                }
                bil(l / s);
                continue;
            }
            for (int j = 0; j < v[l / s].size(); ++j)
            {
                int x = v[l / s][j];
                a[x] += d[l / s];
            }
            d[l / s] = 0;
            for (int j = l; j <= n && (j / s) == (l / s); ++j)
            {
                int x = rtin[j];
                a[x] += aa;
            }
            bil(l / s);
            for (int j = 0; j < v[r / s].size(); ++j)
            {
                int x = v[r / s][j];
                a[x] += d[r / s];
            }
            d[r / s] = 0;
            for (int j = r; j >= 1 && (j / s) == (r / s); --j)
            {
                int x = rtin[j];
                a[x] += aa;
            }
            bil(r / s);
            for (int i = (l / s) + 1; i <= (r / s) - 1; ++i)
            {
                d[i] += aa;
                while (ii[i] < xx[i].size() && d[i] >= xx[i][ii[i]])
                    ++ii[i];
            }
        }
        else
        {
            int uu;
            scanf("%d", &uu);
            int l = tin[uu], r = tout[uu];
            long long ans = 0;
            if ((l / s) == (r / s))
            {
                for (int j = l; j <= r; ++j)
                {
                    int x = rtin[j];
                    ans = max(ans, abs(a[x] + d[l / s]) * b[x]);
                }
                printf("%lld\n", ans);
                continue;
            }
            for (int j = l; j <= n && (j / s) == (l / s); ++j)
            {
                int x = rtin[j];
                ans = max(ans, abs(a[x] + d[l / s]) * b[x]);
            }
            for (int j = r; j >= 1 && (j / s) == (r / s); --j)
            {
                int x = rtin[j];
                ans = max(ans, abs(a[x] + d[r / s]) * b[x]);
            }
            for (int i = (l / s) + 1; i <= (r / s) - 1; ++i)
            {
                ans = max(ans, t[i][ii[i]].y(d[i]));
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}