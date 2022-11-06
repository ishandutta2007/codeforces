#include <bits/stdc++.h>
using namespace std;

char arr[2010][2010];
int sum[2010][2010];

void add(int a, int b, int x, int y)
{
    assert(a <= x && b <= y);

    sum[a][b]++;
    sum[a][y + 1]--;
    sum[x + 1][b]--;
    sum[x + 1][y + 1]++;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, k, i, j;
    scanf("%d%d", &n, &k);
    for(i = 1; i <= n; i++)
        scanf("%s", arr[i] + 1);

    for(i = 1; i <= n; i++)
    {
        int a = -1, b = -1;
        for(j = 1; j <= n; j++)
        {
            if(arr[i][j] == 'B')
            {
                if(a == -1)
                    a = j;
                b = j;
            }
        }

        if(a == -1)
            add(1, 1, n, n);
        else if(b - a + 1 <= k)
            add(max(1, i - k + 1), max(1, b - k + 1), i, a);
    }

    for(j = 1; j <= n; j++)
    {
        int a = -1, b = -1;
        for(i = 1; i <= n; i++)
        {
            if(arr[i][j] == 'B')
            {
                if(a == -1)
                    a = i;
                b = i;
            }
        }

        if(a == -1)
            add(1, 1, n, n);
        else if(b - a + 1 <= k)
            add(max(1, b - k + 1), max(1, j - k + 1), a, j);
    }

    int r = 0;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
            r = max(r, sum[i][j]);
        }
    }

    printf("%d\n", r);
    return 0;
}