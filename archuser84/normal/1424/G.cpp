#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

vector<pair<int, int>> event;

namespace ans
{
    int y=-1, p=-1;
    void up(int yy, int pp)
    {
        if(pp <= p)
            return;
        p = pp;
        y = yy;
    }
}

int main()
{
    FAST;
    int n;
    cin >> n;
    Loop(i,0,n)
    {
        int l, r;
        cin >> l >> r;
        event.push_back({l, 1});
        event.push_back({r, -1});
    }
    sort(all(event));
    int l = event[0].F;
    int p = 0;
    for(auto x : event)
    {
        if(x.F != l)
        {
            ans::up(l, p);
            l = x.F;
        }
        p += x.S;
    }
    ans::up(l, p);
    cout << ans::y << ' ' << ans::p << '\n';
}