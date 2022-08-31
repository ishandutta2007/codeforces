
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

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 1e5 + 1;

bool u[N];
vector <int> g[N];
vector <int> cur;

void dfs(int v)
{
    u[v] = true;
    cur.push_back(v);
    for (int to : g[v])
    {
        if (!u[to])
        {
            dfs(to);
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
    map <int, int> ind;
    vector <int> a(n);
    vector <int> b(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        ind[a[i]] = i;
    }
    b = a;
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        g[i].push_back(ind[b[i]]);
    }
    vector <vector <int> > ans;
    for (int i = 0; i < n; i++)
    {
        if (!u[i])
        {
            cur.clear();
            dfs(i);
            ans.push_back(cur);
        }
    }
    printf("%d\n", (int) ans.size());
    for (auto c : ans)
    {
        printf("%d ", (int) c.size());
        for (auto d : c)
        {
            printf("%d ", d + 1);
        }
        puts("");
    }
}