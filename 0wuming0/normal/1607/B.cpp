#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll solve(ll n)
{
    if(n==0)return 0;
    ll ans=-(n-1)/4*4-1;
    ll now=1+(n-1)/4*4;
    if(n-now==1)ans+=now+1;
    else if(n-now==2)ans+=now+1+now+2;
    else if(n-now==3)ans+=now+1+now+2-now-3;
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll x,n;
        scanf("%lld%lld",&x,&n);
        if(x%2==0)cout<<x+solve(n)<<endl;
        else cout<<x-solve(n)<<endl;
    }
    return 0;
}