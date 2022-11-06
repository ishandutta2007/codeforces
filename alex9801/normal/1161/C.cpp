#include <bits/stdc++.h>
using namespace std;

int arr[51];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int mn = *min_element(arr, arr + n);
    int cnt = 0;
    for(i = 0; i < n; i++)
        if(arr[i] == mn)
            cnt++;

    if(cnt > n / 2)
        puts("Bob");
    else
        puts("Alice");
    return 0;
}