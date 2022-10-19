///
///    I have a dream and a piano
///

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

const int N = 200'010;
bool done[N];
int a[N];
pll b[N];
ll n, p;

void solve()
{
    cin >> n >> p;
    memset(done,0,n);
    Loop(i,0,n) cin >> a[i], b[i] = {a[i],i};
    sort(b,b+n);
    int cnt = 0;
    ll ans = 0;
    Loop(i,0,n)
    {
        if(b[i].F > p) break;
        int l = b[i].S, r = b[i].S;
        while(0<l   && !done[l-1] && !(a[l-1]%b[i].F)) --l;
        while(r<n-1 && !done[r] &&   !(a[r+1]%b[i].F)) ++r;
        ans += b[i].F*(r-l);
        cnt += r-l;
        Loop(i,l,r) done[i]=1;
    }
    ans += p*(n-1-cnt);
    cout << ans << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}