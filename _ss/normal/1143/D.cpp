#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e5+1;

ll gcd (ll a,ll b)
{
    ll r;
    while (b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    ll n,k,a,b,maxkq=0,minkq=1e18,l,kq,g,tmp;
    cin>>n>>k>>a>>b;
    tmp=n*k;
    for (int i=0;i<n;i++)
    {
        l=(k*i+a-b)%tmp;
        if (l<0) l+=n*k;
        g=gcd(l,n*k);
        kq=(n*k)/g;
        if (kq<minkq) minkq=kq;
        if (kq>maxkq) maxkq=kq;

        l=(k*i+a+b)%tmp;
        g=gcd(l,n*k);
        kq=(n*k)/g;
        if (kq<minkq) minkq=kq;
        if (kq>maxkq) maxkq=kq;

        l=(k*i-a+b)%tmp;
        if (l<0) l+=n*k;
        g=gcd(l,n*k);
        kq=(n*k)/g;
        if (kq<minkq) minkq=kq;
        if (kq>maxkq) maxkq=kq;

        l=(k*i-a-b)%tmp;
        if (l<0) l+=n*k;
        g=gcd(l,n*k);
        kq=(n*k)/g;
        if (kq<minkq) minkq=kq;
        if (kq>maxkq) maxkq=kq;
    }
    cout<<minkq<<" "<<maxkq;
    return 0;
}