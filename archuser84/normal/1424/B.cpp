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

const int N = 10'010;
vector<pair<int, pii>> E;
int n, m;

namespace dsu
{
    int par[2*N];
    int cnt[2*N];
    int get(int x)
    {
        if(par[x] == -1)
            return x;
        return par[x] = get(par[x]);
    }

    void unite(int a, int b)
    {
        a = get(a);
        b = get(b);
        if(a == b)
            return;
        par[b] = a;
        cnt[a] += cnt[b];
    }

    void init()
    {
        memset(par, -1, 8*N);
        memset(cnt, 0, 4*N);
        Loop(i,N,2*N)
            cnt[i] = 1;
    }
}

int main()
{
    FAST;
    dsu::init();
    cin >> n >> m;
    Loop(i,0,m)
    {
        E.push_back({0,{0,0}});
        cin >> E[i].S.F >> E[i].S.S >> E[i].F;
    }
    sort(all(E));
    int ans = 0;
    int p1 = 1;
    for(auto e : E)
    {
        if(p1 > n)
            break;
        ans = e.F;
        dsu::unite(e.S.F, e.S.S+N);
        while(dsu::cnt[dsu::get(p1)])
        {
            --dsu::cnt[dsu::get(p1)];
            ++p1;
        }
    }
    if(p1 <= n)
        Kill(-1);
    cout << ans << '\n';
}