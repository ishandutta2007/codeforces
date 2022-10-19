#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll el(ll n)
{
    ll ans=1;
    for(ll i=2;n>=i*i;i++)
    {
        if(n%i==0)
        {
            ll k=1;
            while(n%i==0)
            {
                n/=i;
                k++;
            }
            ans*=k;
        }

    }//cout<<n<<endl;
    if(n>1)ans=ans*2;
    return ans;
}
ll gcd(ll a,ll b)
{
    while(a&&b)
        a>b?a%=b:b%=a;
    return a+b;
}
int main()
{
    int t;
    cin>>t;
    t--;
    ll a;
    scanf("%lld",&a);
    while(t--)
    {
        ll b;
        scanf("%lld",&b);
        a=gcd(a,b);
    }//cout<<a<<endl;
    printf("%lld\n",el(a));
    return 0;
}
/*

*/