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
    int k;
    cin >> n >> k;
    int m = 0;
    int last = -1;
    Loop(i,0,n)
    {
        int x;
        cin >> x;
        if(x != last)
            last = x,
            ++m;
    }
    if(k == 1)
        cout << (m == 1? 1: -1) << '\n';
    else
        cout << max((m-2)/(k-1), 0) + 1 << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
        solve();
}