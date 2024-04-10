#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) {cout << x << '\n'; return 0;}
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int N = 110;
int dp[11][N][N] = {};
int table[11][N][N] = {};
int n, q, c;

int main()
{
    FAST;
    cin >> n >> q >> c; c++;
    Loop(i,0,n)
    {
        int x, y, s;
        cin >> x >> y >> s;
        table[s][x][y]++;
    }
    Loop(k,0,c)
        Loop(i,1,N)
            Loop(j,1,N)
                dp[k][i][j] = table[k][i][j] + dp[k][i][j-1] + dp[k][i-1][j] - dp[k][i-1][j-1];
    while(q--)
    {
        int t,x1,y1,x2,y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        x1--; y1--;
        int ans = 0;
        Loop(k,0,c)
        {
            int x = dp[k][x2][y2] - dp[k][x2][y1] - dp[k][x1][y2] + dp[k][x1][y1];
            x *= (k+t)%c;
            ans += x;
        }
        cout << ans << '\n';
    }
}