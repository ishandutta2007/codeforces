#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll int64_t
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

const int N = 200'010;
ll a[N], b[N], c[N];
int n;

void solve()
{
    cin >> n;
    Loop(i,0,n) cin >> c[i];
    Loop(i,0,n) cin >> a[i];
    Loop(i,0,n) cin >> b[i];
    ll ans = 0;
    ll cur = c[n-1] - 1;
    LoopR(i,1,n)
    {
        cur += 2;
        ans = max(ans, cur + (max(a[i], b[i]) - min(a[i], b[i])));
        if(a[i] == b[i]) cur = 0;
        cur += c[i-1] - (max(a[i], b[i]) - min(a[i], b[i])) - 1;
        cur = max(cur, c[i-1] - 1);
    }
    cout << ans << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}