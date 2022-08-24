
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

const int N = 3e5 + 7;

vector <int> g[N];
bool u[N];
int h[N];
int ans = 0;
int cnt = 0;

void dfs(int v, int pr, int e)
{
    cnt++;
    u[v] = true;
    h[v] = e;
    for (int to : g[v])
    {
        if (to != pr)
        {
            if (!u[to])
            {
                dfs(to, v, e + 1);
            }
            else
            {
                ans = abs(h[v] - h[to]) + 1;
            }
        }
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int mod = 1e9 + 7;
    int x = 1;
    for (int i = 0; i < 2 * n; i++)
    {
        if (!u[i])
        {
            ans = 0, cnt = 0;
            dfs(i, -1, 0);
            int res = 1;
            if (ans)
            {
                if (ans != 1)
                {
                    res = 2;
                }
                else
                {
                    res = 1;
                }
            }
            else
            {
                res = cnt;
            }
            x = (x * (ll) res) % mod;
        }
    }
    printf("%d\n", x);
}