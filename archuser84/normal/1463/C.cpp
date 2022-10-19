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
#define int int64_t
const int N = 200'010;
int t[N];
int des[N];
int cur[N];
int n;

void solve()
{
    cin >> n;
    Loop(i,0,n)
    {
        cin >> t[i] >> des[i];
    }
    cur[0] = 0;
    int dir = (des[0] > 0? 1: -1);
    int next = abs(des[0]) + t[0];
    int cdes = des[0];
    Loop(i,1,n)
    {
        if(t[i] >= next)
        {
            cur[i] = cdes;
            cdes = des[i];
            dir = (des[i] > cur[i]? 1: -1);
            next = abs(des[i]-cur[i]) + t[i];
            continue;
        }
        cur[i] = cur[i-1] + dir*(t[i] - t[i-1]);
    }
    int ans = 0;
    Loop(i,0,n-1)
    {
        ans += (cur[i] <= des[i] && des[i] <= cur[i+1]) ||
               (cur[i] >= des[i] && des[i] >= cur[i+1]);
    }
    ans += (cur[n-1] <= des[n-1] && des[n-1] <= cdes) ||
           (cur[n-1] >= des[n-1] && des[n-1] >= cdes);
    cout << ans << '\n';
}

int32_t main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}