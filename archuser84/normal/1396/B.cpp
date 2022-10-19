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

const int N = 100'010;
int a[N];
int n;

void solve()
{
    cin >> n;
    ll sum = 0, mx = -1;
    Loop(i,0,n)
    {
        ll x;
        cin >> x;
        sum += x;
        mx = max(x, mx);
    }
    if(mx > sum - mx)
        cout << "T\n";
    else if(sum & 1)
        cout << "T\n";
    else
        cout << "HL\n";
}

int main()
{
    FAST;
    int t;
    cin >> t;;
    while(t--)
        solve();
}