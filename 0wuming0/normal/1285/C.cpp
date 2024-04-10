#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[30];
ll an;
void ko(ll n)
{
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
                a[an]++;
            }

            //a[an]=i^a[an]
            ll t=a[an];
            a[an]=1;
            while(t--)
            {
                a[an]*=i;
            }
            an++;
        }
    }
    if(n!=1)
    {
        a[an]=n;
        an++;
    }
}
int main()
{
    ll n,sum=10000000000000ll;
    //cout<<sum;
    cin>>n;
    ko(n);
    sort(a,a+an);
    ll t=(1<<an);
    for(ll i=0;i<t;i++)
    {
        //i  n .... 2  1
        ll p=i;ll now=1;
        for(int j=0;j<an;j++)
        {
            if(p%2)now*=a[j];
            p/=2;
        }
        sum=min(max(n/now,now),sum);
    }
    cout<<n/sum<<" "<<sum<<endl;
    return 0;
}
/*
*/