#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (220)
#define K (41*1000)
#define INF ((ll)1e9)
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,a,b,h[N],dp[2][2][K],ans=INF;

int main()
{
    fin>>n>>a>>b;
    for(ll i=0,sum=0;i<n;i++)
    {
        fin>>h[i];
        sum+=h[i];
        for(ll j=0;j<=a;j++)
        {
            if(sum-j>b){dp[0][(i&1)][j]=dp[1][(i&1)][j]=INF;continue;}
            if(j<h[i])dp[0][(i&1)][j]=INF;
            else dp[0][(i&1)][j]=min(dp[0][!(i&1)][j-h[i]],dp[1][!(i&1)][j-h[i]]+min(h[i],h[i-1]));
            if(sum-j<h[i])dp[1][(i&1)][j]=INF;
            else dp[1][(i&1)][j]=min(dp[1][!(i&1)][j],dp[0][!(i&1)][j]+min(h[i],h[i-1]));
        }
        if(i==n-1)
            for(ll j=0;j<=a;j++)
                ans=min(ans,min(dp[0][(i&1)][j],dp[1][(i&1)][j]));
    }
    if(ans>=INF)fout<<-1;
    else fout<<ans;
    return 0;
}