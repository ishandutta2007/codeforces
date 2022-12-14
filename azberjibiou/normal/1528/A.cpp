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
const int mxN=100010;
const int mxM=350;
const int mxK=350;
const ll MOD=1000000007;
const ll INF=100000000000001;
int N;
vector <int> v[mxN];
ll L[mxN], R[mxN];
ll dp[mxN][2];
ll myabs(ll a)
{
    return (a>0 ? a : -a);
}
void dfs(int now, int pre)
{
    for(int nxt : v[now])   if(nxt!=pre)
    {
        dfs(nxt, now);
        dp[now][0]+=max(dp[nxt][0]+myabs(L[nxt]-L[now]), dp[nxt][1]+myabs(R[nxt]-L[now]));
        dp[now][1]+=max(dp[nxt][0]+myabs(L[nxt]-R[now]), dp[nxt][1]+myabs(R[nxt]-R[now]));
    }
}
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=1;i<=N;i++)   v[i].clear();
        for(int i=1;i<=N;i++)   cin >> L[i] >> R[i];
        for(int i=1;i<=N-1;i++)
        {
            int a, b;   cin >> a >> b;
            v[a].push_back(b);  v[b].push_back(a);
        }
        for(int i=1;i<=N;i++)   dp[i][0]=dp[i][1]=0;
        dfs(1, -1);
        cout << max(dp[1][0], dp[1][1]) << '\n';
    }
}