#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

int main()
{
    FAST;
    int t; t=1;
    //cin >> t;
    while(t--)
    {
        int n[3];
        ll s[3] = {};
        ll mn[3] = {1'000'000'010,1'000'000'010,1'000'000'010};
        Loop(i,0,3) cin >> n[i];
        Loop(i,0,3)
        {
            Loop(j,0,n[i])
            {
                ll x;
                cin >> x;
                s[i] += x;
                mn[i] = min(mn[i], x);
            }
        }
        sort(mn, mn+3);
        sort(s, s+3);
        ll ans = max(s[0] + s[1] + s[2] - 2*(mn[0] + mn[1]),
                     s[1] + s[2] - s[0]);
        cout << ans << '\n';
    }
}