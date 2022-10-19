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

const int N = 300'010;
string s;

void solve()
{
    cin >> s;
    int n = s.size();
    reverse(all(s));
    int cnt = 0;
    int ans = 0;
    Loop(i,0,n)
    {
        if(s[i] == 'B')
        {
            ++cnt;
            continue;
        }
        if(cnt)
        {
            --cnt;
            continue;
        }
        ++ans;
    }
    cout << ans + (cnt & 1) << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}