#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF ((ll)1e14)
#define N (501)

ll n,a[N],dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i],dp[i][i]=1;
    for(int t=2;t<=n;t++)
        for(int i=0;i+t-1<n;i++)
        {
            int j=i+t-1;
            dp[i][j]=1+dp[i+1][j];
            if(a[i]==a[j])dp[i][j]=min(dp[i][j],(i+1==j)?1:dp[i+1][j-1]);
            if(a[i]==a[i+1] && i+1!=j)dp[i][j]=min(dp[i][j],1+dp[i+2][j]);
            for(int p=i+2;p<j;p++)
                if(a[p]==a[i])
                    dp[i][j]=min(dp[i][j],dp[i+1][p-1]+dp[p+1][j]);
        }
    cout<<dp[0][n-1];   
    
    return 0;
}