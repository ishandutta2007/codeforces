#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 400010

using namespace std;

long long K[M];

int main()
{
    long long n;
    scanf("%lld", &n);
    for(long long i = 1; i <= n; i++)
        scanf("%lld", &K[i]);
    for(long long i = 1; i <= n; i++)
        K[i + n] = K[i];
    long long Min = K[1];
    n *= 2;
    for(long long i = 2; i <= n; i++)
        Min = min(Min, K[i]);
    for(long long i = 1; i <= n; i++)
        K[i] -= Min;
    long long Max = 0, Now = 0;
    for(long long i = 1; i <= n; i++)
        if(K[i])
        {
            Now++;
            if(Now > Max) Max = Now;
        }
        else Now = 0;
    printf("%lld\n", Max + Min * n / 2);
    return 0;
}