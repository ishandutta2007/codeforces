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

inline double sqr(double x) {return x*x;}

int main()
{
    FAST;
    double a, b, c;
    double x1, x2, y1, y2;
    cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
    double ans = abs(x2 - x1) + abs(y2 - y1);
    ans = min(ans,
              abs((-b*y1 - c)/a - x1)
            + abs((-b*y2 - c)/a - x2)
            + sqrt(sqr((-b*y1 - c)/a - (-b*y2 - c)/a)
                +  sqr(y1 - y2)));
    ans = min(ans,
              abs((-a*x1 - c)/b - y1)
            + abs((-a*x2 - c)/b - y2)
            + sqrt(sqr((-a*x1 - c)/b - (-a*x2 - c)/b)
                +  sqr(x1 - x2)));
    ans = min(ans,
              abs((-b*y1 - c)/a - x1)
            + abs((-a*x2 - c)/b - y2)
            + sqrt(sqr((-b*y1 - c)/a - x2)
                +  sqr(y1 - (-a*x2 - c)/b)));
    ans = min(ans,
              abs((-a*x1 - c)/b - y1)
            + abs((-b*y2 - c)/a - x2)
            + sqrt(sqr(y2 - (-a*x1 - c)/b)
                +  sqr(x1 - (-b*y2 - c)/a)));
    cout << fixed << setprecision(9) << ans;
}