#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=5123,inf=1e18,mod=1e9+7,N=360360;
ll n,a[maxn],dp[maxn][maxn],DP[maxn],ans[maxn];
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    IOS                                   
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++)
            dp[i][j]=inf;
        DP[i]=inf;
    }
    DP[0]=0;
    a[0]=a[n+1]=-1e9;
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){                                                                                         
            dp[i+1][j]=min(dp[i+1][j],dp[i-1][j-1]+max(0ll,min(a[i-2]-1,a[i-1])-a[i]+1)+max(0ll,a[i+1]-a[i]+1));  
            dp[i+1][j]=min(dp[i+1][j],DP[j-1]+max(0ll,a[i-1]-a[i]+1)+max(0ll,a[i+1]-a[i]+1));    
          //  cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
        for(int j=1;j<=n;j++)
            DP[j]=min(DP[j],dp[i][j]);    
    }
    for(int i=1;i<=(n+1)/2;i++)
        cout<<min(DP[i],dp[n+1][i])<<" ";
}