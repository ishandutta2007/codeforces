#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll _9[100];
ll solve(ll n,ll i)
{
    ll now=_9[i]/9;
    n--;
    now+=(n/i);
    n%=i;
    char s[100];
    sprintf(s,"%lld",now);
    return s[n]-(ll)'0';
}
ll solve2(ll n)
{
    if(n<=9)return n;
    ll ans=0;
    int i;
    for(i=1;;i++)
    {
        if(_9[i]*i>=(n-ans))break;////////////////////////////////////////
        ans+=_9[i]*i;
    }
    n-=ans;
    //cout<<"?"<<n<<"  "<<i<<endl;
    return solve(n,i);
    //cout<<solve(n,i)<<endl;
}
ll solve3(ll n)
{
    if(n<=9)return n*(n+1)/2;
    else if(n<=99)
    {
        ll ans=0;
        ans+=solve3(9);
        n-=9;
        ans+=9*n;
        ans+=2*n*(n+1)/2;
        return ans;
    }
    else if(n<=999)
    {
        ll ans=0;
        ans+=solve3(99);
        ll c=ans-solve3(98);
        n-=99;
        ans+=c*n;
        ans+=3*n*(n+1)/2;
        return ans;
    }
    else if(n<=9999)
    {
        ll ans=0;
        ans+=solve3(999);
        ll c=ans-solve3(998);
        n-=999;
        ans+=c*n;
        ans+=4*n*(n+1)/2;
        return ans;
    }
    else if(n<=99999)
    {
        ll ans=0;
        ans+=solve3(9999);
        ll c=ans-solve3(9998);
        n-=9999;
        ans+=c*n;
        ans+=5*n*(n+1)/2;
        return ans;
    }
    else if(n<=999999)
    {
        ll ans=0;
        ans+=solve3(99999);
        ll c=ans-solve3(99998);
        n-=99999;
        ans+=c*n;
        ans+=6*n*(n+1)/2;
        return ans;
    }
    else if(n<=9999999)
    {
        ll ans=0;
        ans+=solve3(999999);
        ll c=ans-solve3(999998);
        n-=999999;
        ans+=c*n;
        ans+=7*n*(n+1)/2;
        return ans;
    }
    else if(n<=99999999)
    {
        ll ans=0;
        ans+=solve3(9999999);
        ll c=ans-solve3(9999998);
        n-=9999999;
        ans+=c*n;
        ans+=8*n*(n+1)/2;
        return ans;
    }
    else if(n<=999999999)
    {
        ll ans=0;
        ans+=solve3(99999999);
        ll c=ans-solve3(99999998);
        n-=99999999;
        ans+=c*n;
        ans+=9*n*(n+1)/2;
        return ans;
    }
}
int main()
{
    //cout<<solve3(499999999)<<endl;
    //cout<<solve3(599999999)<<endl;
    //cout<<solve3(699999999)<<endl;
    //cout<<solve3(799999999)<<endl;
    _9[1]=9;
    for(int i=2;i<=18;i++)_9[i]=_9[i-1]*10;
    //cout<<solve2(15);
    ll q;
    cin>>q;
    while(q--)
    {
        ll n;
        cin>>n;
        ll x1=0,x2=499999999,x;
        while(x1+1!=x2)
        {
            x=(x1+x2)/2;
            if(solve3(x)>=n)x2=x;
            else x1=x;
        }
        n-=solve3(x1);//cout<<"?"<<n<<endl;
        cout<<solve2(n)<<endl;
    }
    return 0;
}
/*
10
1
2
3
4
5
6
7
8
9
10
*/