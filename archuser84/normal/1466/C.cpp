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
    string s;
    cin >> s;
    s = "____" + s;
    int a[4] = {};
    Loop(i,4,s.size())
    {
        int c;
        if(s[i] != s[i-1] && s[i] != s[i-2]) c = a[3];
        if(s[i] == s[i-1] && s[i] != s[i-2]) c = min(a[3] + 1, a[2] + 1);
        if(s[i] == s[i-1] && s[i] == s[i-2]) c = min(a[3] + 1, a[1] + 2);
        if(s[i] != s[i-1] && s[i] == s[i-2]) {
            c = a[3] + 1;
            if(s[i-1] != s[i-3]) c = min(c, a[1] + 1);
            if(s[i-1] == s[i-3]) c = min({c, a[1] + 2, a[0] + 2});
        }
        a[0] = a[1];
        a[1] = a[2];
        a[2] = a[3];
        a[3] = c;
    }
    cout << a[3] << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}