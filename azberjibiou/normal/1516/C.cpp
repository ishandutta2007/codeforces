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
const int mxN=106;
const int mxK=100000;
const ll MOD=1000000007;
const ll INF=100000000000001;
int N;
int A[mxN];
bool dp[200101][2];
int sum=0;
int main()
{
    gibon
    cin >> N;
    for(int i=1;i<=N;i++)   cin >> A[i];
    while(true)
    {
        bool jogun=true;
        for(int i=1;i<=N;i++)   if(A[i]%2==1)   jogun=false;
        if(!jogun)  break;
        for(int i=1;i<=N;i++)   A[i]/=2;
    }
    for(int i=1;i<=N;i++)   sum+=A[i];
    if(sum%2==1)
    {
        cout << 0 << '\n';
        return 0;
    }
    dp[0][1]=true;
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=200000;j++)  dp[j][0]=dp[j][1];
        for(int j=0;j<=200000;j++)  dp[j][1]=false;
        for(int j=0;j<A[i];j++)
        {
            if(dp[j][0])    dp[j][1]=true;
        }
        for(int j=A[i];j<=200000;j++)
        {
            if(dp[j][0] || dp[j-A[i]][0])   dp[j][1]=true;
        }
    }
    if(!dp[sum/2][1])
    {
        cout << 0 << '\n';
        return 0;
    }
    else
    {
        cout << 1 << '\n';
        for(int i=1;i<=N;i++)
        {
            if(A[i]%2==1)
            {
                cout << i;
                return 0;
            }
        }
    }
}