#include <bits/stdc++.h>
using namespace std;

long long arr[200010];

void solve()
{
    int n;
    long long k;
    scanf("%d%lld", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    {
        long long mx = *max_element(arr, arr + n);
        for(int i = 0; i < n; i++)
            arr[i] = mx - arr[i];
    }

    if(k % 2 == 0)
    {
        {
            long long mx = *max_element(arr, arr + n);
            for(int i = 0; i < n; i++)
                arr[i] = mx - arr[i];
        }
    }

    for(int i = 0; i < n; i++)
        printf("%lld ", arr[i]);
    puts("");
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
        solve();

    return 0;
}