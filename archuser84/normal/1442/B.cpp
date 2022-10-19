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

const int mod = 998244353;
const int N = 200'010;
int a[N];
int l[N], r[N];
int p[N];
int b[N];
int q[N];
bool imp[N]={};
int n, k;

void solve()
{
    cin >> n >> k;
    Loop(i,0,n)
        cin >> a[i],
        p[a[i]] = i,
        l[i] = i-1,
        r[i] = i+1;
    Loop(i,0,k)
        cin >> b[i],
        q[i] = p[b[i]],
        imp[q[i]] = true;
    ll ans = 1;
    Loop(_,0,k)
    {
        int i = q[_];
        int p = l[i];
        int nx = r[i];
        imp[i] = 0;
        int cnt = 0;
        if(nx <  n) cnt += !imp[nx];
        if(p >=  0) cnt += !imp[p];
        ans = (ans*cnt)%mod;
        if(p >=  0) r[p] = nx;
        if(nx <  n) l[nx] = p;
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