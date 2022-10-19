#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include<iostream>
#include<algorithm>
#define ll long long
#define frees(a) free((void*)a)
using namespace std;
ll max(ll a,ll b)
{
    if(a>b)return a;
    else return b;
}
int main()
{
    ll n,x;
    ll i,j;
    ll *ba=(ll*)malloc(300005*8);
    ll *a=(ll*)malloc(300005*8),*be=(ll*)malloc(300005*8);
    ll *bn=(ll*)malloc(300005*8);
    ll *bx=(ll*)malloc(300005*8);
    scanf("%lld",&n);
    scanf("%lld",&x);
    for(i=0;i<n;i++)scanf("%lld",a+i);
    ba[0]=max(a[0],(ll)0);
    bn[0]=bx[0]=be[0]=max(max(a[0],a[0]*x),(ll)0);
    for(i=1;i<n;i++)
    {
        ba[i]=max(ba[i-1]+a[i],(ll)0);
        bx[i]=max(ba[i],bx[i-1]+a[i]*x);
        bn[i]=max(bx[i],bn[i-1]+a[i]);
        be[i]=max(be[i-1],bn[i]);
    }
    printf("%lld\n",be[n-1]);
    frees(a);frees(ba);frees(bn);frees(bx);frees(be);
    return 0;
}