#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>

using namespace std;

struct edg
{
    int x;
    int c;
};

vector<edg> arr[101];
int mem[101][101][27];

int f(int x, int y, int c)
{
    if(!mem[x][y][c])
    {
        mem[x][y][c] = -1;
        for(edg &e : arr[x])
        {
            if(e.c >= c)
            {
                if(f(y, e.x, e.c) == -1)
                {
                    mem[x][y][c] = 1;
                    break;
                }
            }
        }
    }
    return mem[x][y][c];
}

int main()
{
    char c;
    int n, m, x, y, i, j;
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++)
    {
        scanf("%d%d %c", &x, &y, &c);
        arr[x].push_back({ y, c - 'a' });
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(f(i, j, 0) == 1)
                printf("A");
            else
                printf("B");
        }
        printf("\n");
    }

    return 0;
}