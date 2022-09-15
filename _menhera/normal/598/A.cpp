#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int N; scanf("%d", &N);
        long long ans = 1LL*N*(N+1)/2;
        int t = 1;
        while(t <= N)
        {
            ans -= 2*t;
            t *= 2;
        }
        printf("%lld\n", ans);
    }
}