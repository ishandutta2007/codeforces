///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;

const int N = 18;
double a[N][N];
double dp[1<<N]={};
int n;

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n)
        Loop(j,0,n)
            cin >> a[i][j];
    dp[(1<<n)-1] = 1;
    LoopR(mask,1,(1<<n)-1)
    {
        int k = __builtin_popcount(mask);
        Loop(i,0,n)
            Loop(j,0,n)
                if((mask&(1<<i)) && !(mask&(1<<j)))
                    dp[mask] += a[i][j] * dp[mask|(1<<j)];
        dp[mask] /= (k*(k+1)/2);
    }
    cout << fixed << setprecision(9);
    Loop(i,0,n)
        cout << dp[1<<i] << ' ';
}