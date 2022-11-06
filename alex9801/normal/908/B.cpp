#include <cstdio>
#include <cstdlib>
#include <cstring>
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

using namespace std;

int n, m;
char arr[60][60];
char seq[110];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int per[4] = { 0, 1, 2, 3 };

bool f()
{
    int x, y, i, j, k;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(arr[i][j] == 'S')
            {
                x = i;
                y = j;
                for(k = 0; seq[k]; k++)
                {
                    x += dx[per[seq[k] - '0']];
                    y += dy[per[seq[k] - '0']];
                    if(x < 0 || y < 0 || x >= n || y >= m || arr[x][y] == '#')
                        return 0;
                    if(arr[x][y] == 'E')
                        return 1;
                }
                return 0;
            }
        }
    }
    return 0;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int r, i;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++)
        scanf("%s", arr[i]);
    scanf("%s", seq);

    r = 0;
    do
    {
        if(f())
            r++;
    }
    while(next_permutation(per, per + 4));
    printf("%d", r);
    return 0;
}