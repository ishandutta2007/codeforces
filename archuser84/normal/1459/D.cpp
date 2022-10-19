#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

const int N = 101;
ll dp[2][N][3*N*N] = {};
const ll inf = 1e12;
int n;
int a[N], b[N];
int psum[N] = {};

int main()
{
    FAST
    cin >> n;
    Loop(i,0,n) cin >> a[i] >> b[i];
    Loop(i,0,n+1) Loop(j,0,N*N) dp[0][i][j] = min(j-N*N, 0);
    Loop(i,0,n)
    {
        psum[i+1] = psum[i]+b[i];
        bool b = i&1;
        Loop(w,0,3*N*N) dp[!b][0][w] = min(w-N*N, psum[i+1]);
        Loop(j,1,n+1)
        {
            Loop(w,0,3*N*N)
            {
                dp[!b][j][w] = -inf;
                if(w - ::b[i] >= 0) // nemiad
                    dp[!b][j][w] = max(dp[!b][j][w], dp[b][j][w - ::b[i]] + ::b[i]);
                if(w + 2*(a[i]-::b[i]) < 3*N*N) // miad
                    dp[!b][j][w] = max(dp[!b][j][w], dp[b][j-1][w + 2*(a[i]-::b[i])] + 2*::b[i]);
                //if(N*N-2 <= w && w <= N*N+20)
                //    cerr << i+1 << ' ' << j << ' ' << w-N*N << ": " << dp[!b][j][w] << '\n';
            }
        }
    }
    Loop(k,1,n+1)
        cout << dp[n&1][k][N*N]/2. << ' ';
}