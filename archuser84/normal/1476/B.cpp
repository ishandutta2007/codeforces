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

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        Loop(i,0,n) cin >> a[i];
        ll sum = a[0];
        ll ans = 0;
        Loop(i,1,n)
        {
            // 100*a[i]/sum <= k
            // 100*a[i] <= k*sum
            // 100*a[i] <= k*sum
            //cerr << (max(0ll, k*sum - 100*a[i]) + k-1)/k << ' ';
            ll tmp = (100*a[i] + k-1)/k; tmp = max(tmp, sum);
            ans += tmp - sum;
            sum = tmp;
            sum += a[i];
        }
        cout << ans << '\n';
    }
}