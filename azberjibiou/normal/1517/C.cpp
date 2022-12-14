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
const int mxK=100000;
const ll MOD=1000000007;
const ll INF=100000000000001;
int N;
int A[mxN];
int ans[mxN][mxN];
int main()
{
    gibon
    cin >> N;
    for(int i=1;i<=N;i++)   cin >> A[i];
    for(int i=N;i>=1;i--)
    {
        pii now={i, i};
        int tmp=A[i];
        while(tmp--)
        {
            ans[now.fir][now.sec]=A[i];
            if(now.fir!=N && ans[now.fir+1][now.sec]==0)
            {
                now.fir++;
            }
            else
            {
                now.sec--;
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }

}