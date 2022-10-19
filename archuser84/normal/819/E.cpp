#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll int64_t
#define ull uint64_t
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O0")
using namespace std;

int main()
{
    FAST;
    int n;
    cin >> n;
    vector<vector<int>> ans;
    for(int a = 1; a+4 <= n; a += 2)
    {
        ans.push_back({a, a+1, a+2});
        ans.push_back({a, a+1, a+2});
        for(int b = a+3; b < n; b++)
            ans.push_back({a, b, a+1, b+1});
        ans.push_back({a, n, a+1, a+3});
    }
    if(n&1) ans.push_back({n-2, n-1, n}), ans.push_back({n-2, n-1, n});
    else{
        ans.push_back({n-0, n-1, n-2});
        ans.push_back({n-0, n-1, n-3});
        ans.push_back({n-0, n-2, n-3});
        ans.push_back({n-1, n-2, n-3});
    }
    cout << ans.size() << '\n';
    for(auto& x : ans)
    {
        cout << x.size() << ' ';
        for(auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
}