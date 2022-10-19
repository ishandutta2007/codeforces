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

const int N = 100'010;
int a[N];
int n;

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n)
        cin >> a[i];
    sort(a, a+n, greater<int>());
    cout << (n-1)/2 << '\n';
    Loop(i,0,n/2)
    {
        cout << a[i] << ' ';
        cout << a[n-1-i] << ' ';
    }
    if(n&1)
        cout << a[n/2] << ' ';
}