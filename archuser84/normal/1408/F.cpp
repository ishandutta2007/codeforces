#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

vector<pii> ans;

void solve(int l, int r)
{
    if(l == r)
        return;
    int m = (l+r)/2;
    solve(l, m);
    solve(m+1, r);
    Loop(i,l,m+1)
        ans.push_back({i, i-l+m+1});
}

int main()
{
    FAST;
    int n;
    cin >> n;
    int k = 31 - __builtin_clz(n);
    solve(1, 1 << k);
    solve(n - (1 << k) + 1 ,n);
    cout << ans.size() << '\n';
    for(auto x : ans)
        cout << x.F << ' ' << x.S << '\n';
}