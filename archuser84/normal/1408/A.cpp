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

int a[N], b[N], c[N];
int n;

void solve()
{
    cin >> n;
    Loop(i,0,n)
        cin >> a[i];
    Loop(i,0,n)
        cin >> b[i];
    Loop(i,0,n)
        cin >> c[i];
    int last = a[0]+1;
    Loop(i,0,n-1)
    {
        if(a[i] != last)
            cout << a[i] << ' ',
            last = a[i];
        else
            cout << b[i] << ' ',
            last = b[i];
    }
    if(a[n-1] != last && a[n-1] != a[0])
        cout << a[n-1] << ' ';
    else if(b[n-1] != last && b[n-1] != a[0])
        cout << b[n-1] << ' ';
    else if(c[n-1] != last && c[n-1] != a[0])
        cout << c[n-1] << ' ';
    cout << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
        solve();
}