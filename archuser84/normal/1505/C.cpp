///
///    "Your next line is..."
///
///                                    -Joseph Joestar

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

int main()
{
    char s[1000];
    cin >> s;
    int n = strlen(s);
    Loop(i,0,n) s[i] -= 'A';
    Loop(i,2,n) if(s[i] != (s[i-1] + s[i-2]) % 26) Kill("NO");
    cout << "YES";
}