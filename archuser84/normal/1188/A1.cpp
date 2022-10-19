///
///    "Yare Yare Daze"
///
///                                    -Jotaro Kujo

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
#pragma GCC optimize ("O0")

int main()
{
    FAST;
    int n;
    cin >> n;
    vector<int> d(n);
    Loop(i,1,n)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        d[a]++;
        d[b]++;
    }
    Loop(i,0,n) if(d[i] == 2) Kill("NO");
    cout << "YES\n";
}