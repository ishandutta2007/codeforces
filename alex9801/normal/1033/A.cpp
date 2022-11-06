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

int chk[1010][1010];
int n;
int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[8] = { 1, 0, -1, 1, -1, 1, 0, -1 };

void f(int x, int y)
{
    chk[x][y] = 2;
    for(int d = 0; d < 8; d++)
    {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(1 <= nx && nx <= n && 1 <= ny && ny <= n && !chk[nx][ny])
            f(nx, ny);
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int i, j;
    scanf("%d", &n);

    int ax, ay, bx, by, cx, cy;
    scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            int dx = i - ax;
            int dy = j - ay;

            if(dx == 0 || dy == 0 || dx == dy || dx == -dy)
                chk[i][j] = 1;
        }
    }

    f(bx, by);

    if(chk[cx][cy] == 2)
        puts("YES");
    else
        puts("NO");

    return 0;
}