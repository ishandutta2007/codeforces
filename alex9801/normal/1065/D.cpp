#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
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
#include <cmath>

using namespace std;

struct pos
{
    int x, y;
};

int n;
int arr[10][10];
pos loc[101];
int mem[10][10][100][301][3];
const int INF = 100000;

int dx0[8] = { 2, 2, 1, 1, -1, -1, -2, -2 };
int dy0[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };
int dx1[8] = { 1, 1, -1, -1 };
int dy1[8] = { 1, -1, 1, -1 };
int dx2[8] = { 1, 0, -1, 0 };
int dy2[8] = { 0, 1, 0, -1 };

int f(int x, int y, int h, int t, int p)
{
    int &mm = mem[x][y][h][t][p];
    if(mm == -1)
    {
        mm = INF;
        if(t == 0)
        {
            if(loc[1].x == x && loc[1].y == y && h == 1)
                mm = 0;
        }
        else
        {
            mm = min(mm, f(x, y, h, t - 1, (p + 1) % 3) + 1);
            mm = min(mm, f(x, y, h, t - 1, (p + 2) % 3) + 1);

            int ari = loc[h].x == x && loc[h].y == y;
            if(p == 0)
            {
                for(int d = 0; d < 8; d++)
                {
                    int nx = x + dx0[d];
                    int ny = y + dy0[d];
                    if(0 <= nx && nx < n && 0 <= ny && ny < n)
                        mm = min(mm, f(nx, ny, h - ari, t - 1, p));
                }
            }
            else if(p == 1)
            {
                for(int d = 0; d < 4; d++)
                {
                    int nx = x + dx1[d];
                    int ny = y + dy1[d];
                    while(0 <= nx && nx < n && 0 <= ny && ny < n)
                    {
                        mm = min(mm, f(nx, ny, h - ari, t - 1, p));
                        nx += dx1[d];
                        ny += dy1[d];
                    }
                }
            }
            else
            {
                for(int d = 0; d < 4; d++)
                {
                    int nx = x + dx2[d];
                    int ny = y + dy2[d];
                    while(0 <= nx && nx < n && 0 <= ny && ny < n)
                    {
                        mm = min(mm, f(nx, ny, h - ari, t - 1, p));
                        nx += dx2[d];
                        ny += dy2[d];
                    }
                }
            }
        }

        // printf("%d %d %d %d %d : %d\n", x, y, h, t, p, mm);
    }

    return mm;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            loc[arr[i][j]] = { i, j };

    memset(mem, -1, sizeof mem);

    for(i = 2;; i++)
    {
        int mn = INF;
        for(j = 0; j < 3; j++)
            mn = min(mn, f(loc[n * n].x, loc[n * n].y, n * n, i, j));
        
        if(mn != INF)
        {
            printf("%d %d\n", i, mn);
            return 0;
        }
    }

    return 0;
}