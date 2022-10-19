#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 200'010;
vector<pair<ll, int>> f;
void factor(ll n)
{
    f.clear();
    for(ll d = 2; d*d <= n; ++d)
    {
        if(n%d) continue;
        int cnt = 0;
        while(n%d == 0)
        {
            n /= d;
            cnt++;
        }
        f.push_back({d, cnt});
    }
    if(n > 1) f.push_back({n, 1});
}

ll ans[50];

void solve()
{
    ll n;
    cin >> n;
    Loop(i,0,50) ans[i] = 1;
    int k = 0;
    factor(n);
    for(auto x : f)
    {
        k = max(k, x.S);
    }
    for(auto x : f)
    {
        Loop(i,k-x.S,k)
            ans[i] *= x.F;
    }
    cout << k << '\n';
    Loop(i,0,k)
        cout << ans[i] << ' ';
    cout << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
        solve();
}