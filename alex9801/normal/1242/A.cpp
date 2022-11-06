#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    long long n;
    scanf("%lld", &n);

    long long t = n;
    for(int i = 2; 1LL * i * i <= n; i++)
    {
        if(n % i == 0)
        {
            t = i;
            break;
        }
    }

    if(t == n)
    {
        printf("%lld\n", n);
        return 0;
    }

    while(n > 1)
    {
        if(n % t != 0)
        {
            puts("1");
            return 0;
        }

        n /= t;
    }

    printf("%lld\n", t);
    return 0;
}