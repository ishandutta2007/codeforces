#include <bits/stdc++.h>
using namespace std;

long long arr[30][30];

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 3; i <= 2 * n - 1; i++)
    {
        int x = min(i - 1, n);
        int y = i - x;

        long long t = 0;
        while(x >= 1 && y <= n)
        {
            arr[x][y] = t << (i - 3);
            x--;
            y++;
            t = 1 - t;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            printf("%lld ", arr[i][j]);
        puts("");
    }
    fflush(stdout);

    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        long long k;
        scanf("%lld", &k);

        int x = 1;
        int y = 1;
        vector<pair<int, int>> res;
        while(1)
        {
            res.push_back({ x, y });
            if(x == n && y == n)
                break;

            if(x == n)
                y++;
            else if(y == n)
                x++;
            else
            {
                if(!(k & (1LL << (x + y + 1 - 3))) ^ !arr[x + 1][y])
                    y++;
                else
                    x++;
            }
        }

        for(auto[x, y] : res)
            printf("%d %d\n", x, y);
        fflush(stdout);
    }
    return 0;
}