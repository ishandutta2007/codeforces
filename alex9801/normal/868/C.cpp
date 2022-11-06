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

bool arr[100010][4];
bool chk[4];
bool mem[4][4];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int u;
    int n, k, i, j, l;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++)
        for(j = 0; j < k; j++)
            scanf("%d", &arr[i][j]);

    for(i = 0; i < n; i++)
    {
        u = 1;
        for(j = 0; j < k; j++)
        {
            if(arr[i][j])
            {
                u = 0;
                break;
            }
        }
        if(u)
        {
            printf("YES");
            return 0;
        }
    }

    for(i = 0; i < n; i++)
        for(j = 0; j < k; j++)
            if(!arr[i][j])
                chk[j] = 1;

    for(i = 0; i < n; i++)
    {
        u = 1;
        for(j = 0; j < k; j++)
        {
            if(u == 1 && arr[i][j] && chk[j])
            {
                u = 2;
                continue;
            }

            if(arr[i][j])
            {
                u = 0;
                break;
            }
        }
        if(u)
        {
            printf("YES");
            return 0;
        }
    }

    if(k == 4)
    {
        for(i = 0; i < n; i++)
            for(j = 0; j < 3; j++)
                if(!arr[i][j])
                    for(l = j + 1; l < 4; l++)
                        if(!arr[i][l])
                            mem[j][l] = 1;

        if(mem[0][3] && mem[1][2] || mem[0][2] && mem[1][3] || mem[0][1] && mem[2][3])
        {
            printf("YES");
            return 0;
        }
    }

    printf("NO");
    return 0;
}