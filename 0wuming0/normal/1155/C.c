#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define ll long long
ll gcd(ll a,ll b)
{
    while(1)
    {
        if(a>b)
        {
            a%=b;
        }
        else
        {
            b%=a;
        }
        if(a==0)
            return b;
        if(b==0)
            return a;
    }

}
int main()
{
    ll i,j;
    ll x,p,n,m;
    scanf("%lld",&n);
    scanf("%lld",&m);
    ll *nn=malloc(300005*8),mm;
    for(i=0;i<n;i++)
    {
        scanf("%lld",nn+i);
    }
    for(i=n-1;i>0;i--)
    {
        nn[i]-=nn[i-1];
    }
    ll g=nn[1];
    for(i=2;i<n;i++)
        g=gcd(g,nn[i]);
    for(i=1;i<=m;i++)
    {
        scanf("%lld",&mm);
        if(g%mm==0)
        {
            printf("YES\n");
            printf("%lld",nn[0]);
            printf(" %lld\n",i);
            free((void*)nn);
            return 0;
        }
    }
    printf("NO\n");
    free((void*)nn);
    return 0;
}