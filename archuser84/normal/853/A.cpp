///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize("O0")

const int N = 300'010;
int n, k;
ll ans = 0, cnt = 0;
int t[N];
set<pll, greater<pll>> s;

int main()
{
    FAST;
    cin >> n >> k;
    Loop(i,1,n+k+1)
    {
        if(i <= n)
        {
            ll c;
            cin >> c;
            s.insert({c, i});
            cnt += c;
        }
        if(i > k)
        {
            t[s.begin()->S] = i;
            cnt -= s.begin()->F;
            s.erase(s.begin());
        }
        ans += cnt;
    }
    cout << ans << '\n';
    Loop(i,1,n+1) cout << t[i] << ' ';
}