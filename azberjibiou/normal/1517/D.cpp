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
const int mxN=506;
const int mxK=20;
const int MOD=1000000007;
const ll INF=100000000000001;
typedef struct line{
    ll x, y, val;
}line;
int N, M, K;
vector <line> v[mxN][mxN];
ll dp[mxK][mxN][mxN];
int main()
{
    gibon
    cin >> N >> M >> K;
    if(K%2==1)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                cout << -1 << " ";
            }
            cout << '\n';
        }
        return 0;
    }
    K/=2;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M-1;j++)
        {
            int tmp;
            cin >> tmp;
            v[i][j].push_back({i, j+1, tmp});
            v[i][j+1].push_back({i, j, tmp});
        }
    }
    for(int i=1;i<=N-1;i++)
    {
        for(int j=1;j<=M;j++)
        {
            int tmp;
            cin >> tmp;
            v[i][j].push_back({i+1, j, tmp});
            v[i+1][j].push_back({i, j, tmp});
        }
    }
    for(int i=1;i<=K;i++)
    {
        for(int j=1;j<=N;j++)   for(int k=1;k<=M;k++)   dp[i][j][k]=MOD;
        for(int j=1;j<=N;j++)
        {
            for(int k=1;k<=M;k++)
            {
                for(line nxt : v[j][k])
                {
                    dp[i][j][k]=min(dp[i][j][k], dp[i-1][nxt.x][nxt.y]+nxt.val);
                }
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cout << 2*dp[K][i][j] << " ";
        }
        cout << '\n';
    }
}