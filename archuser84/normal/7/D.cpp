#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll int64_t
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
    string s;
    cin >> s;
    ll h1 = 0, h2 = 0, h22 = 1;
    ll sum = 0;
    vector<int> dp(s.size()+1);
    dp[0] = 0;
    Loop(i,0,s.size())
    {
        h1 = h1*301 + s[i];
        h2 = h2 + s[i]*h22; h22 *= 301;
        if(h1 == h2) dp[i+1] = dp[(i+1)/2] + 1;
        else dp[i+1] = 0;
        sum += dp[i+1];
    }
    cout << sum << '\n';
}