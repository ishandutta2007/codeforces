///
///    "Yare Yare Daze"
///
///                                    -Jotaro Kujo

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
#pragma GCC optimize ("Ofast")

map<int, ll> cnt1, cnt2;
ll n, p, k;

int main()
{
    FAST;
    cin >> n >> p >> k;
    Loop(i,0,n)
    {
        ll x;
        cin >> x;
        cnt1[x]++;
        ll tmp = k*x % p;
        x = x*x % p;
        x = x*x % p;
        x = x-tmp;
        if(x < 0) x += p;
        cnt2[x]++;
    }
    ll ans = 0;
    for(auto [x, y] : cnt2)
    {
        ans += y*(y-1)/2;
    }
    for(auto [x, y] : cnt1)
    {
        ll z = 4*x*x%p *x %p;
        if(z != k) ans -= y*(y-1)/2;
    }
    cout << ans << '\n';
}