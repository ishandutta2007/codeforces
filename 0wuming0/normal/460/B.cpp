#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll solve(ll x)
{
    ll ans=0;
    while(x)ans+=x%10,x/=10;
    return ans;
}
int ans[100000],nn;
int add(int x)
{
    ans[nn++]=x;
}
ll a,b,c;
int out(int x)
{
    ll ans=1;
    for(int i=0;i<a;i++)
    {
        ans=ans*x;
        if(ans*b+c>=1e9)return -21412512;
    }
    return ans*b+c;
}
int main()
{//cout<<solve(24)<<endl;
    cin>>a>>b>>c;
    if(a>1)
    {
        for(int i=1;i<40000;i++)
        {
            int t;
            t=out(i);
            if(t==-21412512)break;
            if(solve(t)==i)
            {//cout<<i<<endl;
                add(t);
            }
        }
    }
    else
    {
        for(int i=1;i<=1e7;i++)
        {
            if(b*solve(i)+c==i)add(i);
        }
    }
    sort(ans,ans+nn);
    cout<<nn<<endl;
    for(int i=0;i<nn;i++)printf("%d ",ans[i]);
    return 0;
}