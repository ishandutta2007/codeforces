#include <bits/stdc++.h>
using namespace std;

int arr[200010];

void solve()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i + 1 < n; i++)
    {
        if(arr[i] != arr[i + 1])
        {
            puts("1");
            return;
        }
    }

    printf("%d\n", n);
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
        solve();

    return 0;
}