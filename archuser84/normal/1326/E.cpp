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

const int N = 300'010;
int n;

struct seg
{
    pii t[N<<2] = {};
    pii t2[N<<2] = {};

    inline int lef(int x){return 2*x+1;}
    inline int rig(int x){return 2*x+2;}

    pii get(int l, int r, int i = 0, int b = 0, int e = n)
    {
        if(e <= l || r <= b)
            return {-1, -1};
        if(l <= b && e <= r)
            return t[i];
        int m = (b+e)/2;
        return max(get(l, r, lef(i), b, m),
                   get(l, r, rig(i), m, e));
    }

    void set(int v, int x, int i = 0, int b = 0, int e = n)
    {
        if(b+1 == e)
        {
            t[i] = {x, v};
            return;
        }
        int m = (b+e)/2;
        if(v < m) set(v, x, lef(i), b, m);
        else      set(v, x, rig(i), m, e);
        t[i] = max(t[lef(i)], t[rig(i)]);
    }

    inline void tag_ppg(int i)
    {
        t2[lef(i)].F += t2[i].S;
        t2[lef(i)].S += t2[i].S;
        t2[rig(i)].F += t2[i].S;
        t2[rig(i)].S += t2[i].S;
        t2[i].S = 0;
    }
    void add_tag(int l, int r, int x, int i = 0, int b = 0, int e = n)
    {
        if(e <= l || r <= b)
        {
            return;
        }
        if(l <= b && e <= r)
        {
            t2[i].F += x;
            t2[i].S += x;
            return;
        }
        int m = (b+e)/2;
        tag_ppg(i);
        add_tag(l, r, x, lef(i), b, m);
        add_tag(l, r, x, rig(i), m, e);
        t2[i].F = max(t2[lef(i)].F, t2[rig(i)].F);
    }
    int get_tag(int v, int i = 0, int b = 0, int e = n)
    {
        if(b+1 == e) return b;
        int m = (b+e)/2;
        tag_ppg(i);
        if(t2[lef(i)].F > 0 && v < m)
        {
            int x = get_tag(v, lef(i), b, m);
            if(x != -1)
                return x;
        }
        if(t2[rig(i)].F > 0)
        {
            return get_tag(v, rig(i), m, e);
        }
        return -1;
    }
}T;

int p[N];
int q[N];

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n)
        cin >> p[i], T.set(i, p[i]);
    Loop(i,0,n)
        cin >> q[i], q[i]--;
    Loop(i,0,n)
    {
        cout << T.get(0, n).F << ' ';
        T.add_tag(q[i], n, 1);
        int v = T.get_tag(q[i]);
        v = T.get(0, v+1).S;
        T.set(v, 0);
        T.add_tag(v, n, -1);
    }
}