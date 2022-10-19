#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
ll pows(ll a,ll b)
{
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)
    {
        if(b%2)ans=ans*a%mod;
    }
    return ans%mod;
}
ll dev(ll n)
{
    return pows(n,mod-2);
}
ll dp[200005];
ll odd[200005];
ll even[200005];
int main()
{
    //
    dp[1]=dp[2]=1;
    odd[1]=even[2]=1;
    for(int i=3;i<200005;i++)
    {
        if(i%2)
        {
            dp[i]=(even[i-1]+1)%mod;
            odd[i]=(odd[i-2]+dp[i])%mod;
        }
        else
        {
            dp[i]=odd[i-1]%mod;
            even[i]=(even[i-2]+dp[i])%mod;
        }
    }
    int n;
    cin>>n;
    cout<<dp[n]*pows(dev(2),n)%mod<<endl;
    return 0;
}