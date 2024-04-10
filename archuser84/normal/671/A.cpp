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

//typedef pair<double, double> pdd;
pll a, b, t;
int n;

inline ll dis(pll a, pll b)
{
    return (a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S);
}

int main()
{
    FAST;
    cin >> a.F >> a.S >> b.F >> b.S >> t.F >> t.S;
    vector<pair<double, int>> v1, v2;
    cin >> n;
    double ans;
    Loop(i,0,n)
    {
        pll x;
        cin >> x.F >> x.S;
        ans += 2*sqrt(dis(x, t));
        v1.emplace_back(sqrt(dis(x, a))-sqrt(dis(x, t)), i);
        v2.emplace_back(sqrt(dis(x, b))-sqrt(dis(x, t)), i);
    }
    v1.emplace_back(0, n); v2.emplace_back(0, n);
    sort(all(v1));
    sort(all(v2));
    double ans1, ans2;
    {
        ans1 = 0;
        ans1 += v1[0].F;
        if(v2[0].S == v1[0].S) ans1 += v2[1].F;
        else                   ans1 += v2[0].F;
    }
    {
        ans2 = 0;
        ans2 += v2[0].F;
        if(v2[0].S == v1[0].S) ans2 += v1[1].F;
        else                   ans2 += v1[0].F;
    }
    cout << fixed << setprecision(7);
    cout << ans + min(ans1, ans2) << '\n';
}