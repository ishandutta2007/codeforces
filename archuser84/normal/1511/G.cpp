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

const int N  = 200'010;
const int lg = 20;
pair<bool, int> p[N][lg];
int n, m;

int main()
{
    FAST;
    cin >> n >> m;
    Loop(i,0,n)
    {
        int x;
        cin >> x;
        x--;
        p[x][0].F ^= 1;
    }
    Loop(k,1,lg)
    {
        Loop(l,0,m)
        {
            int m = l+(1<<(k-1));
            int r = l+(1<<k);
            if(r > ::m) break;
            p[l][k].F = p[l][k-1].F ^ p[m][k-1].F;
            p[l][k].S = p[l][k-1].S ^ p[m][k-1].S;
            if(p[m][k-1].F) p[l][k].S ^= m-l;
        }
    }
    int q;
    cin >> q;
    string fans;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        l--; int s = r-l;
        pii ans = {};
        for(int k = 0; s; ++k)
        {
            if(s&1) {
                if(ans.F) ans.S ^= (1<<k);
                ans.S ^= p[r-(1<<k)][k].S;
                ans.F ^= p[r-(1<<k)][k].F;
                r -= (1<<k);
            }
            s >>= 1;
        }
        fans.push_back('B'-(bool)ans.S);
    }
    cout << fans << '\n';
}