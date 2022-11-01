#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (201*1000)
#define INF ((ll)1e9)

ll n,dp[N],id[N],a,ans;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        dp[i]=1;
        cin>>a;
        id[a]=i;
        if(id[a-1])dp[i]=dp[id[a-1]]+1;
        ans=max(ans,dp[i]);
    }
    cout<<n-ans;    
    return 0;
}