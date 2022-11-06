#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

struct edg
{
    int x, i;
};

vector<edg> arr[300010];
int num[300010];

bool dead[300010];
bool vit[300010];
bool res[300010];

int dfs1(int x)
{
    int r = 0;
    if(num[x] == 1)
        r++;

    dead[x] = 1;
    for(edg &e: arr[x])
        if(!dead[e.x])
            r += dfs1(e.x);

    return r;
}

bool cur;
int ori;

void go(int x, edg e)
{
    if(cur)
        res[e.i] = !res[e.i];

    if(e.x != ori && num[e.x] == 1)
    {
        if(cur)
        {
            num[ori] = num[e.x] = 0;
            cur = 0;
        }
        else
        {
            ori = e.x;
            cur = 1;
        }
    }
}

void dfs2(int x, edg r)
{
    vit[x] = 1;
    for(edg &e: arr[x])
    {
        if(vit[e.x])
            continue;

        go(x, e);

        dfs2(e.x, { x, e.i });
    }

    if(r.x != -1)
        go(x, r);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, x, y, i;
    scanf("%d%d", &n, &m);
    for(i = 1; i<=n; i++)
        scanf("%d", &num[i]);
    for(i = 1; i<=m; i++)
    {
        scanf("%d%d", &x, &y);
        arr[x].push_back({ y, i });
        arr[y].push_back({ x, i });
    }

    for(i = 1; i<=n; i++)
    {
        if(num[i] == -1 && !dead[i])
        {
            int t = dfs1(i);
            if(t % 2 == 1)
                num[i] = 1;
        }
    }

    for(i = 1; i<=n; i++)
    {
        if(num[i] == 1 && !vit[i])
        {
            cur = 1;
            ori = i;
            dfs2(i, { -1, -1 });

            if(cur)
            {
                printf("-1");
                return 0;
            }
        }
    }

    int r = 0;
    for(i = 1; i<=m; i++)
        if(res[i])
            r++;

    printf("%d\n", r);
    for(i = 1; i<=m; i++)
        if(res[i])
            printf("%d\n", i);
    return 0;
}