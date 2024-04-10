#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int N = 110;
int a[N];
bool cnt[N];

void solve()
{
    int n;
    cin >> n;
    Loop(i,0,2*n)
        cin >> a[i];
    memset(cnt,0,n+1);
    Loop(i,0,2*n)
    {
        if(!cnt[a[i]])
            cout << a[i] << ' ';
        cnt[a[i]]=true;
    }
    cout << '\n';
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