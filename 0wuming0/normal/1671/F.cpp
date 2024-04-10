#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define N 26
ll mod=998244353;
ll dp[N][N][N][12][12];
ll ans[N][12][12];
ll save[N][N][12][12];
ll inv[100],invjie[100];
ll mul[N][N];
ll C(ll n,ll m)
{
    return invjie[m]*mul[n][m]%mod;
}
int main()
{
    inv[1]=invjie[0]=1;
    for(int i=2;i<100;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    for(int i=1;i<100;i++)invjie[i]=invjie[i-1]*inv[i]%mod;
    dp[1][1][1][0][0]=1;
    save[0][0][0][0]=1;
    for(int i=2;i<N;i++)for(int j=1;j<=i-1;j++)for(int now=1;now<=i-1;now++)for(int k=1;k<=i;k++)
    {
        int dx=i-k,dy=0,now2=now;
        if(j>=k)dy=1;
        if(k<=now)now2=i;
        for(int x=0;x+dx<12;x++)for(int y=0;y+dy<12;y++)
        {
            dp[i][k][now2][x+dx][y+dy]+=dp[i-1][j][now][x][y];
            while(dp[i][k][now2][x+dx][y+dy]>=mod)dp[i][k][now2][x+dx][y+dy]-=mod;
        }
    }
    for(int i=2;i<N;i++)for(int j=1;j<=i;j++)for(int x=0;x<12;x++)for(int y=0;y<12;y++)
    {
        ans[i][x][y]+=dp[i][j][i][x][y];
        while(ans[i][x][y]>=mod)ans[i][x][y]-=mod;
    }
    for(int k=0;k<N-1;k++)for(int i=0;i<N-1;i++)for(int j=i+1;j<N;j++)
    for(int a=0;a<12;a++)for(int c=a;c<12;c++)for(int b=0;b<12;b++)for(int d=b;d<12;d++)
    {
        save[j][k+1][c][d]=(save[j][k+1][c][d]+save[i][k][a][b]*ans[j-i][c-a][d-b])%mod;
    }//for(int i=1;i<N;i++)for(int j=1;j<N;j++)for(int x=0;x<12;x++)for(int y=0;y<12;y++)cout<<"<<"<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<save[i][j][x][y]<<endl;
    //for(int i=1;i<N;i++)for(int x=0;x<12;x++)for(int y=0;y<12;y++)cout<<"<<"<<i<<" "<<x<<" "<<y<<" "<<ans[i][x][y]<<endl;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,x;
        scanf("%d%d%d",&n,&k,&x);
        ll ans=0;
        for(int i=0;i<N;i++)
        {
            mul[i][0]=1;
            for(int j=1;j<N;j++)
            {
                mul[i][j]=mul[i][j-1]*(n-i-j+1)%mod;
            }
        }
        for(int i=1;i<N;i++)for(int j=1;j<=i;j++)
        {
            if(i>n)continue;//if(save[i][j][k][x])cout<<"<<"<<i<<" "<<j<<" "<<k<<" "<<x<<" "<<save[i][j][k][x]<<" "<<C(n-i+j,j)<<" "<<n-i+j<<" "<<j<<endl;
            ans=(ans+save[i][j][k][x]*C(i-j,j))%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}