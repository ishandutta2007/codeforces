#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mdn(ll m,ll d,ll n)
{
    ll a,b;
    a=min(d,m);
    b=max(0ll,m-d);
    return 2*a*a+(4*d-1)*b+n+1;
}
ll f(ll a,ll b,ll n){return (a+b)*n/2;}
int main()
{
    ll x,y,n,m;
    cin>>n>>x>>m>>y;
    ll d=abs(x-y),ans;
    if(m>n)swap(n,m);
    if(n+m<=d)
    {
        ans=1+n+m;
    }
    else if(m+d<=n)
    {
        ans=mdn(m,d,n);
    }
    else if(n<=d)
    {
        ll t=m+n-d;
        ans=1+n+m+t*t;
    }
    else
    {
        ll t=n-d;
        ans=mdn(t,d,n);
        ll a,b;
        a=t+1-d;
        b=m-d;
        if(a>0)ans+=f(2*(n-a)+1,2*(n-b)+1,b-a+1);
        else if(b<=0)ans+=f(2*(n+a),2*(n+b),b-a+1);
        else ans+=f(2*(n+a),2*n,1-a)+f(2*n-1,2*(n-b)+1,b);
    }
    cout<<ans<<endl;
    return 0;
}