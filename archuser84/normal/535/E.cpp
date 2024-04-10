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

inline ll area(pll a, pll b, pll c) {
    return (c.S-b.S)*a.S*b.F*c.F
          +(a.S-c.S)*a.F*b.S*c.F
          +(b.S-a.S)*a.F*b.F*c.S;
          // /(...)
}

const int N = 200'010;
pair<pll, int> pts[N];
int n;

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n)
    {
        cin >> pts[i].F.F >> pts[i].F.S;
        pts[i].S = i;
    }
    sort(pts, pts+n, greater<pair<pll, int>>());
    vector<pair<pll, vector<int>>> d;
    d.emplace_back(pts[0].F, vector<int>(1,0));
    Loop(i,1,n-1)
    {
        if(d.back().F == pts[i].F) {d.back().S.push_back(i); continue;}
        if(area(pts[0].F, pts[i].F, pts[n-1].F) < 0) continue;
        if(area(d.back().F, pts[i].F, pts[n-1].F) < 0) continue;
        while(d.size() > 1 && area(d[d.size()-2].F, d[d.size()-1].F, pts[i].F) < 0)
            d.pop_back();
        d.emplace_back(pts[i].F, vector<int>(1,i));
    }
    d.emplace_back(pts[n-1].F, vector<int>(1,n-1));
    set<int> ans;
    for(int x : d[0].S) ans.insert(pts[x].S);
    Loop(i,1,d.size())
    {
        if(d[i].F.S <= d[i-1].F.S && d[i].F != d[i-1].F) break;
        for(int x : d[i].S) ans.insert(pts[x].S);
    }
    for(int x : ans) cout << x+1 << ' ';
}