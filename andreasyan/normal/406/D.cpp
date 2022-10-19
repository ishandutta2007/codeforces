#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n;
long long x[N], y[N];

struct ban
{
    int i;
    long long x, y;
    ban(){}
    ban(int i, long long x, long long y)
    {
        this->i = i;
        this->x = x;
        this->y = y;
    }
};
bool stg(const ban& t1, const ban& t2, const ban& t)
{
    return (t.x - t1.x) * (t2.y - t1.y) > (t.y - t1.y) * (t2.x - t1.x);
}

const int m = 19;
int p[N][m];

vector<int> a[N];

int tin[N], tout[N], ti;

void dfs(int x)
{
    tin[x] = ++ti;
    for (int i = 1; i < m; ++i)
        p[x][i] = p[p[x][i - 1]][i - 1];
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        dfs(h);
    }
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int lca(int x, int y)
{
    if (isp(x, y))
        return x;
    if (isp(y, x))
        return y;
    for (int i = m - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
            x = p[x][i];
    }
    return p[x][0];
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%I64d%I64d", &x[i], &y[i]);
    vector<ban> v;
    for (int i = n; i >= 1; --i)
    {
        while (v.size() >= 2)
        {
            if (stg(ban(i, x[i], y[i]), v[v.size() - 2], v[v.size() - 1]))
                v.pop_back();
            else
                break;
        }
        if (v.empty())
            p[i][0] = i;
        else
            p[i][0] = v.back().i;
        v.push_back(ban(i, x[i], y[i]));
    }
    for (int i = 1; i < n; ++i)
        a[p[i][0]].push_back(i);
    dfs(n);
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d ", lca(x, y));
    }
    printf("\n");
    return 0;
}