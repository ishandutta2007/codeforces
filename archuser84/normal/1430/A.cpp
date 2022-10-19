#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

void solve()
{
    int n;
    cin >> n;
    Loop(i,0,n)
        Loop(j,0,n)
            if(3*i + 5*j > n)
                continue;
            else if((n - (3*i + 5*j)) % 7 == 0)
                {cout << i << ' ' << j << ' ' << (n - (3*i + 5*j)) / 7 << '\n'; return;}
    cout << "-1\n";
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