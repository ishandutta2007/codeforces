#include"bits/stdc++.h"
using namespace std;
#define ll long long
map<ll,int>p[40];
char s[40];
ll dv(ll a,ll b)
{
    int n=0,m=0;
    while(a>>n)n++;
    while(b>>m)m++;
    ll ans=0;
    for(int i=n-m;i>=0;i--)
    {
        if((a^(b<<i))<a)
        {
            a^=(b<<i);
            ans|=(1ll<<i);
        }
        a=min(a,a^(b<<i));
    }
    if(a)return -1;
    else return ans;
}
ll dp[40];
ll temp[40];
bool check(ll k,ll mul)
{
    ll ans=1;
    for(int i=0;i<40;i++)if(k&(1ll<<i))
    {
        temp[0]=ans;
        for(int j=1;j<40;j++)
        {
            temp[j]=min(temp[j-1]*2,temp[j-1]*2^mul);
        }
        ans=0;
        for(int j=0;j<40;j++)if((1ll<<j)&dp[i])
        {
            ans^=temp[j];
        }
    }
    if(ans==1)return 1;
    else return 0;
}
ll solve(ll mul)
{
    dp[0]=2;
    for(int i=1;i<40;i++)
    {
        dp[i]=0;
        temp[0]=dp[i-1];
        for(int j=1;j<40;j++)
        {
            temp[j]=min(temp[j-1]*2,temp[j-1]*2^mul);
        }
        for(int j=0;j<40;j++)if((1ll<<j)&dp[i-1])
        {
            dp[i]^=temp[j];
        }
    }
    int m;
    for(m=40;m>=0;m--)if(mul&(1ll<<m))break;
    ll ans=(1ll<<m)-1;
    for(auto pr:p[m])
    {
        while(ans%pr.first==0)
        {
            if(check(ans/pr.first,mul))ans/=pr.first;
            else break;
        }
    }
    return ans;
}
ll get(ll mul)
{
    map<ll,int>mp;
    for(int i=2;i<(1<<18);i++)
    {
        if(dv(mul,i)!=-1)
        {
            while(dv(mul,i)!=-1)
            {
                mp[i]++;
                mul=dv(mul,i);
            }
        }
    }
    if(mul>1)mp[mul]++;
    ll ans=1;
    for(auto pr:mp)
    {
        ll s=solve(pr.first);
        int k=1;
        while(k<pr.second)k*=2;
        s*=k;
        ans*=s/__gcd(ans,s);
    }
    return ans;
}
ll baoli(ll mul)
{
    ll ans=mul-1;
    ll m=0;
    while(ans&(ans-1))
    {
        m++;
        ans>>=1;
        if(ans&1)ans^=mul;
    }
    for(int i=0;;i++)if((1ll<<i)&ans)break;else m++;
    return m;
}
int main()
{
    for(ll now=1;now<=35;now++)
    {
        ll n=(1ll<<now)-1;
        for(ll i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                    n/=i;
                    p[now][i]++;
                }
            }
        }
        if(n>1)p[now][n]++;
    }
    int add=0;
    ll mul=0;
    cin>>s;
    for(int i=strlen(s)-1;i>=0;i--)
    {
        mul*=2;
        if(s[i]=='1')mul++;
    }
    if(mul==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    while(mul%2==0)
    {
        mul/=2;
        add++;
    }
    add++;
    cout<<add<<" "<<add+get(mul)<<endl;
    return 0;
}