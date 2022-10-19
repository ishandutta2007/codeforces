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
int a[N], b[N];
int n;

pll solve(int l, int r)
{
    if(l+1 == r) return {min(0, b[l]), max(0, b[l])};
    int m = (l+r)/2;
    pll a1 = solve(l, m);
    pll a2 = solve(m, r);
    pll b1 = {}, b2 = {};
    ll sum = 0;
    LoopR(i,l,m)
    {
        sum += b[i];
        b1.F = min(b1.F, sum);
        b1.S = max(b1.S, sum);
    }
    sum = 0;
    Loop(i,m,r)
    {
        sum += b[i];
        b2.F = min(b2.F, sum);
        b2.S = max(b2.S, sum);
    }
    return {min({a1.F, a2.F, b1.F + b2.F}), max({a1.S, a2.S, b1.S + b2.S})};
}

int main()
{
    FAST;
    cin >> n;
    cin >> a[0];
    Loop(i,1,n)
    {
        cin >> a[i];
        b[i-1] = abs(a[i] - a[i-1]) * (i&1? -1: 1);
    }
    auto ans = solve(0, n-1);
    cout << max(-ans.F, ans.S) << '\n';
}