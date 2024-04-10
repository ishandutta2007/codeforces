#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll solve(ll x,ll y)
{
    ll ans=0;
    if(y<=1e5)
    {
        for(int i=1;i<=y;i++)
        {
            ans+=x/i;
        }
        return ans;
    }
    for(int i=1;i<=1e5;i++)
    {
        ans+=x/i;
    }
    //>=1e5 ,y
    for(int i=1;i<=1e5;i++)
    {
        ll r=x/i;
        if(r<=1e5)break;
        r=min(r,y);
        ans+=r-1e5;
    }
    return ans;
}
int main()
{
    int t;//cout<<solve(3,4)<<endl;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;
        ll t=(ll)sqrt(x+2);
        if(t*t>x+1)t--;//cout<<"t:"<<t<<endl;
        ll ans=0;
        if(y<=t)ans=y*(y-1)/2;
        else
        {
            ans+=t*(t-1)/2;
            ans+=solve(x,y+1)-solve(x,t+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}