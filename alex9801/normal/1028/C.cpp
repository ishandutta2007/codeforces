#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <iterator>

using namespace std;

#define y1 yyyy

int x1[200000];
int y1[200000];
int x2[200000];
int y2[200000];

pair<int, int> xl[200000];
pair<int, int> yl[200000];
pair<int, int> xr[200000];
pair<int, int> yr[200000];
const int INF = 1e9;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);

    xl[0] = yl[0] = { -INF, INF };
    for(i = 1; i <= n; i++)
    {
        xl[i] = { max(xl[i - 1].first, x1[i]), min(xl[i - 1].second, x2[i]) };
        yl[i] = { max(yl[i - 1].first, y1[i]), min(yl[i - 1].second, y2[i]) };
    }

    xr[n + 1] = yr[n + 1] = { -INF, INF };
    for(i = n; i >= 1; i--)
    {
        xr[i] = { max(xr[i + 1].first, x1[i]), min(xr[i + 1].second, x2[i]) };
        yr[i] = { max(yr[i + 1].first, y1[i]), min(yr[i + 1].second, y2[i]) };
    }

    for(i = 1; i <= n; i++)
    {
        int tx = max(xl[i - 1].first, xr[i + 1].first);
        int ty = max(yl[i - 1].first, yr[i + 1].first);

        if(tx <= min(xl[i - 1].second, xr[i + 1].second) && ty <= min(yl[i - 1].second, yr[i + 1].second))
        {
            printf("%d %d\n", tx, ty);
            return 0;
        }
    }

    return 0;
}