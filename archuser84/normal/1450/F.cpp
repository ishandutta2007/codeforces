#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
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

const int N = 100'010;
int cnt[N];
int cnt2[N];
int a[N];
int n;

void solve()
{
    cin >> n;
    memset(cnt, 0, 4*n);
    memset(cnt2, 0, 4*n);
    Loop(i,0,n) cin >> a[i], a[i]--, cnt2[a[i]]++;
    int tt2 = 0;
    int l = 0;
    ll ans = -1;
    Loop(i,1,n+1)
    {
        if(i == n || a[i] == a[i-1])
        {
            if(a[l] == a[i-1]) cnt[a[l]]++;
            ++ans;
            l = i;
        }
    }
    ll tmp = 0;
    int mx2 = 0, mx = 0, mxi = 0;
    Loop(i,0,n)
    {
        mx2 = max(mx2, cnt2[i]);
        tmp += cnt[i];
        if(cnt[i] > mx)
        {
            mx = cnt[i];
            mxi = i;
        }
    }
    Loop(i,0,n)
    {
        if(i == mxi) continue;
        tmp -= 2*cnt[i];
    }
    l = 0;
    Loop(i,1,n+1)
    {
        if(i == n || a[i] == a[i-1])
        {
            if(a[l] != a[i-1] && a[l] != mxi && a[i-1] != mxi) tt2++;
            l = i;
        }
    }
    tmp -= tt2;
    ans += max(tmp-1, 0LL);
    if(mx2 > (n+1)/2) cout << "-1\n";
    else         cout << ans << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}