///
///    I have a dream and a piano
///

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;

int main()
{
    FAST;
    int n;
    cin >> n;
    int g = 0;
    int mx = 0;
    Loop(i,0,n)
    {
        int x;
        cin >> x;
        mx = max(mx, x);
        g = gcd(g, x);
    }
    cout << &(((mx/g^n)&1)*5)["Bob\n\0Alice\n"];
}