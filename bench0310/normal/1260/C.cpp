#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a,long long b)
{
    if(!b) return a;
    else return gcd(b,a%b);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b,k;
        scanf("%I64d%I64d%I64d",&a,&b,&k);
        if(a==b)
        {
            printf("OBEY\n");
            continue;
        }
        if(a<b) swap(a,b);
        long long g=gcd(a,b);
        long long cnt=((a-g)/b)-(((a-g)%b)==0)+1;
        if(cnt<k) printf("OBEY\n");
        else printf("REBEL\n");
    }
    return 0;
}