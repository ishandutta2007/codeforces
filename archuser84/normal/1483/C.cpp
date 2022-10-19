///
///    "I, Giorno Giovanna, have a dream."
///
///                                    -Giorno Giovanna

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize ("O0")

const int N = 300'010;

namespace fen
{
    ll t[N];

    void set(int i, ll v)
    {
        i++;
        while(i < N && t[i] < v)
        {
            t[i] = v;
            i += i & (-i);
        }
    }

    ll get(int r)
    {
        ll ans = LONG_LONG_MIN;
        while(r > 0)
        {
            ans = max(ans, t[r]);
            r -= r & (-r);
        }
        return ans;
    }
}

ll b[N], h[N];
ll dp[N];
int n;

int main()
{
    FAST;
    fill(fen::t, fen::t+N, LONG_LONG_MIN);
    cin >> n;
    Loop(i,0,n) cin >> h[i];
    Loop(i,0,n) cin >> b[i];
    dp[0] = 0; fen::set(n, 0);
    stack<int> s;
    Loop(i,0,n)
    {
        while(s.size() && h[s.top()] > h[i]) s.pop();
        int l = s.size()? s.top()+1: 0;
        //cerr << l << '\n';
        dp[i+1] = b[i] + fen::get(n+1-l);
        if(l) dp[i+1] = max(dp[i+1], dp[l]);
        fen::set(n-i-1, dp[i+1]);
        s.push(i);
    }
    cout << dp[n] << ' ';
}