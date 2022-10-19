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

const int N = 100'010;
int a[6];
int b[N];
int n;

int check(int mn)
{
    int mx = mn;
    Loop(i,0,n)
    {
        Loop(j,0,7)
        {
            if(j == 6)
                return INT_MAX;
            if(b[i] - a[j] >= mn)
            {
                mx = max(mx, b[i] - a[j]);
                break;
            }
        }
    }
    return mx - mn;
}

priority_queue<pii> Q;

int main()
{
    FAST;
    int mx = INT_MIN, mn = INT_MAX;
    Loop(i,0,6)
        cin >> a[i];
    sort(a, a+6);
    LoopR(i,1,6) a[i] -= a[i-1];
    cin >> n;
    Loop(i,0,n)
        cin >> b[i],
        b[i] -= a[0],
        mn = min(mn, b[i]),
        mx = max(mx, b[i]),
        Q.push({b[i], 1});
    int ans = mx - mn;
    while(true)
    {
        auto x = Q.top(); Q.pop();
        if(x.S == 6)
            break;
        x.F -= a[x.S];
        x.S++;
        mn = min(mn, x.F);
        Q.push(x);
        ans = min(ans, Q.top().F - mn);
    }
    cout << ans << '\n';
}