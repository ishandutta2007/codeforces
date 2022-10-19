#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

const int N = 200'010;
vector<pll> A[4*N];
int n, m;

unsigned ll ans[N][4];

int main()
{
    FAST;
    cin >> n >> m;
    Loop(i,0,m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        A[u].push_back({v, w});
        A[v].push_back({u, w});
    }
    memset(ans, -1, sizeof ans);
    set<pair<ll, pii>> S; S.insert({0, {0, 0}}); ans[0][0] = 0;
    Loop(_,0,4*n)
    {
        int u = S.begin()->S.F;
        int c = S.begin()->S.S;
        S.erase(S.begin());
        for(auto e : A[u])
        {
            if(ans[u][c] + e.S < ans[e.F][c])
            {
                S.erase({ans[e.F][c], {e.F, c}});
                ans[e.F][c] = ans[u][c] + e.S;
                S.insert({ans[e.F][c], {e.F, c}});
            }
            if(!(c&1) && ans[u][c] < ans[e.F][c^1])
            {
                S.erase({ans[e.F][c^1], {e.F, c^1}});
                ans[e.F][c^1] = ans[u][c];
                S.insert({ans[e.F][c^1], {e.F, c^1}});
            }
            if(!(c&2) && ans[u][c] + 2*e.S < ans[e.F][c^2])
            {
                S.erase({ans[e.F][c^2], {e.F, c^2}});
                ans[e.F][c^2] = ans[u][c] + 2*e.S;
                S.insert({ans[e.F][c^2], {e.F, c^2}});
            }
        }
    }
    Loop(i,1,n)
    {
        cout << min(ans[i][0], ans[i][3]) << ' ';
    }
}