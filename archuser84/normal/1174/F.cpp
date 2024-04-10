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
//#pragma GCC optimize ("O0")
using namespace std;

const int N = 200'010;
vector<int> A[N];
vector<int> lyr[N]; int h[N];
bool vis[N] = {};
bool red[N] = {};
int cnt[N] = {};
int cntv[N] = {};
int par[N] = {};
int n;

void dfs1(int u, int p, int h)
{
    ::h[u] = h;
    par[u] = p;
    lyr[h].push_back(u);
    for(int v : A[u])
        if(v != p)
            dfs1(v, u, h+1);
}


void trm(int u)
{
    printf("! %d\n", u+1);
    fflush(stdout);
}

int d(int u)
{
    printf("d %d\n", u+1);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}
int s(int u)
{
    printf("s %d\n", u+1);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans-1;
}

void dfs(int u, int p)
{
    cnt[u] = red[u];
    cntv[u] = 1;
    if(red[u]) return;
    for(int v : A[u])
        if(v != p && !vis[u]){
            dfs(v, u);
            cnt[u] += cnt[v];
            cntv[u] += cntv[v];
        }
}

int cent(int u, int p, int c)
{
    for(int v : A[u])
        if(!vis[v] && v != p && cntv[v] > c/2)
            return cent(v, u, c);
    return u;
}

void solve(int u, int h)
{
    if(red[u]) return trm(u);
    dfs(u, -1);
    int v = cent(u, -1, cntv[u]);
    vis[v] = 1;
    if(cnt[v] == cnt[u])
        return solve(s(v), h);
    if(d(v) + ::h[v] != h)
        return solve(u, h);
    else
        return solve(s(v), h);
}

int main()
{
    scanf("%d", &n);
    Loop(i,1,n)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    dfs1(0, -1, 0);
    int x = d(0);
    for(int v : lyr[x]) red[v] = 1;
    solve(0, x);
}