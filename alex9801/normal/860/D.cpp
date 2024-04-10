#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

vector<pair<int, int>> edg[400010];
bool val[400010];
pair<int, int> par[400010];
bool chk[400010];
bool vit[400010];
int pri[400010];
int n, m;

vector<tuple<int, int, int>> res;

void dfs(int x)
{
    chk[x] = 1;
    int s = edg[x].size();
    for(int k = 0; k<s; k++)
    {
        int y = edg[x][k].first;
        int i = edg[x][k].second;

        if(val[i])
            continue;

        if(y == par[x].first)
            continue;

        if(chk[y])
        {
            val[i] = 1;
            n++;
            edg[x].push_back({ n, m });
            edg[n].push_back({ x, m });
            pri[n] = y;
            chk[n] = 1;
            par[n] = { x, m };
            m++;
            continue;
        }

        par[y] = { x, i };
        dfs(y);
    }
}

void dfs2(int x)
{
    chk[x] = 1;
    vector<int> chi;
    for(auto p : edg[x])
    {
        int y = p.first;
        int i = p.second;

        if(val[i])
            continue;

        if(y == par[x].first)
            continue;

        dfs2(y);

        if(!val[i])
            chi.push_back(y);
    }

    int s = chi.size();
    for(int i = 0; i+1<s; i += 2)
        res.push_back({ chi[i], x, chi[i+1] });

    if(s % 2 == 1)
    {
        int z = chi[s-1];
        if(par[x].second != -1)
        {
            res.push_back({ z, x, par[x].first });
            val[par[x].second] = 1;
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int x, y, z, i;
    scanf("%d%d", &n, &m);
    for(i = 0; i<m; i++)
    {
        scanf("%d%d", &x, &y);
        edg[x].push_back({ y, i });
        edg[y].push_back({ x, i });
    }

    for(i = 1; i<=n; i++)
        pri[i] = i;

    for(i = 1; i<=n; i++)
    {
        if(!chk[i])
        {
            par[i] = { i, -1 };
            dfs(i);
        }
    }

    memset(chk, 0, sizeof chk);

    for(i = 1; i<=n; i++)
    {
        if(!chk[i])
        {
            dfs2(i);
        }
    }

    printf("%d\n", res.size());
    for(auto t : res)
    {
        tie(x, y, z) = t;
        printf("%d %d %d\n", pri[x], pri[y], pri[z]);
    }
    return 0;
}