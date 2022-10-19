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

typedef long double tw;
__attribute((naked, optimize("O2"))) tw fprem(tw, tw)
{
    asm(
        ".intel_syntax noprefix;"
        "fld TBYTE PTR [r8];"
        "fld TBYTE PTR [rdx];"
        "fprem;"
        "fxch;"
        "fstp TBYTE PTR [rcx];"
        "fstp TBYTE PTR [rcx];"
        "mov rax, rcx;"
        "ret;"
        ".att_syntax;"
    );
}

const tw mod = 1e9 + 7;
const int N = 1e6 + 10;
tw fct[N], ifct[N];
tw inv[N];

inline tw C(int n, int r)
{
    if(r < 0 || n < r) return 0;
    return fprem(fct[n]*fprem(ifct[r]*ifct[n-r], mod), mod);
}

inline tw S(int n, int r)
{
    return fprem((2*C(n-r, r) - C(n-1-r, r) + mod), mod);
}

int main()
{
    FAST;
    inv[1] = 1;
    fct[0] = fct[1] = 1;
    ifct[0] = ifct[1] = 1;
    Loop(i,2,N)
        inv[i] = mod-fprem(inv[int(fprem(mod, i))]*floor(mod/i), mod);
    Loop(i,2,N)
        fct[i] = fprem(fct[i-1]*i, mod);
    Loop(i,2,N)
        ifct[i] = fprem(ifct[i-1]*inv[i], mod);

    int n;
    cin >> n;
    tw ans = 0;
    for(int i = n&1; i <= n; i+=2)
        ans += fprem(2*fct[n-i]*S(n, i), mod);
    while(ans >= mod) ans = fprem(ans, mod);
    cout << ll(ans) << '\n';
}