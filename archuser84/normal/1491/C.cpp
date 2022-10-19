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
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O0")
using namespace std;

const int N = 200'010;
ll a[N], b[N];
ll n;

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        Loop(i,0,n) cin >> a[i];
        fill(b, b+n, 0);
        ll ans = 0;
        Loop(i,0,n)
        {
            Loop(j,i+2,min(n, i+a[i]+1)) b[j]++;
            b[i+1] += max(0ll, b[i] - a[i] + 1);
            a[i] = max(a[i]-b[i], 1ll);
            ans += a[i]-1;
        }
        cout << ans << '\n';
    }
}