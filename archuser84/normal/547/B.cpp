///
///    "I, Giorno Giovanna, have a dream."
///
///                                    -Giorno Giovanna

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

int rt(int* par, int u){return par[u] == u? u: par[u] = rt(par, par[u]);}
void unite(int* par, int* cnt, int a, int b)
{
    a = rt(par, a);
    b = rt(par, b);
    if(a == b) return;
    par[b] = a;
    cnt[a] += cnt[b];
}

int main()
{
    FAST;
    int n;
    cin >> n;
    pii* a = new pii[n];
    int* par = new int[n]; iota(par,par+n,0);
    int* cnt = new int[n]; fill(cnt,cnt+n,1);
    int* ans = new int[n]{};
    bool* gd = new bool[n]{};
    Loop(i,0,n) cin >> a[i].F, a[i].S = i;
    sort(a, a+n);
    LoopR(j,0,n)
    {
        int i = a[j].S;
        gd[i] = 1;
        if(0 < i   && gd[i-1]) unite(par, cnt, i, i-1);
        if(i < n-1 && gd[i+1]) unite(par, cnt, i, i+1);
        ans[cnt[rt(par, i)]-1] = max(ans[cnt[rt(par, i)]-1], a[j].F);
    }
    int z = 0;
    LoopR(i,0,n)
    {
        z = max(z, ans[i]);
        ans[i] = z;
    }
    Loop(i,0,n) cout << ans[i] << ' ';
}