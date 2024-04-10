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
int n;

class Seg
{
private:

    struct node
    {
        ll sum;
        int mx;
    }t[N << 2];

    inline int lef(int x){return 2*x+1;}
    inline int rig(int x){return 2*x+2;}

    void merge(int p)
    {
        int l = lef(p);
        int r = rig(p);
        t[p].sum = t[l].sum + t[r].sum;
        t[p].mx = max(t[l].mx, t[r].mx);
    }

    void Set(int i, int b, int e, int d, int v)
    {
        if(e-b == 1)
        {
            t[i].mx = t[i].sum = v;
            return;
        }
        int m = (b+e)/2;
        if(d < m)
            Set(lef(i), b, m, d, v);
        else
            Set(rig(i), m, e, d, v);
        merge(i);
    }

    void Mod(int i, int b, int e, int l, int r, int x)
    {
        if(e <= l || r <= b || t[i].mx < x)
            return;
        if(e-b == 1)
        {
            t[i].mx = t[i].sum = t[i].sum % x;
            return;
        }
        int m = (b+e)/2;
        Mod(lef(i), b, m, l, r, x);
        Mod(rig(i), m, e, l, r, x);
        merge(i);
    }

    ll Get(int i, int b, int e, int l, int r)
    {
        if(e <= l || r <= b)
            return 0;
        if(l <= b && e <= r)
            return t[i].sum;
        int m = (b+e)/2;
        return Get(lef(i), b, m, l, r) +
               Get(rig(i), m, e, l, r);
    }

public:
    void Set(int i, int x)       {Set(0, 0, n, i, x);}
    void Mod(int l, int r, int x){Mod(0, 0, n, l, r, x);}
    ll   Get(int l, int r){return Get(0, 0, n, l, r);}
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
        T.Set(i, x);
    }
    while(q--)
    {
        int t, a, b, c;
        cin >> t;
        switch(t)
        {
            case 1: cin >> a >> b; cout << T.Get(a-1, b) << '\n'; break;
            case 2: cin >> a >> b >> c; T.Mod(a-1, b, c); break;
            case 3: cin >> a >> b; T.Set(a-1, b); break;
        }
    }
}