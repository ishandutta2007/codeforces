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
const int N = 300'010;
ll ps[N];
ll a[N];
int n;

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

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n) cin >> a[i];
    sort(a,a+n,greater<ll>());
    Loop(i,0,n) ps[i+1] = ps[i]+a[i];
    ll inv = mpow(n, mod-2);
    Loop(k,1,n+1)
    {
        ll ans = 0;
        for(ll i = 0; i*k < n; ++i)
        {
            ans = (ans + (ps[min((ll)n, (i+1)*k)] - ps[i*k])*i) % mod;
        }
        ans = ans*inv % mod;
        cout << ans << ' ';
    }
}