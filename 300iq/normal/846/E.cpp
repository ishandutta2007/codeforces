
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

const int N = 1e5 + 1;

vector <int> g[N];

ll b[N], a[N];
int k[N];

void dfs(int v, int pr)
{
    for (int to : g[v])
    {
        if (to != pr)
        {
            dfs(to, v);
        }
    }
    if (b[v] < a[v])
    {
        if (pr == -1)
        {
            puts("NO");
            exit(0);
        }
        ll now = (a[v] - b[v]) * k[v];
        if (now / k[v] != (a[v] - b[v]) || now / (a[v] - b[v]) != k[v] || now < max(a[v] - b[v], (ll) k[v]))
        {
            puts("NO");
            exit(0);
        }
        ll was = a[pr];
        a[pr] += now;
        if (a[pr] - now != was || a[pr] - was != now || a[pr] <= 0)
        {
            puts("NO");
            exit(0);
        }
    }
    else
    {
        if (pr != -1)
        {
            b[pr] += b[v];
            ll was = a[pr];
            a[pr] += a[v];
            if (a[pr] - a[v] != was || a[pr] - was != a[v] || a[pr] <= 0)
            {
                puts("NO");
                exit(0);
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
    for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i < n; i++)
    {
        int x;
        scanf("%d%d", &x, &k[i]);
        x--;
        g[x].push_back(i);
    }
    dfs(0, -1);
    puts("YES");
}