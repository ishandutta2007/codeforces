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
//#pragma GCC optimize ("Ofast")
using namespace std;

void solve()
{
    vector<int> ans;
    int n;
    string a, b;
    cin >> n >> a >> b;
    function<void (int, int)> slve = [&](int l, int r) -> void
    {
        if(r-l == 0) return;
        if(r-l == 1){if(a[0] != b[l]) ans.push_back(1); return;}
        slve(l+1, r-1);
        ans.push_back(r-l-1);
        if(a[r-l-2] != b[r-1]) ans.push_back(1);
        ans.push_back(r-l);
        if(a[r-l-1] == b[l]) ans.push_back(1);
    };
    slve(0, a.size());
    cout << ans.size() << ' ';
    for(auto x : ans) cout << x << ' ';
    cout << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}