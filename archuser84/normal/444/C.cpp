///
///    I have a dream and a piano
///

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;

const int N = 100'010;

namespace seg
{
    int clr[N<<2];
    ll sum[N<<2], lzy[N<<2];

    inline void ppg(int i, int b, int e)
    {
        if(lzy[i])
        {
            clr[2*i+1] = clr[2*i+2] = clr[i];
            lzy[2*i+1] += lzy[i];
            lzy[2*i+2] += lzy[i];
            sum[2*i+1] += lzy[i]*((e-b)/2);
            sum[2*i+2] += lzy[i]*((e-b+1)/2);
            lzy[i] = 0;
        }
    }

    void set(int l, int r, int x, int i=0, int b=0, int e=N)
    {
        if(r <= b || e <= l) return;
        if(l <= b && e <= r && clr[i] != -1){
            sum[i] += ll(e-b)*abs(x-clr[i]);
            lzy[i] += abs(x-clr[i]);
            clr[i] = x;
            return;
        }
        ppg(i,b,e);
        set(l,r,x,2*i+1,b,(b+e)/2);
        set(l,r,x,2*i+2,(b+e)/2,e);
        sum[i] = sum[2*i+1]+sum[2*i+2];
        clr[i] = clr[2*i+1]==clr[2*i+2]?clr[2*i+1]:-1;
    }

    ll get(int l, int r, int i=0, int b=0, int e=N)
    {
        if(l <= b && e <= r) return sum[i];
        if(r <= b || e <= l) return 0;
        ppg(i,b,e);
        return get(l,r,2*i+1,b,(b+e)/2)+get(l,r,2*i+2,(b+e)/2,e);
    }

    void init(int i=0, int b=0, int e=N)
    {
        clr[i] = e-b==1? b+1: -1;
        sum[i] = 0;
        lzy[i] = 0;
        if(e-b!=1) {
            init(2*i+1,b,(b+e)/2);
            init(2*i+2,(b+e)/2,e);
        }
    }
}

int main()
{
    seg::init();
    FAST;
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int t, l, r;
        cin >> t >> l >> r; --l;
        if(t==1)
        {
            int x;
            cin >> x;
            seg::set(l,r,x);
        } else cout << seg::get(l,r) << '\n';
    }
}