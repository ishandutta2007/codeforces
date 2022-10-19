#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int main()
{
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        long long a, b;
        long long n;
        scanf("%lld", &n);
        scanf("%lld%lld", &a, &b);
        if (a * 2 <= b)
        {
            printf("%lld\n", a * n);
        }
        else
        {
            printf("%lld\n", (n / 2) * b + (n % 2) * a);
        }
    }
    return 0;
}