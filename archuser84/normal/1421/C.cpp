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

string s;
int n;

void solve()
{
    cin >> s;
    n = s.size();
    cout << "3\n";
    cout << "R " << n-1 << '\n';
    cout << "L " << n << '\n';
    cout << "L " << 2 << '\n';
}

int main()
{
    FAST;
    int t;
    //cin >> t;
    t=1;
    while(t--)
        solve();
}