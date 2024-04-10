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

int main()
{
    FAST;
    int n;
    int a[3];
    int b[3];
    cin >> n;
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    int mn = 0;
    mn += max(0, b[1] - (n - a[0]));
    mn += max(0, b[2] - (n - a[1]));
    mn += max(0, b[0] - (n - a[2]));
    int mx = 0;
    mx += min(a[0], b[1]);
    mx += min(a[1], b[2]);
    mx += min(a[2], b[0]);
    cout << mn << ' ' << mx << '\n';
}