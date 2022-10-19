#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
int a[54];
int b[54];
ll sumb;
int n,m;
ll dev[250005];
int wa,wb;
ll dp[51][51][51];
void solve(int x)
{
    for(int i=0;i<51;i++)for(int j=0;j<51;j++)for(int k=0;k<51;k++)dp[i][j][k]=0;
    int aw=wa,bw=wb,mw=0;
    mw=b[x];
    if(a[x])aw-=b[x];
    else bw-=b[x];
    int op=2*a[x];
    op--;
    dp[0][0][0]=1;
    ll d;
    for(int num=0;num<m;num++)
    {
        int a,b,c;
        for(int i=num;i>=0;i--)for(int j=num;j>=0;j--)for(int k=num;k>=0;k--)
        {
            a=aw+i;
            b=bw-j;
            c=mw+op*k;
            d=dev[a+b+c];
            dp[i+1][j][k]=(dp[i+1][j][k]+dp[i][j][k]*a%mod*d)%mod;
            dp[i][j+1][k]=(dp[i][j+1][k]+dp[i][j][k]*b%mod*d)%mod;
            dp[i][j][k+1]=(dp[i][j][k+1]+dp[i][j][k]*c%mod*d)%mod;
            dp[i][j][k]=0;
        }
    }
    ll ans=0;
    for(int i=0;i<51;i++)for(int j=0;j<51;j++)for(int k=0;k<51;k++)
    {
        ans+=k*dp[i][j][k]%mod;
        ans%=mod;
    }
    if(a[x]==0)ans=(b[x]-ans)%mod;
    else ans=(b[x]+ans)%mod;
    if(ans<0)ans+=mod;
    cout<<ans<<endl;
}
int main()
{
    dev[1]=1;
    for(int i=2;i<250005;i++)
    {
        dev[i]=(mod-(mod/i)*dev[mod%i]%mod)%mod;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    ll s=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",b+i);
        s+=a[i];
        sumb+=b[i];
        if(a[i])wa+=b[i];
        else wb+=b[i];
    }
    for(int i=1;i<=n;i++)
    {
        solve(i);
    }
    return 0;
}
/*
3 3
 1 1 0
 3 5 4
*/