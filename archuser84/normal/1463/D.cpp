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
int* a = new int[N];
int n;

int find_mn()
{
    int cntmn = 0;
    int cntb = 0;
    LoopR(i,0,n)
    {
        cntb += a[i+1]-a[i]-1;
        if(cntmn + 1 <= cntb) cntmn++;
    }
    return cntmn;
}
int find_mx()
{
    int cntmx = 0;
    int cntb = 0;
    Loop(i,0,n)
    {
        cntb += a[i]-a[i-1]-1;
        if(cntmx + 1 <= cntb) cntmx++;
    }
    return cntmx;
}

void solve()
{
    cin >> n;
    Loop(i,0,n) cin >> a[i];
    a[n] = 2*n+1; a[-1] = 0;
    int mn = find_mn();
    int mx = find_mx();
    cout << mn-(n-mx)+1 << '\n';
}

int main()
{
    FAST;
    a++;
    int t;
    cin >> t;
    while(t--) solve();
}