#include"bits/stdc++.h"
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        if(a==b)printf("0 0\n");
        else
        {
            ll c=max(a,b)-min(a,b),d=min(a,b);
            printf("%lld %lld\n",c,min(c-b%c,b%c));
        }
    }
    return 0;
}