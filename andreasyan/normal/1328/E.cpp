#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;

int n, m;
vector<int> a[N];

int d[N];
int tin[N], tout[N], ti;
int p[N];
void dfs(int x, int pp)
{
    d[x] = d[pp] + 1;
    tin[x] = ++ti;
    p[x] = pp;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == pp)
            continue;
        dfs(h, x);
    }
    tout[x] = ++ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1);
    while (m--)
    {
        int q;
        scanf("%d", &q);
        vector<pair<int, int> > v;
        for (int i = 0; i < q; ++i)
        {
            int x;
            scanf("%d", &x);
            v.push_back(m_p(d[x], p[x]));
        }
        sort(v.begin(), v.end());
        bool z = true;
        for (int i = 0; i < q - 1; ++i)
        {
            if (!isp(v[i].second, v[i + 1].second))
            {
                z = false;
                break;
            }
        }
        if (z)
            printf("YES\n");
        else
            printf("NO\n");
    }
}