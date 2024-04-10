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

inline ll area(pll a, pll b, pll c)
{
    return a.F*(b.S-c.S)+b.F*(c.S-a.S)+c.F*(a.S-b.S);
}

set<pll> pts;
set<pll> d, u;

int main()
{
    FAST;
    int t;
    cin >> t;
    Loop(i,0,2)
    {
        int t, x, y;
        cin >> t >> x >> y;
        pts.insert({x,y});
        d.insert({x,y});
        u.insert({x,y});
    }
    t -= 2;
    while(t--)
    {
        ll t, x, y;
        cin >> t >> x >> y; pll p = {x,y};
        if(t == 1)
        {
            if(pts.count(p)) continue;
            if(p < *pts.begin())
            {
                while(u.size() > 1 && area(p, *u.begin(), *++u.begin()) > 0) u.erase(u.begin());
                while(d.size() > 1 && area(p, *d.begin(), *++d.begin()) < 0) d.erase(d.begin());
                d.insert(p);
                u.insert(p);
            }
            else if(p > *--pts.end())
            {
                while(u.size() > 1 && area(*----u.end(), *--u.end(), p) > 0) u.erase(--u.end());
                while(d.size() > 1 && area(*----d.end(), *--d.end(), p) < 0) d.erase(--d.end());
                d.insert(p);
                u.insert(p);
            }
            else if(area(*pts.begin(), p, *--pts.end()) < 0)
            {
                auto it1 = u.lower_bound(p);
                auto it2 = it1--;
                if(area(*it1, p, *it2) >= 0) continue;
                auto nit1 = it1; nit1--;
                auto nit2 = it2; nit2++;
                while( it1 != u.begin() && area(*nit1, *it1, p) > 0) {u.erase(it1); it1 = nit1--;}
                while(nit2 != u.  end() && area(p, *it2, *nit2) > 0) {u.erase(it2); it2 = nit2++;}
                u.insert(p);
            }
            else
            {
                auto it1 = d.lower_bound(p);
                auto it2 = it1--;
                if(area(*it1, p, *it2) <= 0) continue;
                auto nit1 = it1; nit1--;
                auto nit2 = it2; nit2++;
                while( it1 != d.begin() && area(*nit1, *it1, p) < 0) {d.erase(it1); it1 = nit1--;}
                while(nit2 != d.  end() && area(p, *it2, *nit2) < 0) {d.erase(it2); it2 = nit2++;}
                d.insert(p);
            }
            pts.insert(p);
        }
        else
        {
            if(pts.count(p)) {cout << "YES\n"; continue;}
            if(p < *pts.begin()) {cout << "NO\n"; continue;}
            if(p > *--pts.end()) {cout << "NO\n"; continue;}
            if(area(*pts.begin(), p, *--pts.end()) < 0)
            {
                auto it1 = u.lower_bound(p);
                auto it2 = it1--;
                cout << YN(area(*it1, p, *it2) >= 0) << '\n';
                continue;
            }
            else
            {
                auto it1 = d.lower_bound(p);
                auto it2 = it1--;
                cout << YN(area(*it1, p, *it2) <= 0) << '\n';
                continue;
            }
        }
    }
}