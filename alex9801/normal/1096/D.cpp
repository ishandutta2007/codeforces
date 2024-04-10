#include <bits/stdc++.h>

using namespace std;

char arr[100010];
int poi[100010];
long long mem[100010][4];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i, j;
    scanf("%d%s", &n, arr + 1);
    for(i = 1; i <= n; i++)
        scanf("%d", &poi[i]);

    for(i = 1; i <= n; i++)
    {
        for(j = 0; j < 4; j++)
            mem[i][j] = mem[i - 1][j];

        if(arr[i] == 'h')
            mem[i][0] = mem[i - 1][0] + poi[i];
        else if(arr[i] == 'a')
            mem[i][1] = min(mem[i - 1][0], mem[i - 1][1] + poi[i]);
        else if(arr[i] == 'r')
            mem[i][2] = min(mem[i - 1][1], mem[i - 1][2] + poi[i]);
        else if(arr[i] == 'd')
            mem[i][3] = min(mem[i - 1][2], mem[i - 1][3] + poi[i]);
    }

    printf("%lld\n", mem[n][3]);
    return 0;
}