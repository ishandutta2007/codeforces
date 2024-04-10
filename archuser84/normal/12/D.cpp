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
#pragma GCC optimize ("O0")

const int N = 500'010;

int fen[N] = {};

void fset(int i, int v)
{
    ++i;
    while(i < N && fen[i] < v)
    {
        fen[i] = v;
        i += i & (-i);
    }
}
int fget(int r)
{
    int ans = 0;
    while(r > 0)
    {
        ans = max(ans, fen[r]);
        r -= r & (-r);
    }
    return ans;
}

struct obj
{
    int id;
    int a, b, c;
};

obj x[N];
int byb[N];
int n;

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n) cin >> x[i].a;
    Loop(i,0,n) cin >> x[i].b;
    Loop(i,0,n) cin >> x[i].c;
    Loop(i,0,n) x[i].id = i;
    sort(x, x+n, [](obj& x, obj& y){return x.b > y.b;});
    Loop(i,0,n)
        if(i && x[i].b == x[i-1].b) byb[x[i].id] = byb[x[i-1].id];
        else                        byb[x[i].id] = i;
    sort(x, x+n, [](obj& x, obj& y){return x.a > y.a;});
    int ans = 0;
    vector<int> tof;
    Loop(i,0,n+1)
    {
        if(i == n || (i > 0 && x[i].a != x[i-1].a))
        {
            for(int i : tof)
            {
                if(fget(byb[x[i].id]) > x[i].c) ++ans;
            }
            for(int i : tof)
            {
                fset(byb[x[i].id], x[i].c);
            }
            tof.clear();
        }
        tof.push_back(i);
    }
    cout << ans << '\n';
}