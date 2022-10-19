#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 300005;
struct ban
{
    int s;
    int x;
    long long d;
    ban(){}
    ban(int x, long long d)
    {
        this->x = x;
        this->d = d;
    }
    ban(int s, int x, long long d)
    {
        this->s = s;
        this->x = x;
        this->d = d;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.d > b.d;
}

int n, m, k, q;
pair<pair<int, int>, int> b[N];
vector<ban> a[N];

bool c[N];
int s[N];
long long d[N];
void djk()
{
    priority_queue<ban> q;
    for (int i = 1; i <= k; ++i)
    {
        q.push(ban(i, i, 0));
    }
    while (1)
    {
        ban t;
        do
        {
            if (q.empty())
                return;
            t = q.top();
            q.pop();
        } while (c[t.x]);
        c[t.x] = true;
        d[t.x] = t.d;
        s[t.x] = t.s;
        for (int i = 0; i < a[t.x].size(); ++i)
        {
            ban h = a[t.x][i];
            h.s = t.s;
            h.d += t.d;
            if (!c[h.x])
                q.push(h);
        }
    }
}

vector<pair<long long, pair<int, int> > > v;

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}
void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

vector<ban> g[N];
const int l = 20;
int pp[N][l];
long long maxu[N][l];
int ti, tin[N], tout[N];

void dfs(int x, int yp, long long yd)
{
    tin[x] = ++ti;
    pp[x][0] = yp;
    maxu[x][0] = yd;
    for (int i = 1; i < l; ++i)
    {
        pp[x][i] = pp[pp[x][i - 1]][i - 1];
        maxu[x][i] = max(maxu[x][i - 1], maxu[pp[x][i - 1]][i - 1]);
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        ban h = g[x][i];
        if (h.x == yp)
            continue;
        dfs(h.x, x, h.d);
    }
    tout[x] = ti;
}
bool is_p(int x, int y)
{
    return (tin[x] <= tin[y] && tout[x] >= tout[y]);
}
long long go(int x, int y)
{
    if (is_p(x, y))
        return 0;
    long long ans = 0;
    for (int i = l - 1; i >= 0; --i)
    {
        if (!is_p(pp[x][i], y))
        {
            ans = max(ans, maxu[x][i]);
            x = pp[x][i];
        }
    }
    ans = max(ans, maxu[x][0]);
    return ans;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x].push_back(ban(y, z));
        a[y].push_back(ban(x, z));
        b[i] = m_p(m_p(x, y), z);
    }
    djk();
    for (int i = 0; i < m; ++i)
    {
        int x = b[i].first.first;
        int y = b[i].first.second;
        int z = b[i].second;
        if (s[x] != s[y])
        {
            v.push_back(m_p(d[x] + z + d[y], m_p(s[x], s[y])));
        }
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= k; ++i)
        p[i] = i;
    for (int i = 0; i < v.size(); ++i)
    {
        long long d = v[i].first;
        int x = v[i].second.first;
        int y = v[i].second.second;
        if (fi(x) != fi(y))
        {
            kpc(x, y);
            g[x].push_back(ban(y, d));
            g[y].push_back(ban(x, d));
        }
    }
    dfs(1, 1, 0);
    while (q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%lld\n", max(go(x, y), go(y, x)));
    }
    return 0;
}