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

const int N = 300'010;
int k[N];
ll c[N];
int n, m;

void solve()
{
    cin >> n >> m;
    ll sum = 0;
    Loop(i,0,n) cin >> k[i], k[i]--;
    Loop(i,0,m) cin >> c[i];
    sort(k, k+n);
    Loop(i,0,n) sum += c[k[i]];
    ll ans = sum;
    int dis = 1e9;
    Loop(i,0,min(n, m))
    {
        sum -= c[k[n-i-1]];
        sum += c[i];
        dis -= 1;
        dis = min(dis, k[n-i-1]);
        if(dis < 0) break;
        ans = min(ans, sum);
    }
    cout << ans << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}