#include <bits/stdc++.h>
using namespace std;

long long arr[1000010];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    if(n == 1)
    {
        printf("%lld\n", arr[0]);
        return 0;
    }

    long long sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];

    long long t = 1LL * (n - 2) * (n - 1) / 2;
    long long d = (sum - t) / n;
    long long k = sum - t - d * (n - 1);
    assert(d - 1 <= k && k <= d + n - 1);

    if(k == d - 1)
        printf("%lld ", k);

    for(long long i = d; i <= d + n - 2; i++)
    {
        if(i == k)
            printf("%lld ", k);
        printf("%lld ", i);
    }

    if(k == d + n - 1)
        printf("%lld ", k);

    puts("");
    return 0;
}