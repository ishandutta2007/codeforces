///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

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
//#pragma GCC optimize("O0")

const int N = 1'000'010;
int n, m, k;
ll ans = 0;
vector<pll> o[N], c[N];
vector<pll> cc[N]; int ccc=0; int ccl[N]={};
ll oo[N]; int ooo=0;

int main()
{
    FAST;
    cin >> n >> m >> k;
    Loop(i,0,m)
    {
        int d, f, t, c;
        cin >> d >> f >> t >> c;
        if(!t) ::o[d].push_back({f, c});
        else   ::c[d].push_back({t, c});
    }
    ans = 0;
    fill(oo, oo+N, 1e12);
    Loop(t,k,N)
    {
        for(auto [x, y] : c[t])
        {
            if(cc[x].empty()) ccc++;
            while(cc[x].size() && cc[x].back().F > y) cc[x].pop_back();
            cc[x].push_back({y, t});
        }
    }
    if(ccc != n) Kill(-1);
    ll fans = 1e15;
    Loop(i,1,n+1) ans += cc[i].front().F;
    Loop(t,0,N-k)
    {
        for(auto [x, y] : c[t+k])
        {
            while(cc[x][ccl[x]].S == t+k){
                ans -= cc[x][ccl[x]++].F;
                if(ccl[x] == cc[x].size()) Kill(ooo==n?fans:-1);
                ans += cc[x][ccl[x]].F;
            }
        }
        for(auto [x, y] : o[t])
        {
            if(oo[x] == 1e12) ++ooo, ans += 1e12;
            if(oo[x] > y) ans -= oo[x]-y, oo[x] = y;
        }
        if(ooo == n) fans = min(ans, fans);
    }
    //cout << fans << '\n';
}