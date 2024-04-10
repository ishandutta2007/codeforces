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

const int N = 610;
ll w[N][N];
ll dis[N][N];
ll magik[N][N];
ll l[N][N];
bool good[N][N];
int n, m, q;

int main()
{
    FAST;
    Loop(a,0,N) Loop(b,0,N) w[a][b] = dis[a][b] = magik[a][b] = 1e15;
    Loop(a,0,N) Loop(b,0,N) l[a][b] = -1e15;
    cin >> n >> m;
    Loop(i,0,m)
    {
        ll a, b, c;
        cin >> a >> b >> c; a--; b--;
        w[a][b] = w[b][a] = c;
        dis[a][b] = dis[b][a] = c;
    }
    Loop(i,0,n) dis[i][i] = 0;
    Loop(k,0,n)
        Loop(a,0,n)
            Loop(b,0,n)
                dis[a][b] = min(dis[a][b], dis[a][k] + dis[k][b]);
    cin >> q;
    Loop(i,0,q)
    {
        ll a, b, c;
        cin >> a >> b >> c; a--; b--;
        l[a][b] = l[b][a] = c;
    }
    Loop(a,0,n)
        Loop(b,0,n)
            Loop(c,0,n)
                magik[a][b] = min(magik[a][b], dis[b][c] - l[a][c]);
    Loop(a,0,n)
        Loop(b,0,n)
            Loop(c,0,n)
                if(dis[a][b] + w[b][c] + magik[a][c] <= 0)
                    good[b][c] = 1;
    ll ans = 0;
    Loop(a,0,n)
        Loop(b,a+1,n)
            ans += good[a][b] || good[b][a];
    cout << ans << '\n';
}