#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 200'010;
int cnt[N];
bool ex[N];
int a[N];
int n;

void solve()
{
    cin >> n;
    memset(cnt, 0, 4*n);
    memset(ex, 0, n);
    int excnt = 0;
    bool l = 0;
    cin >> a[0]; a[0]--;
    excnt += 1;
    ex[a[0]] = 1;
    Loop(i,1,n)
    {
        cin >> a[i]; a[i]--;
        excnt += !ex[a[i]];
        ex[a[i]] = 1;
        if(a[i] != a[i-1] && l)
        {
            cnt[a[i-1]]++;
        }
        if(a[i] != a[i-1])
        {
            l = 1;
        }
    }
    if(excnt == 1){cout << "0\n"; return;}
    int ans = INT_MAX;
    Loop(i,0,n)
    {
        if(ex[i])
            ans = min(ans, cnt[i]+1);
    }
    cout << ans << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
        solve();
}