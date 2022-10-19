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

const int N = 500'010;
const int lM = 60;
const int mod = 1e9 + 7;
int n;
ll a[N];
int cnt[lM];

void solve()
{
    cin >> n;
    Loop(i,0,lM) cnt[i] = 0;
    Loop(i,0,n) {
        cin >> a[i];
        ll x = a[i];
        for(int k = 0; x; ++k)
        {
            cnt[k] += x&1;
            x >>= 1;
        }
    }
    ll ans = 0;
    Loop(i,0,n)
    {
        ll l = 0, r = 0;
        for(int k = 0; k < lM; ++k)
        {
            if(a[i]&1) l += ((1ll<<k)%mod) * cnt[k] % mod, r += ((1ll<<k)%mod) * n % mod;
            else       r += ((1ll<<k)%mod) * cnt[k] % mod;
            a[i] >>= 1;
        }
        l %= mod; r %= mod;
        ans += l*r % mod;
    }
    ans %= mod;
    cout << ans << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}