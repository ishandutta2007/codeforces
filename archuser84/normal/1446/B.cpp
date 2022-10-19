#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 5'010;
int dp[N][N]={};
int dpsuf[N][N]={};
char A[N], B[N];
int n, m;

int main()
{
    FAST;
    cin >> n >> m;
    cin >> A >> B;
    Loop(i,0,n)
    {
        Loop(j,0,m)
        {
            dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            if(A[i] == B[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dpsuf[i][j] + 2);

            dpsuf[i+1][j+1] = max(dpsuf[i][j+1], dpsuf[i+1][j]) - 1;
            if(A[i] == B[j]) dpsuf[i+1][j+1] = max(dpsuf[i+1][j+1], dpsuf[i][j] + 2);
            dpsuf[i+1][j+1] = max(dpsuf[i+1][j+1], 0);
        }
    }
    /*Loop(i,0,n)
    {
        Loop(j,0,m)
            cout << dp[i+1][j+1] << ' ';
        cout << '\n';
    }Loop(i,0,n)
    {
        Loop(j,0,m)
            cout << dpsuf[i+1][j+1] << ' ';
        cout << '\n';
    }*/
    cout << dp[n][m] << '\n';
}