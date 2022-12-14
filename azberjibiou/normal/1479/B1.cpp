#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define fir first
#define sec second
#define pss pair<short, short>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<long double, long double>
typedef long long ll;
using namespace std;
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1 , 0};
const int mxN=100005;
const int mxM=2000100;
const int mxK=32;
const ll MOD=1999;
const ll INF=100000000000001;
int N;
int A[mxN];
int S[mxN];
int dp[mxN];
int col[mxM];
int maxi;
int ans;
int main()
{
    gibon
    cin >> N;
    for(int i=1;i<=N;i++)   cin >> A[i];
    if(N==1)
    {
        cout << 1;
        return 0;
    }
    if(N==2)
    {
        cout << 2;
        return 0;
    }
    for(int i=2;i<=N;i++)
    {
        if(A[i]==A[i-1])    S[i]=S[i-1];
        else    S[i]=S[i-1]+1;
    }
    dp[N-1]=S[N-1];
    maxi=dp[N-1];
    col[maxi]=A[N];
    for(int i=N-2;i>=1;i--)
    {
        int res=S[N]-S[i+1];
        if(col[maxi]!=-1 && col[maxi]==A[i])
        {
            res=max(res, maxi-S[i+1]);
        }
        else
        {
            res=max(res, maxi+1-S[i+1]);
        }
        res+=S[i];
        dp[i]=res;
        if(res==maxi)
        {
            if(col[maxi]!=-1 && A[i+1]!=col[maxi])    col[maxi]=-1;
        }
        else if(res>maxi)
        {
            maxi=res;
            col[maxi]=A[i+1];
        }
    }
    ans=S[N]+1;
    for(int i=1;i<=N-1;i++)
    {
        ans=max(ans, dp[i]+2);
    }
    cout << ans;
}