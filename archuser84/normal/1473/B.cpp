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

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        string a, b;
        cin >> a >> b;
        string ans;
        Loop(i,0,a.size()*b.size()/__gcd(a.size(), b.size())) ans.push_back(a[i%a.size()]);
        Loop(i,0,a.size()*b.size()/__gcd(a.size(), b.size())) if(ans[i] != b[i%b.size()]) {cout << "-1\n"; goto end;}
        cout << ans << '\n';
        end:;
    }
}