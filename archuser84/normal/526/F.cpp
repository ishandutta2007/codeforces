///
///    "Yare Yare Daze"
///
///                                    -Jotaro Kujo

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize ("O0")

const int N = 300'010;

namespace seg
{
    int mn[N<<2];
    int cnt[N<<2];
    int lzy[N<<2];

    void init(int i = 0, int b = 0, int e = N)
    {
        lzy[i] = 0; mn[i] = 1; cnt[i] = e-b;
        if(b+1 == e) return;
        init(2*i+1, b, (b+e)/2);
        init(2*i+2, (b+e)/2, e);
    }

    inline void ppg(int i)
    {
        mn [2*i+1] += lzy[i];
        lzy[2*i+1] += lzy[i];
        mn [2*i+2] += lzy[i];
        lzy[2*i+2] += lzy[i];
        lzy[i] = 0;
    }

    void add(int l, int r, int v, int i=0, int b=0, int e=N)
    {
        if(l <= b && e <= r){lzy[i] += v; mn[i] += v; return;}
        if(r <= b || e <= l) return;
        ppg(i);
        add(l, r, v, 2*i+1, b, (b+e)/2);
        add(l, r, v, 2*i+2, (b+e)/2, e);
        if(mn[2*i+1] >  mn[2*i+2]) {mn[i] = mn[2*i+2]; cnt[i] = cnt[2*i+2];}
        if(mn[2*i+1] == mn[2*i+2]) {mn[i] = mn[2*i+1]; cnt[i] = cnt[2*i+1]+cnt[2*i+2];}
        if(mn[2*i+1] <  mn[2*i+2]) {mn[i] = mn[2*i+1]; cnt[i] = cnt[2*i+1];}
    }

    inline int get(){return mn[0] > 0? 0: cnt[0];}
}

int a[N];
int n;

int main()
{
    FAST;
    seg::init();
    cin >> n;
    Loop(i,0,n)
    {
        int a, b;
        cin >> a >> b;
        ::a[a-1] = b-1;
    }
    ll ans = 0;
    stack<int> l, g; l.push(-1); g.push(-1);
    Loop(i,0,n)
    {
        while(~l.top() && a[l.top()] > a[i])
        {
            int r = l.top();
            l.pop();
            seg::add(l.top()+1, r+1, a[r]-a[i]);
        }
        while(~g.top() && a[g.top()] < a[i])
        {
            int r = g.top();
            g.pop();
            seg::add(g.top()+1, r+1, a[i]-a[r]);
        }
        seg::add(0, i+1, -1);
        ans += seg::get();
        l.push(i);
        g.push(i);
    }
    cout << ans << '\n';
}