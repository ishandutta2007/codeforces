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
    ll sum = 0;
    cin >> n;
    Loop(i,0,n)
        cin >> a[i],
        sum += a[i];
    if(sum == 0)
    {
        cout << "NO\n";
        return;
    }
    sort(a, a+n);
    if(sum > 0)
        reverse(a, a+n);
    cout << "YES\n";
    Loop(i,0,n)
        cout << a[i] << ' ';
    cout << '\n';
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