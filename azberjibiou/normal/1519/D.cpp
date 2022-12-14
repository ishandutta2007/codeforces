#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define bp __builtin_popcount
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
const int mxN=5020;
const int mxM=104;
const int mxK=1000000;
const ll MOD=1000000007;
const ll INF=100000000000001;
int N;
ll A[mxN], B[mxN];
ll ans;
ll sum;
ll dp[mxN][mxN];
ll dping(int s, int e)
{
    if(dp[s][e]!=0) return dp[s][e];
    if(s+1==e || s+2==e)
    {
        return dp[s][e]=sum-A[s]*B[s]-A[e]*B[e]+A[s]*B[e]+A[e]*B[s];
    }
    return dp[s][e]=dping(s+1, e-1)-A[s]*B[s]-A[e]*B[e]+A[s]*B[e]+A[e]*B[s];
}
int main()
{
    gibon
    cin >> N;
    for(int i=1;i<=N;i++)   cin >> A[i];
    for(int i=1;i<=N;i++)   cin >> B[i];
    for(int i=1;i<=N;i++)   sum+=A[i]*B[i];
    ans=sum;
    for(int i=1;i<=N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            dping(i, j);
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            ans=max(ans, dping(i, j));
        }
    }
    cout << ans;
}