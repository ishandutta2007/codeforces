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

const int N = 2e5 + 10;
int mxd[N];
int lst[N];
int a[N];
int dp[N];
int dpf[N];
int n;

void solve()
{
    memset(mxd, 0, sizeof mxd);
    cin >> n;
    Loop(i,0,n) cin >> a[i];
    sort(a, a+n);
    dp[0] = 0; lst[0] = -1;
    Loop(i,0,n)
    {
        dpf[i+1] = 1;
        for(int d = 1; d*d <= a[i]; ++d)
        {
            if(a[i]%d) continue;
            dpf[i+1] = max(dpf[i+1], 1+dpf[lst[mxd[d]]+1]);
            dpf[i+1] = max(dpf[i+1], 1+dpf[lst[mxd[a[i]/d]]+1]);
        }
        dp[i+1] = max(dp[i], dpf[i+1]);
        lst[a[i]] = i;
        if(i && a[i-1] == a[i]) continue;
        for(int x = a[i]; x < N; x += a[i]) mxd[x] = a[i];
    }
    cout << n-dp[n] << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}