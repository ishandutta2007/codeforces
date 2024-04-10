#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>

using namespace std;

const int N = 3e5 + 7;

vector <int> g[N];
vector <int> rg[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        g[i].push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        sort(g[i].begin(), g[i].end());
    }
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    sort(a.begin(), a.end(), [] (int a, int b)
    {
        return g[a] < g[b];
    });
    vector <int> res(n);
    for (int i = 1; i < n; i++)
    {
        if (g[a[i]] != g[a[i - 1]])
        {
            res[a[i]] = res[a[i - 1]] + 1;
        }
        else
        {
            res[a[i]] = res[a[i - 1]];
        }
    }
    int mx = res[a[n - 1]];
    for (int i = 0; i < n; i++)
    {
        for (auto to : g[i])
        {
            rg[res[i]].push_back(res[to]);
        }
    }
    for (int i = 0; i <= mx; i++)
    {
        sort(rg[i].begin(), rg[i].end());
        rg[i].resize(unique(rg[i].begin(), rg[i].end()) - rg[i].begin());
    }
    vector <int> col(n);
    int j = 0;
    int cnt = 0;
    for (int i = 0; i <= mx; i++)
    {
        if (rg[i].size() > 3)
        {
            puts("NO");
            return 0;
        }
        else
        {
            if (rg[i].size() == 2)
            {
                j = i;
                cnt++;
            }
        }
    }
    if (cnt == 2 || mx == 0)
    {
        puts("YES");
        int cur = j;
        col[cur] = 1;
        int pr = -1;
        while (1)
        {
            int w = cur;
            for (auto to : rg[cur])
            {
                if (to != cur && to != pr)
                {
                    col[to] = col[cur] + 1;
                    pr = cur;
                    cur = to;
                    break;
                }
            }
            if (cur == w)
            {
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d ", col[res[i]]);
        }
        puts("");
    }
    else
    {
        puts("NO");
    }
}