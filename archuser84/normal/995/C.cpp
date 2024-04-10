#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
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

#define sqr(x) ((x)*(x))

ll dis(ll x, ll y)
{
    return sqr(x) + sqr(y);
}

bool my_cmp(pair<pll, int> a, pair<pll, int> b)
{
    return (a.F.S * b.F.F < b.F.S * a.F.F);
}

const int N = 100'010;
pair<pll, int> v[N];
int ans[N];

int main()
{
    FAST;
    int n;
    cin >> n;
    Loop(i,0,n) cin >> v[i].F.F >> v[i].F.S, v[i].S = i;
    sort(v, v+n, my_cmp);
    ll x=0, y=0;
    Loop(i,0,n)
    {
        if(dis(x+v[i].F.F, y+v[i].F.S) <
           dis(x-v[i].F.F, y-v[i].F.S)) ans[v[i].S] =  1;
        else                            ans[v[i].S] = -1;
        x += v[i].F.F*ans[v[i].S];
        y += v[i].F.S*ans[v[i].S];
    }
    Loop(i,0,n) cout << ans[i] << ' ';
}