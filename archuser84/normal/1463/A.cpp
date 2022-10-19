#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

int solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x = a+b+c;
    if(x%9!=0) Kill("NO");
    int y = x/9;
    if(a < y || b < y || c < y) Kill("NO");
    Kill("YES");
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}