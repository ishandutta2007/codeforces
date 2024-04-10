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

const int N = 2'010;
int last[N][256];
string s;
string p;
int seg[N];
int n, m;
int dp[N][N] = {};

int main()
{
    FAST;
    cin >> s >> p;
    n = s.size();
    m = p.size();
    memset(last,-1,N*256*4);
    Loop(i,1,n)
    {
        Loop(c,0,256)
            last[i][c] = last[i-1][c];
        last[i][s[i-1]] = i-1;
    }
    LoopR(r,0,n)
    {
        seg[r] = -1;
        if(s[r] != p[m-1])
            continue;
        int l = r;
        int k = m-1;
        while(k--)
        {
            l = last[l][p[k]];
            if(l == -1)
                break;
        }
        if(l == -1)
            continue;
        seg[r] = l;
    }
    if(!seg[0])
        dp[0][0]=1;
    Loop(i,1,n)
    {
        int s = i - seg[i] + 1;
        Loop(j,0,n+1)
        {
            if(seg[i] != -1 && i+1-m >= j && j >= s-m)
            {
                if(seg[i] > 0)
                    dp[i][j] = max(max(dp[i-1][j], dp[i-1][max(j-1, 0)])
                                   , dp[seg[i]-1][j-(s-m)]+1);
                else
                    dp[i][j] = max(max(dp[i-1][j], dp[i-1][max(j-1, 0)])
                                   , 1);
            }
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][max(j-1, 0)]);
        }
    }

    Loop(j,0,n+1)
        cout << dp[n-1][j] << ' ';
}