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

vector<pii> w;
vector<int> ans;

ll W;

void solve()
{
    int n;
    cin >> n >> W;
    w.clear();
    Loop(i,0,n)
    {
        int x;
        cin >> x;
        if(x > W)
            continue;
        w.push_back({x, i});
    }
    sort(all(w), greater<pii>());
    ll sum = 0;
    ans.clear();
    for(auto p : w)
    {
        sum += p.F;
        ans.push_back(p.S);
        if(sum >= (W+1)/2)
            break;
    }
    if(sum < (W+1)/2)
        cout << "-1\n";
    else
    {
        cout << ans.size() << '\n';
        for(int x : ans)
            cout << x+1 << ' ';
        cout << '\n';
    }
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
        solve();
}