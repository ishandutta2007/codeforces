#include <bits/stdc++.h>

using namespace std;

int arr[1000010];
int mem[1000010][15];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, i, j;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        arr[x]++;
    }

    memset(mem, -1, sizeof mem);
    for(i = 1; i <= m; i++)
    {
        for(j = 0; j < 15; j++)
        {
            int x = j / 3;
            int y = j % 3;
            if(i == 1)
            {
                if(y == 0 && x <= arr[1])
                    mem[i][j] = (arr[1] - x) / 3;
            }
            else if(i == 2)
            {
                if(y <= arr[1] && x <= arr[2])
                    mem[i][j] = (arr[1] - y) / 3 + (arr[2] - x) / 3;
            }
            else
            {
                for(int z = 0; z <= 2; z++)
                    if(z + x <= arr[i] && mem[i - 1][3 * (y + z) + z] != -1)
                        mem[i][j] = max(mem[i][j], (arr[i] - z - x) / 3 + z + mem[i - 1][3 * (y + z) + z]);

            }
            //printf("mem %d (%d, %d) = %d\n", i, x, y, mem[i][j]);
        }
    }

    int r = 0;
    for(int i = 0; i < 8; i++)
        r = max(r, mem[m][i]);

    printf("%d\n", r);
    return 0;
}