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

const int mod = 1e9 + 7;

void make(int l, int r, vector<pii>& v, int b = 0, int e = 1<<30)
{
    if(l <= b && e <= r){v.emplace_back(b, e); return;}
    if(r <= b || e <= l){return;}
    make(l, r, v, b, (b+e)/2);
    make(l, r, v, (b+e)/2, e);
}

inline ll sum(ll x){return x*(x-1)/2;}

void solve()
{
    int x1, x2, y1, y2, k;
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    x1--; y1--;
    vector<pii> vx, vy;
    make(x1, x2, vx);
    make(y1, y2, vy);
    ll ans=0;
    for(pii xx : vx) for(pii yy : vy)
    {
        pii x, y;
        if(xx.S - xx.F > yy.S - yy.F) {x = yy; y = xx;}
        else                          {x = xx; y = yy;}
        ll kk = __builtin_ctz(y.S - y.F);
        ll l = y.F ^ ((x.F >> kk) << kk);
        ll r = min(l + (y.S - y.F), ll(k));
        if(r <= l) continue;
        ans = (ans + (x.S - x.F)*((sum(r+1)-sum(l+1))%mod)) % mod;
    }
    //ans = (ans + (x2-x1)*(y2-y1)) % mod;
    cout << ans << '\n';
}

int main()
{
    FAST;
    int q;
    cin >> q;
    while(q--) solve();
}