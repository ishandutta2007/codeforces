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
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O0")
using namespace std;

const int N = 1e6 + 10;
int a[N];
int n;
int mx, mxp, mxc;
int mx2, mx2c;

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n)
    {
        cin >> a[i];
        if(a[i] > mx)
        {
            mx2 = mx;
            mx2c = mxc;
            mx = a[i];
            mxc = 0;
        }
        else if(a[i] > mx2)
        {
            mx2 = a[i];
            mx2c = 0;
        }
        if(a[i] == mx)
        {
            mxp = i;
            mxc++;
        }
        if(a[i] == mx2) mx2c++;
    }
    ll ans = 2*n - mx2c*(mxc==1) - 2*mxc;
    vector<pii> b;
    for(int j = mxp+n; j > mxp; --j)
    {
        int i = j%n;
        while(b.size() && b.back().F < a[i]) b.pop_back();
        if(b.size() && b.back().F == a[i])
            ans += b.back().S,
            b.back().S++;
        else
            b.emplace_back(a[i], 1);
    }
    cout << ans << '\n';
}