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
//#pragma GCC optimize ("Ofast")
using namespace std;

const int mod = 1e9 + 7;

void matmul(ll A[2][2], ll B[2][2], ll res[2][2])
{
    ll ans[2][2];
    ans[0][0] = (A[0][0]*B[0][0] + A[0][1]*B[1][0])%mod;
    ans[0][1] = (A[0][0]*B[0][1] + A[0][1]*B[1][1])%mod;
    ans[1][0] = (A[1][0]*B[0][0] + A[1][1]*B[1][0])%mod;
    ans[1][1] = (A[1][0]*B[0][1] + A[1][1]*B[1][1])%mod;
    res[0][0] = ans[0][0]; res[0][1] = ans[0][1]; res[1][0] = ans[1][0]; res[1][1] = ans[1][1];
}

void matmul2(ll A[2][2], ll B[2], ll res[2])
{
    ll ans[2];
    ans[0] = (A[0][0]*B[0] + A[0][1]*B[1])%mod;
    ans[1] = (A[1][0]*B[0] + A[1][1]*B[1])%mod;
    res[0] = ans[0]; res[1] = ans[1];
}

void matPow(ll e, ll res[2][2])
{
    res[0][0] = 1; res[0][1] = 0; res[1][0] = 0; res[1][1] = 1;
    ll x[2][2] = {{0, 1}, {1, 1}};
    for(; e; e >>= 1)
    {
        if(e&1) matmul(res, x, res);
        matmul(x,x,x);
    }
}

const int N = 100'010;
int n;

struct seg
{
    ll t[N<<2][2];
    ll lazy[N<<2][2][2] = {};

    inline int lc(int x){return 2*x+1;}
    inline int rc(int x){return 2*x+2;}

    void ppg(int i)
    {
        matmul(lazy[i],lazy[lc(i)],lazy[lc(i)]);
        matmul(lazy[i],lazy[rc(i)],lazy[rc(i)]);
        matmul2(lazy[i],t[lc(i)],t[lc(i)]);
        matmul2(lazy[i],t[rc(i)],t[rc(i)]);
        lazy[i][0][0] = 1; lazy[i][0][1] = 0; lazy[i][1][0] = 0; lazy[i][1][1] = 1;
    }

    void add(int i, ll v[2][2], int l, int r, int b, int e)
    {
        if(l <= b && e <= r)
        {
            matmul(v,lazy[i],lazy[i]);
            matmul2(v,t[i],t[i]);
            return;
        }
        if(e <= l || r <= b) return;
        ppg(i);
        int m = (b+e)/2;
        add(lc(i), v, l, r, b, m);
        add(rc(i), v, l, r, m, e);
        t[i][0] = (t[lc(i)][0] + t[rc(i)][0])%mod;
        t[i][1] = (t[lc(i)][1] + t[rc(i)][1])%mod;
    }

    ll get(int i, int l, int r, int b, int e)
    {
        if(l <= b && e <= r) return t[i][0];
        if(e <= l || r <= b) return 0;
        ppg(i);
        int m = (b+e)/2;
        return (get(lc(i), l, r, b, m) +
                get(rc(i), l, r, m, e)) % mod;
    }

    void init(int i = 0, int b = 0, int e = n)
    {
        lazy[i][0][0] = 1; lazy[i][0][1] = 0; lazy[i][1][0] = 0; lazy[i][1][1] = 1;
        if(b+1 == e)
        {
            t[i][0] = 0; t[i][1] = 1;
            return;
        }
        int m = (b+e)/2;
        init(lc(i), b, m);
        init(rc(i), m, e);
        t[i][0] = 0;
        t[i][1] = (t[lc(i)][1] + t[rc(i)][1])%mod;
    }
}s;


int main()
{
    ll tmp[2][2];
    FAST;
    int q;
    cin >> n >> q;
    s.init();
    Loop(i,0,n)
    {
        int x;
        cin >> x; matPow(x, tmp);
        s.add(0,tmp,i,i+1,0,n);
    }
    while(q--)
    {
        int t;
        int l, r, x;
        cin >> t;
        switch(t)
        {
            case 1: cin >> l >> r >> x; matPow(x, tmp); s.add(0,tmp,l-1,r,0,n); break;
            case 2: cin >> l >> r; cout << s.get(0,l-1,r,0,n) << '\n'; break;
        }
    }
}