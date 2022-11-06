#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
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
#include <cmath>

using namespace std;

struct str
{
    int x, y, cx, cy;
    bool operator <(const str &a) const
    {
        return cx + cy > a.cx + a.cy;
    }
};

char arr[2010][2010];
int dis[2010][2010];
const int INF = 100000000;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int cst[4] = { 0, 1, 0, 1 };

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, sx, sy, cx0, cy0, i, j;
    scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &cx0, &cy0);
    for(i = 0; i < n; i++)
        scanf("%s", arr[i]);

    sx--;
    sy--;

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            dis[i][j] = INF;

    priority_queue<str> pq;
    dis[sx][sy] = 0;
    pq.push({ sx, sy, 0, 0 });
    while(!pq.empty())
    {
        int x, y, cx, cy, w;
        x = pq.top().x;
        y = pq.top().y;
        cx = pq.top().cx;
        cy = pq.top().cy;
        pq.pop();

        w = cx + cy;

        if(dis[x][y] < w)
            continue;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ncx = cx;
            int ncy = cy;

            if(i == 1)
                ncy++;
            else if(i == 3)
                ncx++;

            if(ncy > cy0 || ncx > cx0)
                continue;

            int nw = ncx + ncy;

            if(0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] != '*' && nw < dis[nx][ny])
            {
                dis[nx][ny] = nw;
                pq.push({ nx, ny, ncx, ncy });
            }
        }
    }

    int r = 0;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            if(dis[i][j] != INF)
                r++;

    printf("%d\n", r);
    return 0;
}