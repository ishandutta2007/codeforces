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

int main()
{
    FAST;
    int a[110]={}, n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    int ans = 0;
    int emp = 0;
    Loop(i,0,110)
    {
        while(a[i] > emp){++ans; emp += i+1;}
        emp -= a[i];
        emp += ans;
    }
    cout << ans << '\n';
}