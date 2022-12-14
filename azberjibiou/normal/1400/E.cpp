#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pii pair<int, int>
#define pll pair<ll, ll>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1 , 0};
const int mxN=5050;
const int mxM=505;
const ll MOD=1000000007;
const ll INF=1000000000000000000;
int N;
int A[mxN];
ll dp[mxN][mxN];
int lim;
int main()
{
    gibon
    cin >> N;
    for(int i=1;i<=N;i++)   cin >> A[i];
    for(int i=1;i<=N;i++)   for(int j=0;j<=N;j++)   dp[i][j]=-1;
    for(int i=1;i<=N+1;i++)
    {
        if(A[i]<=lim)
        {
            for(int j=0;j<A[i];j++)
            {
                dp[i][j]=dp[i-1][j]+1;
            }
            dp[i][A[i]]=dp[i-1][A[i]];
            for(int j=A[i]+1;j<=lim;j++)    dp[i][A[i]]=min(dp[i][A[i]], dp[i-1][j]);
            lim=A[i];
        }
        else
        {
            for(int j=0;j<=lim;j++)
            {
                dp[i][j]=dp[i-1][j]+1;
            }
            for(int j=lim+1;j<=min(A[i]-1, 5000);j++)
            {
                dp[i][j]=dp[i-1][lim]+j-lim+1;
            }
            if(A[i]<=5000)
                dp[i][A[i]]=dp[i-1][lim]+A[i]-lim;
            lim=min(A[i], 5000);
        }
    }
    cout << dp[N+1][0];
}