#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{
    while(a&&b)
    {
        a>b?a%=b:b%=a;
    }
    return a+b;
}
int main()
{
    ll n,m,q;
    scanf("%lld",&n);
    scanf("%lld",&m);
    scanf("%lld",&q);
    ll g=gcd(n,m);
    ll n1=n/g,m1=m/g;
    while(q--)
    {
        ll a,b,c,d;
        scanf("%lld",&a);
        scanf("%lld",&b);
        scanf("%lld",&c);
        scanf("%lld",&d);
        ll c1,c2;
        b--;d--;
        if(a==1)
        {
            c1=b/n1;
        }
        else
        {
            c1=b/m1;
        }
        if(c==1)
        {
            c2=d/n1;
        }
        else
        {
            c2=d/m1;
        }
        if(c1==c2)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
/*

*/