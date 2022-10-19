#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int N = 200010;
pair<ll, ll> a[N];
ll par[N];
ll n, m;

int bin(int x)
{
    int l=0, r=n;
    while(l < r)
    {
        int m = (l+r)/2;
        if(a[m].F < x)
            r = m;
        else
            l = m+1;
    }
    return l;
}

void solve()
{
    cin >> m >> n;
    Loop(i,0,n)
        cin >> a[i].F >> a[i].S;
    sort(a,a+n);
    reverse(a,a+n);
    par[0] = 0; Loop(i,1,n+1)par[i]=par[i-1]+a[i-1].F;
    ll ans = par[min(m, n)];
    Loop(i,0,n)
    {
        int k = bin(a[i].S);
        if(k >= m)
            continue;
        ll sum = par[k] + a[i].F;
        if(i < k)
        {
            k--;
            sum -= a[i].F;
        }
        sum += (m-k-1) * a[i].S;
        ans = max(ans, sum);
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