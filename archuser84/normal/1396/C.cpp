#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int N = 1'000'010;
ll dp[N], dpg[N], dpb[N];
ll a[N];
ll r1, r2, r3, d;
int n;

int main()
{
    FAST;
    cin >> n >> r1 >> r2 >> r3 >> d;
    r1 = min({r1, r2, r3});
    ll r15 = min(2*r1, r3);
    Loop(i,0,n)
        cin >> a[i];
    dp[n-1] = dpb[n-1] = r1*a[n-1] + r3;
    dpg[n-1] = min(r1*a[n-1] + r15, r2 + r1);
    LoopR(i,0,n-1)
    {
        ll las, pis;

//dp[i]:
pis = min({r1*a[i] + r3 + d + dp[i+1],
           r1*a[i] + r15 + 2*d + dpb[i+1],
           r1*a[i] + r15 + 3*d + dpg[i+1]});
las = min( r2 + r1 + 2*d + dpb[i+1],
           r2 + r1 + 3*d + dpg[i+1] );
dp[i] = min(pis, las);

//dpb[i]:
pis = r1*a[i] + r15 + 2*d + dpb[i+1];
las = r2 + r1 + 2*d + dpb[i+1];
dpb[i] = min(pis, las);

//dpg[i]:
pis = r1*a[i] + r15 + d + dp[i+1];
las = r2 + r1 + d + dp[i+1];
dpg[i] = min(pis, las);

//dpb[n-2]:
if(i == n-2)
{
pis = min( r1*a[i] + r15 + 2*d + dpb[i+1],
           r1*a[i] + r15 + 4*d + dpg[i+1] );
las = min( r2 + r1 + 2*d + dpb[i+1],
           r2 + r1 + 4*d + dpg[i+1] );
dpb[i] = min(pis, las);
}

    }
    cout << dp[0] << '\n';
}