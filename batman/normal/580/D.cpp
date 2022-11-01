#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N (20)
ll n,m,k,a[N],dp[1<<N][N],e[N][N],u,v,w,ans;

int main()
{
    cin>>n>>m>>k;
    for(ll i=0;i<n;i++)cin>>a[i],dp[1<<i][i]=a[i];
    for(ll i=0;i<k;i++)cin>>u>>v>>w,e[u-1][v-1]=w;  
    for(ll i=0,cnt=0,ex=0;i<1<<n;ans=max(ans,(cnt==m)?ex:0ll),i++,cnt=0,ex=0)
        for(ll j=0;j<n;j++)
            if((1<<j)&i)
            {
                cnt++;
                for(ll p=0;p<n;p++)
                    if(p!=j && (1<<p)&i)
                        dp[i][j]=max(dp[i][j],dp[i-(1<<j)][p]+e[j][p]+a[j]);    
                ex=max((ll)ex,dp[i][j]);        
            }   
    cout<<ans;                      
    return 0;
}