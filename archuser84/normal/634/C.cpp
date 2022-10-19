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
//#pragma GCC optimize ("O0")
using namespace std;

const int N = 200'010;
int n, k, a, b, q;

struct seg
{
    ll t[N<<2] = {};
    ll mx;

    void add(int p, int v, int i = 0, int b = 0, int e = n)
    {
        if(b+1 == e)
        {
            t[i] = min(t[i]+v, mx);
            return;
        }
        if(p < (b+e)/2) add(p, v, 2*i+1, b, (b+e)/2);
        else            add(p, v, 2*i+2, (b+e)/2, e);
        t[i] = t[2*i+1] + t[2*i+2];
    }

    ll get(int l, int r, int i = 0, int b = 0, int e = n)
    {
        if(l <= b && e <= r) return t[i];
        if(e <= l || r <= b) return 0;
        return get(l, r, 2*i+1, b, (b+e)/2) + get(l, r, 2*i+2, (b+e)/2, e);
    }
}A, B;



int main()
{
    FAST;
    cin >> n >> k >> a >> b >> q;
    A.mx = a; B.mx = b;
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int d, a;
            cin >> d >> a; --d;
            A.add(d, a);
            B.add(d, a);
        }
        if(t == 2)
        {
            int d;
            cin >> d; --d;
            ll ans = 0;
            if(0   < d) ans += B.get(0, d);
            if(d+k < n) ans += A.get(d+k, n);
            cout << ans << '\n';
        }
    }
}