#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long d,m;
        scanf("%I64d%I64d",&d,&m);
        long long x=0;
        for(long long i=0;i<=30;i++) if(d&(1ll<<i)) x=i;
        vector<long long> k(x+1,0);
        for(long long i=0;i<x;i++) k[i]=(1ll<<i)%m;
        k[x]=(d-(1ll<<x)+1)%m;
        long long res=k[0];
        for(long long i=1;i<=x;i++)
        {
            res=(res+res*k[i]+k[i])%m;
        }
        printf("%I64d\n",res);
    }
    return 0;
}