#include <bits/stdc++.h>
using namespace std;

char arr[100010];
char tmp[100010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%s", arr);

    n = strlen(arr);

    int c = 0;
    for(i = 0; i < n; i++)
        if(arr[i] != 'a')
            c++;

    if(c % 2)
    {
        puts(":(");
        return 0;
    }

    if(c == 0)
    {
        printf("%s\n", arr);
        return 0;
    }

    int t = 0;
    int p, s = 0;
    for(i = 0; i < n; i++)
    {
        if(arr[i] != 'a')
        {
            t++;
            if(t == c / 2 + 1)
            {
                p = i;
                break;
            }
            tmp[s++] = arr[i];
        }
    }

    if(strcmp(tmp, arr + p) == 0)
    {
        arr[p] = '\0';
        printf("%s\n", arr);
    }
    else
        puts(":(");

    return 0;
}