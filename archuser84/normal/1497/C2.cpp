///
///    "I, Giorno Giovanna, have a dream."
///
///                                    -Giorno Giovanna

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize ("O0")

void solve()
{
    int n, k;
    cin >> n >> k;
    while(k > 3)
    {
        cout << "1 ";
        k--;
        n--;
    }
    if(n&1)      cout << n/2 << ' ' << n/2 << " 1\n";
    else if(n&2) cout << n/2-1 << ' ' << n/2-1 << " 2\n";
    else         cout << n/2 << ' ' << n/4 << ' ' << n/4 << "\n";
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}