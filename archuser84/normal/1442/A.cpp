#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
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
    Loop(i,0,n)
        cin >> a[i];
    int b = a[0], r = 0;
    Loop(i,1,n)
    {
        if(a[i] < r)
        {
            cout << "NO\n";
            return;
        }
        a[i] -= r;
        int k = max(a[i]-b, 0);
        r += k;
        a[i] -= k;
        b = min(b, a[i]);
    }
    cout << "YES\n";
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
        solve();
}