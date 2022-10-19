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

int n, k;
string s;

bool solve()
{
    cin >> n >> k;
    cin >> s;
    if(k&1)
        return 0;
    Loop(i,0,n)
    {
        if(s[i] == '?')
            continue;
        if(s[i%k] == '?')
            s[i%k] = s[i];
        if(s[i%k] != s[i])
            return 0;
    }
    int cnt1=0, cnt2=0;
    Loop(i,0,k)
    {
        cnt1 += s[i] == '1';
        cnt2 += s[i] == '1' || s[i] == '?';
    }
    return cnt1 <= k/2 && k/2 <= cnt2;
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
        cout << YN(solve()) << '\n';
}