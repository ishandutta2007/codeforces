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

void solve()
{
    int n, x;
    cin >> n >> x;
    int sum=0; bool alle = 1; bool onee = 0;
    Loop(i,0,n)
    {
        int z;
        cin >> z;
        sum += z;
        if(z != x)
            alle = 0;
        if(z == x)
            onee = 1;
    }
    if(alle)
        cout << "0\n";
    else if(sum == x*n || onee)
        cout << "1\n";
    else
        cout << "2\n";
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
        solve();
}