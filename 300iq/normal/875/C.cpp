
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

bool bigger(int x, int y)
{
    return x > y;
}

const int N = 1e5 + 7;

vector <int> g[N], gr[N];
bool used[N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    vector <vector <int> > a(n);
    vector <vector <pair <int, int> > > pos(m);
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        for (int j = 0; j < t; j++)
        {
            int x;
            scanf("%d", &x);
            x--;
            pos[x].push_back({i, j});
            a[i].push_back(x);
        }
    }
    vector <bool> del(m);
    vector <int> ans;
    for (int i = 0; i < n - 1; i++)
    {
        int cur = 0;
        while (cur < (int) a[i].size() && cur < (int) a[i + 1].size() && a[i][cur] == a[i + 1][cur])
        {
            cur++;
        }
        if (cur != (int) a[i].size() && cur != (int) a[i + 1].size())
        {
            g[a[i][cur]].push_back(a[i + 1][cur]);
        }
        else
        {
            if (a[i].size() == a[i + 1].size())
            {
                continue;
            }
            else
            {
                if (a[i].size() > a[i + 1].size())
                {
                    puts("No");
                    return 0;
                }
            }
        }
    }
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j : g[i])
        {
            if (j < i)
            {
                del[i] = true;
            }
            else if (del[j])
            {
                del[i] = true;
            }
        }
        if (del[i])
        {
            ans.push_back(i);
            for (auto c : pos[i])
            {
                a[c.first][c.second] -= m;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        int cur = 0;
        while (cur < (int) a[i].size() && cur < (int) a[i + 1].size() && a[i][cur] == a[i + 1][cur])
        {
            cur++;
        }
        if (cur != (int) a[i].size() && cur != (int) a[i + 1].size())
        {
            if (a[i][cur] > a[i + 1][cur])
            {
                puts("No");
                return 0;
            }
        }
    }
    sort(ans.begin(), ans.end());
    puts("Yes");
    printf("%d\n", (int) ans.size());
    for (int c : ans)
    {
        printf("%d ", c + 1);
    }
    puts("");
}