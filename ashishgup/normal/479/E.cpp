#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5005;
const int MOD=1e9+7;

int n, a, b, k;
int pref[N], dp[N][N];

int rsum(int L, int R)
{
    return (pref[R] - pref[L-1] + MOD)%MOD;
}

int32_t main()
{
    IOS;
    cin>>n>>a>>b>>k;
    for(int i=1;i<=n;i++)
    {
        dp[i][k+1]=1;
        pref[i]=pref[i-1]+1;
    }
    for(int turn=k;turn>=1;turn--)
    {
        for(int floor=1;floor<=n;floor++)
        {
            int dist=abs(floor-b) - 1;
            int L=max(1, floor-dist);
            int R=min(n, floor+dist);
            dp[floor][turn]=rsum(L, R) - rsum(floor, floor) + MOD;
            dp[floor][turn]%=MOD;
        }  
        for(int floor=1;floor<=n;floor++)
        {
            pref[floor]=pref[floor-1] + dp[floor][turn];
            pref[floor]%=MOD;
        }     
    }
    int ans=dp[a][1];
    cout<<ans;
    return 0;
}