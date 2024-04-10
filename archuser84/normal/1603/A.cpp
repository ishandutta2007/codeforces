///
///   You fell for it, fool!
///   Thunder Cross Split Attack!
///

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x, l, r) for(ll x = ll(r)-1; x >= ll(l); --x)
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

const int N = 100'010;
int a[N];
int n;

void solve()
{
    cin >> n;
    Loop(i,0,n) cin >> a[i];
    while(n)
    {
        bool good = 0;
        LoopR(i,0,n)
        {
            if(a[i]%(i+2))
            {
                good = 1;
                Loop(j,i,n-1)
                    a[j] = a[j+1];
                break;
            }
        }
        if(!good)
        {
            cout << "NO\n";
            return;
        }
        --n;
    }
    cout << "YES\n";
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}