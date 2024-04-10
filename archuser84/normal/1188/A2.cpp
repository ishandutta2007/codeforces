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

const int N = 1010;
vector<int> A[N];
int p[N];
ll w[N][N];
int n;

void dfs(int u)
{
    for(int v : A[u])
        if(v != p[u])
            p[v] = u, dfs(v);
}

void sub(int u, int v)
{
    while(p[u] != -1)
    {
        w[u][p[u]] -= v;
        w[p[u]][u] -= v;
        u = p[u];
    }
}

vector<tuple<int,int,int>> ans;
int rt;

pii solve(int u)
{
    int l = -1, r = -1;
    for(int v : A[u])
    {
        if(v == p[u]) continue;
        if(A[v].size() == 1)
        {
            if(l == -1) l = v; r = v;
            if(!w[u][v]) continue;
            ans.emplace_back(rt, v, -w[u][v]);
            sub(v, w[u][v]);
        }
        else
        {
            auto [ll, rr] = solve(v);
            if(l == -1) l = ll; r = rr;
            if(!w[u][v]) continue;
            ans.emplace_back(rt, ll, -w[u][v]/2);
            ans.emplace_back(rt, rr, -w[u][v]/2);
            ans.emplace_back(ll, rr,  w[u][v]/2);
            sub(v, w[u][v]);
        }
    }
    return {l, r};
}

int main()
{
    FAST;
    cin >> n;
    Loop(i,1,n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        ::w[u][v] = ::w[v][u] = w;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    Loop(i,0,n) if(A[i].size() == 2 && w[i][A[i][0]] != w[i][A[i][1]]) Kill("NO");
    Loop(i,0,n) if(A[i].size() == 1) {rt = i; break;}
    p[rt] = -1;
    dfs(rt);
    solve(rt);
    cout << "YES\n";
    cout << ans.size() << '\n';
    for(auto [u, v, w] : ans)
    {
        cout << u+1 << ' ' << v+1 << ' ' << -w << '\n';
    }
}