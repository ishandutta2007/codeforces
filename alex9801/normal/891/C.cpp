#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>

using namespace std;

struct edg
{
    int x, y, w;
    bool operator <(const edg &a) const
    {
        return w < a.w;
    }
};

int par[500010];
int rnk[500010];

vector<pair<int, int>> pdes;
vector<pair<int, int>> rdes;

int root(int x)
{
    if(x == par[x])
        return x;

    int t = root(par[x]);
    pdes.push_back({ x, par[x] });
    par[x] = t;
    return t;
}

bool merge(int x, int y)
{
    x = root(x);
    y = root(y);
    if(x == y)
        return 0;
    if(rnk[x] < rnk[y])
    {
        pdes.push_back({ x, par[x] });
        par[x] = y;
    }
    else
    {
        pdes.push_back({ y, par[y] });
        par[y] = x;
        if(rnk[x] == rnk[y])
        {
            rdes.push_back({ x, rnk[x] });
            rnk[x]++;
        }
    }
    return 1;
}

edg arr[500010];
vector<edg> que[500010];
vector<pair<int, pair<int, int>>> tot;

bool res[500010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, q, a, x, y, w, i, j;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &x, &y, &w);
        arr[i] = { x, y, w };
    }
    scanf("%d", &q);
    for(i = 0; i < q; i++)
    {
        scanf("%d", &a);
        for(j = 0; j < a; j++)
        {
            scanf("%d", &x);
            que[i].push_back(arr[x]);
        }
    }

    for(i = 0; i < q; i++)
    {
        sort(que[i].begin(), que[i].end());

        for(j = 0; j < que[i].size(); j++)
        {
            if(j == 0 || que[i][j].w != que[i][j - 1].w)
                tot.push_back({ que[i][j].w, {i, j} });
        }
    }

    sort(tot.begin(), tot.end());

    sort(arr + 1, arr + m + 1);

    for(i = 1; i <= n; i++)
        par[i] = i;

    int p = 0;
    for(i = 1; i <= m && p < tot.size(); i++)
    {
        if(arr[i].w < tot[p].first)
        {
            merge(arr[i].x, arr[i].y);
            pdes.clear();
            rdes.clear();
            continue;
        }

        int c = tot[p].second.first;
        if(!res[c])
        {
            int s = tot[p].second.second;
            for(j = s; j < que[c].size() && que[c][j].w == que[c][s].w; j++)
            {
                if(!merge(que[c][j].x, que[c][j].y))
                {
                    res[c] = 1;
                    break;
                }
            }

            while(!pdes.empty())
            {
                par[pdes.back().first] = pdes.back().second;
                pdes.pop_back();
            }

            while(!rdes.empty())
            {
                rnk[rdes.back().first] = rdes.back().second;
                rdes.pop_back();
            }
        }

        i--;
        p++;
    }

    for(i = 0; i < q; i++)
    {
        if(res[i])
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}