#include <bits/stdc++.h>
using namespace std;

int arr[200010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int c1 = 0, c2 = 0;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == 1)
            c1++;
        else
            c2++;
    }

    if(c1 == 0 || c2 == 0)
    {
        for(i = 0; i < n; i++)
            printf("%d ", arr[i]);
        return 0;
    }

    printf("2 1 ");
    for(i = 0; i < c2 - 1; i++)
        printf("2 ");
    for(i = 0; i < c1 - 1; i++)
        printf("1 ");

    return 0;
}