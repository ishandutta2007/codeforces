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

const int N = 200'010;
vector<ll> v[2];
ll a[N], b[N];
ll n, m;

void solve()
{
    cin >> n >> m;
    Loop(i,0,n) cin >> a[i];
    Loop(i,0,n) cin >> b[i];
    v[0].clear(); v[1].clear();
    Loop(i,0,n) v[b[i]-1].push_back(a[i]);
    sort(all(v[0]), greater<int>());
    sort(all(v[1]), greater<int>());
    ll ans = LONG_LONG_MAX;
    ll sum = 0;
    int p1 = 0, p2 = 0;
    while(p1 < v[0].size() && sum < m) sum += v[0][p1++];
    while(p2 < v[1].size() && sum < m) sum += v[1][p2++];
    if(sum >= m) ans = min(ans, (ll)2*p2 + p1);
    while(p1)
    {
        sum -= v[0][--p1];
        while(p2 < v[1].size() && sum < m) sum += v[1][p2++];
        if(sum >= m) ans = min(ans, (ll)2*p2 + p1);
    }
    cout << (ans == LONG_LONG_MAX? -1: ans) << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}