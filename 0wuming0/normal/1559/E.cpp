#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
int prime[100005];
ll sum;
int n,sm,sl[55],sr[55],m,l[55],r[55];
ll dp[200005],save[200005];
void solve(int k)
{
    int op=1;
    for(int i=k;i!=1;)
    {
        int p=prime[i];
        i/=p;
        if(i%p==0)
        {
            return;
        }
        op^=1;
    }
    ll ans=0;
    m=sm/k;
    for(int i=1;i<=n;i++)
    {
        l[i]=(sl[i]-1)/k+1;
        r[i]=sr[i]/k;
        if(l[i]>r[i])return;
    }
    for(int i=0;i<=m;i++)dp[i]=save[i]=0;
    save[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[j+l[i]]+=save[j];
            dp[j+r[i]+1]-=save[j];
        }
        for(int j=1;j<=m;j++)
        {
            dp[j]=(dp[j]+dp[j-1])%mod;
        }
        for(int j=0;j<=m;j++)
        {
            save[j]=dp[j];
            dp[j]=0;
        }
    }
    for(int i=1;i<=m;i++)ans+=save[i];
    if(op)sum+=ans%mod;
    else sum-=ans%mod;
}
int main()
{
    for(int i=2;i<100005;i++)if(prime[i]==0)
    {
        prime[i]=i;
        for(int j=2;i*j<100005;j++)prime[i*j]=i;
    }
    cin>>n>>sm;
    for(int i=1;i<=n;i++)scanf("%d%d",sl+i,sr+i);
    for(int i=1;i<=sm;i++)solve(i);
    sum%=mod;
    if(sum<0)sum+=mod;
    cout<<sum<<endl;
    return 0;
}