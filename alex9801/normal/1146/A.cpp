#include <bits/stdc++.h>
using namespace std;

char arr[100];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%s", arr);

    n = strlen(arr);

    int c = 0;
    for(i = 0; i < n; i++)
        if(arr[i] == 'a')
            c++;

    int r = c + min(n - c, c - 1);
    printf("%d\n", r);
    return 0;
}