/*
      
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
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
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 2e5 + 1;

int pr[N];
int ans[N];
int x[N], y[N];
int w[N];

int get(int v)
{
    if (v == pr[v])
    {
        return v;
    }
    else
    {
        return pr[v] = get(pr[v]);
    }
}

void uni(int u, int v)
{
    u = get(u), v = get(v);
    ans[v] += ans[u];
    pr[u] = v;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        pr[i] = i;
        ans[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &x[i], &y[i], &w[i]);
        x[i]--, y[i]--;
    }
    vector <int> e(n);
    for (int i = 0; i < n; i++)
    {
        e[i] = i;
    }
    sort(e.begin(), e.end(), [] (int a, int b)
    {
        return w[a] > w[b];
    });
    ll res = 0;
    for (int v : e)
    {
        if (y[v] == -1 || get(x[v]) == get(y[v]))
        {
            if (ans[get(x[v])] > 0)
            {
                res += w[v];
                ans[get(x[v])]--;
            }
        }
        else
        {
            if (ans[get(x[v])] > 0 || ans[get(y[v])] > 0)
            {
                res += w[v];
                uni(x[v], y[v]);
                ans[get(x[v])]--;
            }
        }
    }
    printf("%lld\n", res);
}