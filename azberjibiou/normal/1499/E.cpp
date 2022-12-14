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
const int mxN=1010;
const int mxM=10000100;
const ll mxK=2500;
const ll MOD=998244353;
const ll INF=1000000000000000001;
char A[mxN], B[mxN];
int N, M;
ll dp[mxN][mxN][2];
ll ans;
ll dping(int x, int y, int typ)
{
    if(dp[x][y][typ]!=-1)   return dp[x][y][typ];
    if(typ==0)
    {
        ll res=0;
        if(y>0 && B[y-1]!=A[x-1])  res+=dping(x-1, y, 1);
        if(x>1 && A[x-2]!=A[x-1])  res+=dping(x-1, y, 0);
        res++;
        res%=MOD;
        return dp[x][y][typ]=res;
    }
    else
    {
        ll res=0;
        if(x>0 && A[x-1]!=B[y-1])  res+=dping(x, y-1, 0);
        if(y>1 && B[y-2]!=B[y-1])  res+=dping(x, y-1, 1);
        res++;
        res%=MOD;
        return dp[x][y][typ]=res;
    }
}
int main()
{
    gibon
    cin >> A >> B;
    N=strlen(A), M=strlen(B);
    for(int i=0;i<=N;i++)   for(int j=0;j<=M;j++)   dp[i][j][0]=dp[i][j][1]=-1;
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=M;j++)
        {
            if(i!=0)
            {
                ans+=dping(i, j, 0);
            }
            if(j!=0)
            {
                ans+=dping(i, j, 1);
            }
        }
    }
    ll rem=N*(M+1)+M*(N+1);
    for(int j=0;j<=M;j++)
    {
        ll cnt=0;
        for(int i=2;i<=N;i++)
        {
            if(A[i-1]!=A[i-2])  cnt++;
            else
            {
                rem+=cnt*(cnt+1)/2;
                rem%=MOD;
                cnt=0;
            }
        }
        rem+=cnt*(cnt+1)/2;
        rem%=MOD;
    }
    for(int i=0;i<=N;i++)
    {
        ll cnt=0;
        for(int j=2;j<=M;j++)
        {
            if(B[j-1]!=B[j-2])  cnt++;
            else
            {
                rem+=cnt*(cnt+1)/2;
                rem%=MOD;
                cnt=0;
            }

        }
        rem+=cnt*(cnt+1)/2;
        rem%=MOD;
    }
    ans=((ans-rem)%MOD+MOD)%MOD;
    cout << ans;
}