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

const int N = 3010;

struct node{
    int cnt;
    int l, r;
};
node t[25*N]; int tc;

int make_node(int l, int r){t[tc] = {t[l].cnt+t[r].cnt,l,r}; return tc++;}
int make_node(int x){t[tc] = {x,0,0}; return tc++;}
int reset_(int l, int r){
    if(r-l==1) return make_node(0);
    return make_node(reset_(l,(l+r)/2), reset_((l+r)/2,r));
}
int reset(){tc = 1;return reset_(0,2*N);}
int add(int i, int p, int b=0, int e=2*N)
{
    if(e-b==1) return make_node(t[i].cnt+1);
    if(p < (b+e)/2) return make_node(add(t[i].l,p,b,(b+e)/2),t[i].r);
    else            return make_node(t[i].l,add(t[i].r,p,(b+e)/2,e));
}
int get(int i, int l, int r, int b=0, int e=2*N)
{
    if(l <= b && e <= r) return t[i].cnt;
    if(r <= b || e <= l) return 0;
    return get(t[i].l, l, r, b, (b+e)/2) + get(t[i].r, l, r, (b+e)/2, e);
}
char c[N][N];
int r[N][N];
int d[N][N];

int rt[N];
int n, m;

int main()
{
    FAST;
    cin >> n >> m;
    Loop(i,0,n) Loop(j,0,m) cin >> c[i][j];
    Loop(i,0,n) LoopR(j,0,m)
    {
        r[i][j] = c[i][j]=='z'? r[i][j+1]+1: 0;
        d[i][j] = c[i][j]=='z'? (i? d[i-1][j+1]+1: 1): 0;
    }
    ll ans = 0;
    Loop(j,0,m)
    {
        rt[0] = reset();
        Loop(i,0,n) rt[i+1] = add(rt[i], r[i][j]+i);
        Loop(i,0,n)
        {
            int len = min(r[i][j], d[i][j]);
            ans += get(rt[i+1],i+1,2*N)-get(rt[i+1-len],i+1,2*N);
        }
    }
    cout << ans << '\n';
}