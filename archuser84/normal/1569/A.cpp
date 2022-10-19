///
///   Let the voice of love take you higher!
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

int foo()
{
    string s;
    int n;
    cin >> n >> s;
    if(n < 2) return cout << "-1 -1\n", 0;
    Loop(i,0,n-1) if(s[i] != s[i+1]) return cout << i+1 << ' ' << i+2 << '\n', 0;
    return cout << "-1 -1\n", 0;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        foo();
    }
}