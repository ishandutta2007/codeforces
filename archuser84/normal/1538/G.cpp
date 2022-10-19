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

ll x, y, a, b;

inline double solve(ll k)
{
    return k + min(double(x-k*a)/b, double(y-k*b)/a);
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> x >> y >> a >> b;
        ll l = 0, r = min(x/a, y/b);
        while(l < r)
        {
            ll m = (l+r)/2;
            auto m1 = solve(m);
            auto m2 = solve(m+1);
            if(m1 < m2) l = m+1;
            else        r = m;
        }
        cout << (ll)solve(l) << '\n';
    }
}