#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define int long long
using namespace std;

const int N = 100'010;
ll a[N];
int n;

int32_t main()
{
    FAST;
    cin >> n;
    Loop(i,0,n)
        cin >> a[i];

    if(n==1)
    {
        cout << "1 1\n0\n1 1\n0\n1 1\n" << -a[0];
        return 0;
    }

    cout << 1 << ' ' << n-1 << '\n';
    Loop(i,0,n-1)
        {cout << a[i]*(n-1) << ' '; a[i] += a[i]*(n-1);}

    cout << '\n' << n << ' ' << n << '\n' << -a[n-1]; a[n-1] = 0;

    cout << '\n' << 1 << ' ' << n << '\n';
    Loop(i,0,n)
        cout << -a[i] << ' ';


}