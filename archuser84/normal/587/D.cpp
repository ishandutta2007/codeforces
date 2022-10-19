///
///    "Your next line is..."
///
///                                    -Joseph Joestar

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

const int N = 50'010;
vector<int> sat[N*10];
vector<int> satt[N*10];
bool vis[N*10];
int scc[N*10];
int ans[N*10];
vector<int> added;
vector<int> order;
int n, m;

void dfs1(int u)
{
    vis[u] = 1;
    for(int v : sat[u])
        if(!vis[v])
            dfs1(v);
    order.push_back(u);
}

void dfs2(int u, int p)
{
    scc[u] = p;
    vis[u] = 1;
    for(int v : satt[u])
        if(!vis[v])
            dfs2(v, p);
}

bool solve_sat()
{
    order.clear();

    memset(vis,  0, N*10);
    Loop(i,0,N*10)
        if(!vis[i])
            dfs1(i);

    reverse(all(order));
    memset(vis, 0, N*10);
    int cnt = 0;
    for(int i : order)
        if(!vis[i])
            dfs2(i, cnt++);

    Loop(i,0,N*5)
        if(scc[2*i] == scc[2*i+1])
            return false;

    memset(ans, -1, N*10*4);
    for(int i : order)
    {
        if(ans[scc[i]] != -1) continue;
        else ans[scc[i]] = 0, ans[scc[i^1]] = 1;
    }

    return true;
}

inline bool get_ans(int i){return ans[scc[2*i]];}

void add_clause(int a, int b, bool n1, bool n2)
{
    //cerr << n1 << a << ' ' << n2 << b << '\n';
    sat [2*a + !(n1)].push_back(2*b +  (n2));
    sat [2*b + !(n2)].push_back(2*a +  (n1));
    satt[2*a +  (n1)].push_back(2*b + !(n2));
    satt[2*b +  (n2)].push_back(2*a + !(n1));
    added.push_back(2*a + !(n1));
    added.push_back(2*b + !(n2));
}

void remove_clause(int cnt)
{
    while(cnt--)
    {
        sat [added.back()  ].pop_back();
        satt[added.back()^1].pop_back();
        added.pop_back();
        sat [added.back()  ].pop_back();
        satt[added.back()^1].pop_back();
        added.pop_back();
    }
}

map<int, vector<int>> Ac[N];
vector<int> A[N];
int t[N];

bool prepare()
{
    Loop(i,0,n)
    {
        for(auto& [c, v] : Ac[i])
        {
            if(v.size() > 2) return 0;
            if(v.size() == 2) add_clause(v[0], v[1], 0, 0);
        }
    }
    int cnt = 0;
    Loop(i,0,n)
    {
        int d = A[i].size();
        Loop(j,0,d)
        {
            add_clause(A[i][j], N+cnt+  j, 1, 0); // ~e v pre
            add_clause(A[i][j], N+cnt+d+j, 1, 0); // ~e v suf
        }
        Loop(j,1,d)
        {
            add_clause(N+cnt+j, N+cnt+j-1, 1, 0); // ~pre[i] v pre[i-1]
            add_clause(N+cnt+j, A[i][j-1], 1, 1); // ~pre[i] v ~e[i-1]
        }
        Loop(j,0,d-1)
        {
            add_clause(N+cnt+d+j, N+cnt+d+j+1, 1, 0); // ~suf[i] v suf[i+1]
            add_clause(N+cnt+d+j, A[i][j+1], 1, 1);   // ~suf[i] v ~e[i+1]
        }
        cnt += 2*d;
    }
    return solve_sat();
}

int bin()
{
    int l = 0, r = 1e9+10;
    while(l < r)
    {
        //cerr << l << ' ' << r << '\n';
        int m = (l+r)/2;
        int cnt = 0;
        Loop(i,0,::m)
            if(t[i] <= r && t[i] > m)
                add_clause(i, i, 1, 1), ++cnt;
        if(solve_sat())
            r = m;
        else
            l = m+1, remove_clause(cnt);
    }
    solve_sat();
    return l;
}

int main()
{
    FAST;
    cin >> n >> m;
    Loop(e,0,m)
    {
        int u, v, c;
        cin >> u >> v >> c >> t[e];
        u--; v--;
        Ac[u][c].push_back(e);
        Ac[v][c].push_back(e);
        A[u].push_back(e);
        A[v].push_back(e);
    }
    if(!prepare()) Kill("No");
    cout << "Yes\n";
    int ans = bin();
    int cnt = 0;
    Loop(i,0,m) cnt += get_ans(i);
    cout << ans << ' ' << cnt << '\n';
    Loop(i,0,m) if(get_ans(i)) cout << i+1 << ' ';
}