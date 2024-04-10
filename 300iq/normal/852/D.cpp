
/*
    !  !!!
   
   
   
   
   
   
   
   
   
   
   
*/

#include <cmath>
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
#include <unordered_map>
#include <iomanip>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 600 + 1;

int w[N][N];
int mt[N];
bool used[N];
vector <int> g[N];

bool dfs(int v)
{
    if (used[v])
    {
        return false;
    }
    used[v] = true;
    for (int to : g[v])
    {
        if (mt[to] == -1 || dfs(mt[to]))
        {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int v, e, n, k;
    scanf("%d%d%d%d", &v, &e, &n, &k);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i != j)
            {
                w[i][j] = 1e9;
            }
            else
            {
                w[i][j] = 0;
            }
        }
    }
    vector <int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        x--;
        a.push_back(x);
    }
    for (int i = 0; i < e; i++)
    {
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        a--, b--;
        w[a][b] = min(w[a][b], t);
        w[b][a] = min(w[b][a], t);
    }
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
            }
        }
    }
    int l = -1, r = 1731311 + 7;
    while (l < r - 1)
    {
        int m = (l + r) / 2;
        for (int i = 0; i < v; i++)
        {
            mt[i] = -1;
            used[i] = false;
        }
        for (int i = 0; i < n; i++)
        {
            g[i].clear();
            int u = a[i];
            for (int j = 0; j < v; j++)
            {
                if (w[u][j] <= m)
                {
                    g[i].push_back(j);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (dfs(i))
            {
                cnt++;
                for (int j = 0; j < n; j++)
                {
                    used[j] = 0;
                }
            }
        }
        if (cnt >= k)
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    if (r == 1731311 + 7)
    {
        puts("-1");
    }
    else
    {
        printf("%d\n", r);
    }
}