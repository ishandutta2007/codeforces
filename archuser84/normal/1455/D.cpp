#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
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

const int N = 510;
int a[N];
int mn[N];
int n, x;

void solve()
{
    cin >> n >> x;
    Loop(i,0,n)
        cin >> a[i];
    mn[n-1] = N;
    LoopR(i,0,n-1)
        mn[i] = min(mn[i+1], a[i+1]);
    int cnt = 0, bad = 0;
    Loop(i,0,n)
    {
        if(mn[i] < a[i])
        {
            if(x >= a[i] || x > mn[i])
            {
                cout << "-1\n";
                return;
            }
            cnt += bad+1;
            bad = 0;
            x = a[i];
            continue;
        }
        if((i == 0 || a[i] > a[i-1]) && a[i] > x)
        {
            ++bad;
        }
    }
    cout << cnt << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}