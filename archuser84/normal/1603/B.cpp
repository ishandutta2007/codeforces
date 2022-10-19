///
///   You fell for it, fool!
///   Thunder Cross Split Attack!
///

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x, l, r) for(ll x = ll(r)-1; x >= ll(l); --x)
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



void solve()
{
    ll x, y;
    cin >> x >> y;
    if(x > y) cout << x+y << '\n';
    if(x == y) cout << x << '\n';
    if(x < y) cout << y-((y-x)%x)/2 << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}