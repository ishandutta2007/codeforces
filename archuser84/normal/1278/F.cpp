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
//#pragma GCC optimize("O0")

const int mod = 998244353;
const int N = 5010;

ll mpow(ll x, ll e)
{
    ll ans = 1;
    while(e)
    {
        if(e&1) ans = ans*x % mod;
        x = x*x % mod;
        e >>= 1;
    }
    return ans;
}

ll magic[N][N]; //magic[i][j] donbale be toole i az andis ha ba j ta adade motemayez
int n, m, k;

int main()
{
    FAST;
    cin >> n >> m >> k;
    magic[0][0] = 1;
    Loop(i,1,N)
    {
        Loop(j,0,N-1)
        {
            magic[i]  [j] = (magic[i]  [j] + magic[i-1][j]*   j ) % mod;
            magic[i][j+1] = (magic[i][j+1] + magic[i-1][j]*(n-j)) % mod;
        }
    }
    ll ans = 0;
    Loop(i,1,min(k, n)+1)
    {
        ans = (ans + magic[k][i]*mpow(m, n-i)) % mod;
    }
    ans = ans*mpow(mpow(m, n), mod-2) % mod;
    cout << ans << '\n';
}