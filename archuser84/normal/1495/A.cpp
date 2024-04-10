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

int main()
{
    FAST;
    int t;
    cin >> t;
    cout << fixed << setprecision(12);
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> a, b;
        Loop(_,0,2*n)
        {
            ll x, y;
            cin >> x >> y;
            if(x == 0) a.push_back(abs(y));
            if(y == 0) b.push_back(abs(x));
        }
        sort(all(a));
        sort(all(b));
        double ans = 0;
        Loop(i,0,n)
        {
            ans += sqrt(a[i]*a[i] + b[i]*b[i]);
        }
        cout << ans << '\n';
    }
}