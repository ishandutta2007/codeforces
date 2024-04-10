#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>

using namespace std;

mt19937 Rand(16092002);
mt19937_64 BigRand(16092002);

typedef long long ll;

const int N = 4e5 + 7;

vector <int> g[N];
int mx[N];
int p[N];
int sz[N];
int res[N];

void dfs(int v, int pr)
{
    p[v] = pr;
    sz[v] = 1;
    for (auto to : g[v])
    {
        if (to != pr)
        {
            dfs(to, v);
            sz[v] += sz[to];
            mx[v] = max(mx[v], sz[to]);
        }
    }
}

void zhfs(int v, int pr)
{
    int x = -1;
    for (auto to : g[v])
    {
        if (to != pr)
        {
            zhfs(to, v);
            if (x == -1 || sz[to] > sz[x])
            {
                x = to;
            }
        }
    }
    if (x == -1)
    {
        res[v] = v;
    }
    else
    {
        int cur = res[x];
        while (1)
        {
            bool good = (sz[v] - sz[cur] <= sz[v] / 2);
            good &= (mx[cur] <= sz[v] / 2);
            if (good)
            {
                break;
            }
            else
            {
                cur = p[cur];
            }
        }
        res[v] = cur;
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i++)
    {
        int p;
        scanf("%d", &p);
        g[p].push_back(i + 1);
    }
    dfs(1, -1);
    zhfs(1, -1);
    while (q--)
    {
        int i;
        scanf("%d", &i);
        printf("%d\n", res[i]);
    }
}