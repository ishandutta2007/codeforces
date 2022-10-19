#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) {cout << x << '\n'; return 0;}
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int N = 1'000'010;
__int128 sum = 0;
int n;

inline __int128 C2(__int128 x)
{
    return x*(x-1)/2;
}

ll bin()
{
    ll l = 0, r = 1e12;
    while(l < r)
    {
        ll m = (l+r+1)/2;
        if(C2(m+1) - C2(m+2-n) < sum - m + n)
            l = m;
        else
            r = m - 1;
    }
    return l;
}

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n)
    {
        ll h;
        cin >> h;
        sum += h;
    }
    ll k = bin();
    ll r = sum - C2(k+1) + C2(k+2-n);
    for(ll i = k-n+2; i <= k; i++)
    {
        if(r == i-1)
            cout << r << ' ';
        cout << i << ' ';
    }
    if(r == k)
        cout << r << ' ';
}