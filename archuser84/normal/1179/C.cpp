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

const int N = 300'010;
const int MAX = 1'000'010;
int a[N]={}, b[N]={};

class seg_tree
{
private:
    struct node
    {
        int v = 0;
        int lazy = 0;
    };
    vector<node> t;

    inline int lef(int x){return 2*x+1;}
    inline int rig(int x){return 2*x+2;}

    inline int mid(int l, int r){return (l+r)/2;}

    inline void merge(int i)
    {
        t[i].v = max(t[lef(i)].v, t[rig(i)].v);
    }
    inline void relax(int i)
    {
        if(t[i].lazy == 0)
            return;
        t[lef(i)].lazy += t[i].lazy;
        t[rig(i)].lazy += t[i].lazy;
        t[lef(i)].v += t[i].lazy;
        t[rig(i)].v += t[i].lazy;
        t[i].lazy = 0;
    }

    inline void lazy_tag(int i, int x)
    {
        t[i].lazy += x;
        t[i].v += x;
    }

    void add(int i, int l, int r, int x, int b, int e)
    {
        if(r <= b || e <= l)
            return;
        if(l <= b && e <= r)
            return lazy_tag(i, x);
        int m = mid(b, e);
        relax(i);
        add(lef(i), l, r, x, b, m);
        add(rig(i), l, r, x, m, e);
        merge(i);
    }

    int get(int i, int b, int e)
    {
        if(e-b == 1)
            return b;
        int m = mid(b, e);
        relax(i);
        if(t[rig(i)].v > 0)
            return get(rig(i), m, e);
        return get(lef(i), b, m);
    }

public:
    seg_tree(){t.resize(MAX<<2);}
    void add(int r, int x){add(0, 0, r+1, x, 0, MAX);}
    int get(){return t[0].v <= 0? -1: get(0, 0, MAX);}
}S;

int n, m;

int main()
{
    FAST;
    cin >> n >> m;
    Loop(i,0,n)
    {
        cin >> a[i];
        S.add(a[i], 1);
    }
    Loop(i,0,m)
    {
        cin >> b[i];
        S.add(b[i], -1);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int t, i, x;
        cin >> t >> i >> x; i--;
        if(t == 1)
        {
            S.add(a[i], -1);
            a[i] = x;
            S.add(a[i], 1);
        }
        if(t == 2)
        {
            S.add(b[i], 1);
            b[i] = x;
            S.add(b[i], -1);
        }
        cout << S.get() << '\n';
    }
}