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
int Chk[mxN];   ///  max   ?
int mini;
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
        if(A[1]==A[2])  cout << 1;
        else    cout << 2;
        return 0;
    }
    for(int i=0;i<=N;i++)   Chk[i]=-1;
    for(int i=2;i<=N;i++)
    {
        if(A[i]==A[i-1])    S[i]=S[i-1];
        else    S[i]=S[i-1]+1;
    }
    dp[N-1]=S[N-1];
    mini=dp[N-1];
    Chk[A[N]]=mini;
    for(int i=N-2;i>=1;i--)
    {
        int res=S[N]-S[i+1];
        if(Chk[A[i]]==mini)
        {
            res=min(res, mini-S[i+1]);
        }
        else
        {
            res=min(res, mini+1-S[i+1]);
        }
        res+=S[i];
        dp[i]=res;
        mini=min(mini, res);
        if(Chk[A[i+1]]==-1) Chk[A[i+1]]=res;
        else    Chk[A[i+1]]=min(Chk[A[i+1]], res);
    }
    ans=S[N]+1;
    for(int i=1;i<=N-1;i++)
    {
        ans=min(ans, dp[i]+2);
    }
    cout << ans;
}