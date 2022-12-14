#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define bp __builtin_popcount
#define fir first
#define sec second
#define pss pair<short, short>
#define pii pair<int, int>
#define pll pair<ll, ll>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1 , 0};
const int mxN=1000010;
const int mxM=350;
const int mxK=350;
const ll MOD=998244353;
const ll INF=100000000000001;
int N;
ll dp[mxN];
ll yaksu[mxN];
ll sum;
int main()
{
    gibon
    cin >> N;
    dp[0]=1;
    for(int i=1;i<=N;i++)
    {
        for(int j=2*i;j<=N;j+=i)
        {
            yaksu[j]++;
        }
    }
    sum=1;
    for(int i=1;i<=N;i++)
    {
        dp[i]=sum+yaksu[i]; dp[i]%=MOD;
        sum+=dp[i]; sum%=MOD;
    }
    cout << dp[N];
}