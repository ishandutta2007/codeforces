#include <bits/stdc++.h>
using namespace std;

int deg[100010];

int main()
{
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        deg[x]++;
        deg[y]++;
    }

    for(i = 1; i <= n; i++)
    {
        if(deg[i] == 2)
        {
            puts("NO");
            return 0;
        }
    }

    puts("YES");
    return 0;
}