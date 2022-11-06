#include <bits/stdc++.h>

using namespace std;

int arr[100010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int b, k, i;
    scanf("%d%d", &b, &k);
    for(i = 0; i < k; i++)
        scanf("%d", &arr[i]);

    int r = 0;
    for(i = 0; i < k; i++)
    {
        if(arr[i] % 2 == 1 && (b % 2 == 1 || i == k - 1))
            r = 1 - r;
    }

    if(r)
        puts("odd");
    else
        puts("even");
    return 0;
}