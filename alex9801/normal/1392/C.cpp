#include <bits/stdc++.h>
using namespace std;

int arr[200010];

void solve()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long r = 0;
    for(int i = n - 1; i >= 1; i--)
    {
        if(arr[i - 1] > arr[i])
            r += arr[i - 1] - arr[i];
    }

    printf("%lld\n", r);
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
        solve();

    return 0;
}