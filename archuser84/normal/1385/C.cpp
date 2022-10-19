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
int a[N];

void solve()
{
    int n;
    cin >> n;
    Loop(i,0,n)
        cin >> a[i];
    reverse(a,a+n);
    bool flag = 0;
    int ans = n;
    Loop(i,1,n)
    {
        if(a[i-1] > a[i])
            flag = 1;
        if(a[i-1] < a[i] && flag)
        {
            ans = i;
            break;
        }
    }
    cout << n - ans << '\n';
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