///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

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

inline bool Bit(ull x, int b){return (x>>b)&1;}

bool ok(ull a, ull b)
{
    int mn=0,  mx=0;
    Loop(_,0,64)
    {
        if((b&1) && !(a&1)) mn = 0, mx--;
        if(!(b&1) && (a&1)) mn=1, mx++;
        if(mx < 0) return 0;
        a>>=1; b>>=1;
    }
    return !mn;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        ull a, b;
        cin >> a >> b;
        cout << YN(ok(a, b)) << '\n';
    }
}