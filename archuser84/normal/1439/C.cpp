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

const int N = 200'010;
int n;

struct seg
{
    struct node
    {
        int mn=0, mx=0;
        ll sum = 0;
        int lazy = -1;
    };
    vector<node> t;

    seg(){t.resize(N<<2);}

    inline int lc(int x){return 2*x+1;}
    inline int rc(int x){return 2*x+2;}

    inline void ppg(int i, int b, int e)
    {
        if(t[i].lazy == -1) return;
        t[lc(i)].mn = t[lc(i)].mx = t[lc(i)].lazy = t[i].lazy;
        t[rc(i)].mn = t[rc(i)].mx = t[rc(i)].lazy = t[i].lazy;
        int m = (b+e)/2;
        t[lc(i)].sum = ((ll)(m-b)) * t[i].lazy;
        t[rc(i)].sum = ((ll)(e-m)) * t[i].lazy;
        t[i].lazy = -1;
    }

    inline void lzy_tag(int i, int x, int b, int e)
    {
        t[i].mn = t[i].mx = t[i].lazy = x;
        t[i].sum = ((ll)(e-b))*x;
    }

    void update(int l, int r, int x, int i = 0, int b = 0, int e = n)
    {
        if(r <= b || e <= l || x <= t[i].mn)
            return;
        if(l <= b && e <= r && x >= t[i].mx)
            return lzy_tag(i, x, b, e);
        int m = (b+e)/2;
        ppg(i, b, e);
        update(l, r, x, lc(i), b, m);
        update(l, r, x, rc(i), m, e);
        t[i].mn = min(t[lc(i)].mn, t[rc(i)].mn);
        t[i].mx = max(t[lc(i)].mx, t[rc(i)].mx);
        t[i].sum = t[lc(i)].sum + t[rc(i)].sum;
    }

    ll sum(int l, int r, int i = 0, int b = 0, int e = n)
    {
        if(r <= b || e <= l)
            return 0;
        if(l <= b && e <= r)
            return t[i].sum;
        int m = (b+e)/2;
        ppg(i, b, e);
        return sum(l, r, lc(i), b, m) +
               sum(l, r, rc(i), m, e);
    }

    int bin(ll x, int i = 0, int b = 0, int e = n)
    {
        if(t[i].mn > x) return -1;
        if(b+1 == e) return b;
        ppg(i, b, e);
        if(t[lc(i)].mn <= x) return bin(x, lc(i), b, (b+e)/2);
        return bin(x, rc(i), (b+e)/2, e);
    }

    int bin2(ll x, int i = 0, int b = 0, int e = n)
    {
        if(t[i].sum <= x) return e;
        if(b+1 == e) return b;
        ppg(i, b, e);
        if(t[lc(i)].sum <= x) return bin2(x-t[lc(i)].sum, rc(i), (b+e)/2, e);
        return bin2(x, lc(i), b, (b+e)/2);
    }
}T;

int main()
{
    FAST;
    int q;
    cin >> n >> q;
    Loop(i,0,n)
    {
        int x;
        cin >> x;
        T.update(0, i+1, x);
    }
    while(q--)
    {
        ll t, x, y;
        cin >> t >> x >> y;
        switch(t)
        {
            case 1: T.update(0, x, y); break;
            case 2:
                int ans = 0;
                y += T.sum(0, x-1);
                while(1)
                {
                    auto l = T.bin(y);
                    if(l == -1) break;
                    auto r = T.bin2(T.sum(0, l) + y);
                    ans += r-l;
                    y -= T.sum(l, r);
                    if(r==n) break;
                }
                cout << ans-x+1 << '\n';
        }
    }
}