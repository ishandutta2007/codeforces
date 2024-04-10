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

pii a[100'010];
double b[100'010];
pii a2[100'010];
ll n;

pair<ll, double> cnt(int l, int r)
{
    if(l+1 == r) return {};
    int m = (l+r)/2;
    ll ans1; double ans2;
    auto x = cnt(l, m), y = cnt(m, r);
    ans1 = x.F + y.F;
    ans2 = x.S + y.S;
    b[m] = n-a[m].S; Loop(i,m+1,r) b[i] = b[i-1] + n - a[i].S;
    int p1 = l, p2 = m;
    while(p1 < m)
    {
        if(p2 != r && a[p1].F > a[p2].F) ++p2;
        else
        {
            ans1 += p2-m;
            if(p2 > m) ans2 += (a[p1].S+1)*b[p2-1];
            ++p1;
        }
    }
    merge(a+l, a+m, a+m, a+r, a2);
    memcpy(a+l, a2, (r-l)*8);
    return {ans1, ans2};
}

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n) cin >> a[i].F, a[i].S = i;
    double ans = n; ans = (ans+2)*(ans-1)/24;
    //cerr << ans << '\n';
    auto [x, y] = cnt(0, n);
    //cerr << x << '\n';
    //cerr << y << '\n';
    ans += x;
    ans -= y/(n*(n+1)/2);
    cout << fixed << setprecision(15) << ans << '\n';
}