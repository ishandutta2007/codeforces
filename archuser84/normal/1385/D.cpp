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
using namespace std;

const int N = 200'010;
char a[N];

int dc(int l, int r, char c)
{
    if(l == r)
        return a[l] != c;
    int m = (l+r)/2;
    int x = dc(l, m, c+1);
    int y = dc(m+1, r, c+1);
    Loop(i,l,m+1)
        y += a[i] != c;
    Loop(i,m+1,r+1)
        x += a[i] != c;
    return min(x, y);
}

void solve()
{
    int n;
    cin >> n;
    cin >> a;
    cout << dc(0,n-1,'a') << '\n';
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