#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 200'010;
int a[N];
int n;

void solve()
{
    int k;
    cin >> n >> k;
    Loop(i,0,n)
        cin >> a[i];
    sort(a, a+n);
    reverse(a,a+n);
    ll ans = 0;
    Loop(i,0,k+1)
        ans += a[i];
    if(k == 0)
        cout << ans- a[n-1] << '\n';
    else
        cout << ans << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {

        solve();
    }
}