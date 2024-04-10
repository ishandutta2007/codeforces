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

const int N = 2e5 + 10;
ll a, b, k;
ll cnt[2][N];

void solve()
{
    cin >> a >> b >> k;
    memset(cnt[0], 0, 8*a);
    memset(cnt[1], 0, 8*b);
    int zz;
    Loop(i,0,k) cin >> zz, cnt[0][zz-1]++;
    Loop(i,0,k) cin >> zz, cnt[1][zz-1]++;
    ll ans = k*(k-1)/2;
    Loop(i,0,a) ans -= cnt[0][i]*(cnt[0][i]-1)/2;
    Loop(i,0,b) ans -= cnt[1][i]*(cnt[1][i]-1)/2;
    cout << ans << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}