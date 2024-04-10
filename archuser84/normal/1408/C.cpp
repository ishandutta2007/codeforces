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

const int N = 200'010;
int a[N];
int n;

void solve()
{
    int l;
    cin >> n >> l;
    Loop(i,1,n+1)
        cin >> a[i];
    a[0] = 0; a[n+1] = l;
    int f = 1, s = n;
    double ans = 0;
    double t1 = a[f], t2 = l - a[s];
    int last = 0;
    while(f <= s)
    {
        if(t1 <= t2)
        {
            t2 -= t1;
            ans += t1;
            last = 0;
            ++f;
            t1 = double(a[f] - a[f-1]) / (f);
        }
        else
        {
            t1 -= t2;
            ans += t2;
            last = 1;
            --s;
            t2 = double(a[s+1] - a[s]) / (n-s+1);
        }
    }
    double dis;
    if(last == 0)
        dis = t2*(n-s+1);
    else
        dis = t1*(f);
    ans += dis/(f+n-s+1);
    cout << ans << '\n';
}

int main()
{
    FAST;
    cout << fixed << setprecision(9);
    int t;
    cin >> t;
    while(t--)
        solve();
}