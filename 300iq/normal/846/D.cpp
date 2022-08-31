
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

int a[1488][1488];

int get(int x, int y)
{
    if (x < 0 || y < 0) return 0;
    else return a[x][y];
}

int get(int x1, int y1, int x2, int y2)
{
    return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector <pair <pair <int, int>, int> > e;
    for (int i = 0; i < q; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        x--, y--;
        e.push_back({{x, y}, t});
    }
    int l = -1, r = 1e9 + 8;
    while (l < r - 1)
    {
        int vm = (l + r) / 2;
        for (auto c : e)
        {
            if (c.second <= vm)
            {
                a[c.first.first][c.first.second]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i) a[i][j] += a[i - 1][j];
                if (j) a[i][j] += a[i][j - 1];
                if (i && j) a[i][j] -= a[i - 1][j - 1];
            }
        }
        bool bad = false;
        for (int i = k - 1; i < n; i++)
        {
            for (int j = k - 1; j < m; j++)
            {
                if (get(i - k + 1, j - k + 1, i, j) == k * k)
                {
                    bad = true;
                }
            }
        }
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = 0;
        if (bad)
        {
            r = vm;
        }
        else
        {
            l = vm;
        }
    }
    if (r <= 1e9)
    {
        printf("%d\n", r);
    }
    else
    {
        puts("-1");
    }
}