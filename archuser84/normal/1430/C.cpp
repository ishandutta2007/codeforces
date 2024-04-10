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
    cin >> n;
    int ans = n;
    cout << 2 << '\n';
    LoopR(i,1,n)
    {
        cout << ans << ' ' << i << '\n';
        ans = (ans+i+1)/2;
    }
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