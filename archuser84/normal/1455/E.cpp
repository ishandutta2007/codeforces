#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

int p[4] = {0, 1, 2, 3};
ll x[4];
ll y[4];

ll get_ans(ll a)
{
    ll t[4], v[4];
    Loop(i,0,4)
        t[i]=x[p[i]],
        v[i]=y[p[i]];
    t[2] -= a;
    t[3] -= a;
    v[1] -= a;
    v[3] -= a;
    sort(t, t+4);
    sort(v, v+4);
    return t[3]+t[2]-t[0]-t[1] + v[3]+v[2]-v[0]-v[1];
}

ll bin()
{
    ll l = 0, r = 4e9 + 10;
    while(l < r)
    {
        ll m = (l+r)/2;
        if(get_ans(m) < get_ans(m+1))
            r = m;
        else
            l = m+1;
    }
    return get_ans(l);
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        ll ans = 1e15;
        Loop(i,0,4)
            cin >> x[i] >> y[i];
        Loop(i,0,24)
        {
            ans = min(ans, bin());
            next_permutation(p, p+4);
        }
        cout << ans << '\n';
    }
}