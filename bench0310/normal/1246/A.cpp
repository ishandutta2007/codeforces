#include <bits/stdc++.h>

using namespace std;

long long popcnt(long long a)
{
    long long t=0;
    while(a)
    {
        if(a&1) t++;
        a/=2;
    }
    return t;
}

int main()
{
    long long n,p;
    scanf("%I64d%I64d",&n,&p);
    for(long long k=1;k<=1000000;k++)
    {
        long long sum=n-k*p;
        if(k>sum) continue;
        if(k<popcnt(sum)) continue;
        printf("%I64d\n",k);
        return 0;
    }
    printf("-1\n");
    return 0;
}