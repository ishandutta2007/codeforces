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
int a[N];
ll n, u, v;
int cnt = 0;

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> u >> v;
        Loop(i,0,n) cin >> a[i];
        ll ans = min(u+v,2*v);
        Loop(i,1,n)
        {
            if(a[i] != a[i-1]) ans = min(ans, min(u, v));
            if(abs(a[i] - a[i-1]) > 1) ans = 0;
        }
        cout << ans << '\n';
    }
}