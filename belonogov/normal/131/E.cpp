#include <iostream>
#include <cstdio>
#include <set>
#include <map>

using namespace std;
const int maxn = 1e5;
struct point
{
    int x, y;
};
point a[maxn];
map <int,int> b[2 * maxn];
int dist[maxn];
int res[10];

void line(int n)
{
    int d, i;
    map <int, int>::iterator j, jj;

    for (i = 0; i < n; i++)
    {
        if (b[i].size() == 0)
            continue;
        if (b[i].size() == 1)
        {
            b[i].clear();
            continue;
        }

        if (b[i].size() > 1)
        {
            dist[(*b[i].begin()).second]++;
            b[i].erase(b[i].begin());
        }
        d = -1;
        for (j = b[i].begin(); j != b[i].end(); j++)
        {
            d = (*j).second;
            dist[d] += 2;
        }
        if (d != -1)
            dist[d]--;
        b[i].clear();
    }

}

int main()
{
     int i, n, m, l, x, y;
    pair <int, int> k;
    map <int, int>::iterator j;
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].x--;
        a[i].y--;
    }
    for (i = 0; i < m; i++)
    {
       b[a[i].x].insert(make_pair(a[i].y, i));
    }
    line(n);
    for (i = 0; i < m; i++)
    {
       b[a[i].y].insert(make_pair(a[i].x, i));
    }
    line(n);
    for (i = 0; i < m; i++)
    {
        l = a[i].x - a[i].y + n - 1;
        if (a[i].y >= a[i].x)
            x = a[i].x;
        else
            x = a[i].y;
        b[l].insert(make_pair(x, i));
    }
    line(2 * n - 1);

    for (i = 0; i < m; i++)
    {
        y = a[i].x;
        x = n - 1 - a[i].y;
        a[i].x = x;
        a[i].y = y;

    }
    for (i = 0; i < m; i++)
    {
        l = a[i].x - a[i].y + n - 1;
        if (a[i].y >= a[i].x)
            x = a[i].x;
        else
            x = a[i].y;
        b[l].insert(make_pair(x, i));
    }
    line(2 * n - 1);


    for (i = 0; i < m; i++)
        res[dist[i]]++;
    for (i = 0; i <= 8; i++)
        printf("%d ", res[i]);


    return 0;
}