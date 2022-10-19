///
///    "Your next line is..."
///
///                                    -Joseph Joestar

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize ("O0")

const int N = 300'010;
const int mod = 1e9 + 7;
ll a[N];
ll pow2[N];
int n;

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n) cin >> a[i];
    sort(a, a+n);
    pow2[0] = 1; Loop(i,1,N) pow2[i] = pow2[i-1]*2 % mod;
    ll ans = 0;
    ll sum = 0;
    for(int i = n-2; i >= 0; --i)
    {
        sum += a[i+1];
        sum += mod - a[n-2-i];
        sum %= mod;
        ans = (ans + sum*pow2[i]) % mod;
    }
    cout << ans << '\n';
}