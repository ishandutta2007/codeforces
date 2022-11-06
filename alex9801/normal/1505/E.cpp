#include <bits/stdc++.h>
using namespace std;

char arr[10][10];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", arr[i]);

    int res = 0;
    int x = 0, y = 0;
    while(1)
    {
        int mn = 1e9;
        int p, q;
        for(int i = x; i < n; i++)
        {
            for(int j = y; j < m; j++)
            {
                if(arr[i][j] == '*')
                {
                    int t = i - x + j - y;
                    if(t < mn)
                    {
                        mn = t;
                        p = i;
                        q = j;
                    }
                }
            }
        }
        if(mn == 1e9)
            break;

        res++;
        arr[p][q] = '.';
        x = p;
        y = q;
    }

    printf("%d\n", res);
    return 0;
}