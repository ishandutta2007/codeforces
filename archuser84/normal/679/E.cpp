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

ll constexpr MAX = 1'000'000'000'000'000'000LL;
vector<ll> pow42;
void calc_pow()
{
    pow42.push_back(1);
    while(pow42.back() < MAX)
        pow42.push_back(pow42.back()*42);
}

ll dis_near(ll x)
{
    for(ll y : pow42)
        if(x <= y)
            return y-x;
    return -1;
}

class Seg
{
private:

    struct node
    {
        ll lazy = 0;
        ll mn = 42;
        ll v = 0;
    }t[N << 2];

    inline int lef(int x){return 2*x+1;}
    inline int rig(int x){return 2*x+2;}

    void merge(int i)
    {
        t[i].mn = min(t[lef(i)].mn, t[rig(i)].mn);
    }

    void relax(int i)
    {
        int l = lef(i);
        int r = rig(i);
        if(t[i].v)
        {
            t[l].v = t[i].v;
            t[r].v = t[i].v;
            t[l].mn = t[i].mn;
            t[r].mn = t[i].mn;
            t[i].v = t[i].lazy = 0;
            return;
        }
        if(t[i].lazy == 0)
            return;
        t[l].lazy += t[i].lazy;
        t[r].lazy += t[i].lazy;
        t[l].mn -= t[i].lazy;
        t[r].mn -= t[i].lazy;
        if(t[l].v) t[l].v += t[i].lazy;
        if(t[r].v) t[r].v += t[i].lazy;
        t[i].lazy = 0;
    }

    void set(int i, int b, int e, int l, int r, int x)
    {
        if(r <= b || e <= l)
            return;
        if(l <= b && e <= r)
            {t[i].v = x; t[i].mn = dis_near(t[i].v); return;}
        relax(i);
        int m = (b+e)/2;
        set(lef(i), b, m, l, r, x);
        set(rig(i), m, e, l, r, x);
        merge(i);
    }

    bool add(int i, int b, int e, int l, int r, int x)
    {
        if(r <= b || e <= l)
            return 0;
        if(l <= b && e <= r && t[i].v)
            {t[i].v += x; t[i].mn = dis_near(t[i].v); return !t[i].mn;}
        if(l <= b && e <= r && t[i].mn > x)
            {t[i].lazy += x; t[i].mn -= x; return 0;}
        relax(i);
        int m = (b+e)/2;
        add(lef(i), b, m, l, r, x);
        add(rig(i), m, e, l, r, x);
        merge(i);
        return !t[i].mn;
    }

    ll get(int i, int b, int e, int k)
    {
        if(t[i].v)
            return t[i].v;
        relax(i);
        int m = (b+e)/2;
        if(k < m) return get(lef(i), b, m, k);
        else      return get(rig(i), m, e, k);
    }

public:
    void set(int l, int r, int x){       set(0, 0, n, l, r, x);}
    bool add(int l, int r, int x){return add(0, 0, n, l, r, x);}
    ll   get(int k)              {return get(0, 0, n, k);      }
}T;

void debug_print()
{
    cout << "debug: ";
    Loop(i,0,n)
        cout << T.get(i) << ' ';
    cout << '\n';
}

int main()
{
    FAST;
    calc_pow();
    int q;
    cin >> n >> q;
    Loop(i,0,n)
    {
        int x;
        cin >> x;
        T.set(i, i+1, x);
    }
    while(q--)
    {
        int t, a, b, c;
        cin >> t;
        switch(t)
        {
            case 1: cin >> a; cout << T.get(a-1) << '\n'; break;
            case 2: cin >> a >> b >> c; T.set(a-1, b, c); break;
            case 3: cin >> a >> b >> c; while(T.add(a-1, b, c)){} break;
        }
    }
}