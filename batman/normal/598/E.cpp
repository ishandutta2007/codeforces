#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
#define N (31)
#define K (51)
#define ll int
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;a;}return p;}
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

ll dp[N][N][K];

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)for(int k=1;k<K;k++)dp[i][j][k]=INF;
    for(int i=0;i<N;i++)for(int j=0;j<N && i*j<K;j++)dp[i][j][i*j]=0;
    
    for(int i=1;i<N;i++)
        for(int j=1;j<N;j++)
            for(int k=1;k<min(K,i*j);k++)
            {
                for(int p=1;p<i;p++)
                    for(int q=0;q<=k;q++)
                        dp[i][j][k]=min(dp[i][j][k],j*j+dp[p][j][q]+dp[i-p][j][k-q]);
                for(int p=1;p<j;p++)
                    for(int q=0;q<=k;q++)
                        dp[i][j][k]=min(dp[i][j][k],i*i+dp[i][p][q]+dp[i][j-p][k-q]);       
            }   
    ll t=0;
    scanf("%d",&t);
    while(t--)
    {
        ll n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        printf("%d\n",dp[n][m][k]);
    }       
    return 0;
}