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
//#pragma GCC optimize ("O0")
using namespace std;

int main()
{
    FAST;
    ull x, s;
    cin >> s >> x;
    if(s < x) Kill(0);
    s -= x;
    if(s&1) Kill(0);
    s >>= 1;
    x = ~x;
    if((s|x) - x) Kill(0);
    ull ans = 1ll << __builtin_popcountll(~x);
    if(s == 0) ans -= 2;
    cout << ans << '\n';
}