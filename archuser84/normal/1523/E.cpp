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

const int N = 1e5 + 10;
const int mod = 1e9 + 7;
ll fact[N];
ll mpow(ll x, ll y)
{
    ll ans = 1;
    while(y)
    {
        if(y&1) ans = ans*x % mod;
        x = x*x % mod;
        y >>= 1;
    }
    return ans;
}
inline ll C(int n, int r){return r < 0 || n < r? 0: fact[n]*mpow(fact[r]*fact[n-r] % mod, mod-2) % mod;}

int main()
{
    FAST;
    fact[0] = 1; Loop(i,1,N) fact[i] = fact[i-1]*i % mod;
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        ll ans = 1;
        for(int i = 1; i <= n-(i-1)*(k-1); ++ i)
            ans = (ans + C(n-(i-1)*(k-1), i)*mpow(C(n, i), mod-2)) % mod;
        cout << ans << '\n';
    }
}