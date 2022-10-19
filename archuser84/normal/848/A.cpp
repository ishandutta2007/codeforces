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
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize("O0")

int main()
{
    FAST;
    int n;
    cin >> n;
    if(n==0) Kill('a');
    char c = 'a';
    for(ll x = 1000; n; --x)
    {
        while(x*(x-1)/2 <= n)
        {
            n -= x*(x-1)/2;
            Loop(_,0,x) cout << c;
            ++c;
        }
    }
}