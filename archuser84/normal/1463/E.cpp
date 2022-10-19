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

const int N = 300'010;
int par[N];
int nxt[N] = {};
int pre[N] = {};
int cnt[N] = {};
bool vis[N] = {};
vector<int> A[N];
vector<int> ans;
int n, k;

void dfs(int, bool);

void ddfs(int u)
{
    vis[u] = 1;
    ans.push_back(u);
    if(!vis[par[u]]) ans.clear();
    if(nxt[u] != 0) ddfs(nxt[u]);
    dfs(u, 0);
}

void dfs(int u, bool add = 1)
{
    if(pre[u] && add)
    {
        cnt[pre[u]]--;
        if(cnt[pre[u]]) return;
        ddfs(pre[u]);
        return;
    }
    vis[u] = 1;
    if(add) ans.push_back(u);
    for(int v : A[u])
        if(!vis[v])
            dfs(v);
}

int get_root(int u)
{
    if(pre[u] == 0){
        pre[u] = u;
        cnt[u]++;
        return u;
    }
    pre[u] = get_root(pre[u]);
    cnt[pre[u]]++;
    return pre[u];
}

int main()
{
    FAST;
    cin >> n >> k;
    Loop(i,1,n+1)
    {
        cin >> par[i];
        A[par[i]].push_back(i);
    }
    vis[0] = 1;
    Loop(i,0,k)
    {
        int x, y;
        cin >> x >> y;
        nxt[x] = y;
        pre[y] = x;
    }
    Loop(i,1,n+1)
    {
        if(pre[i] && !nxt[i])
            get_root(i);
    }
    Loop(i,1,n+1)
    {
        if(pre[i] && pre[i] == pre[par[i]]) cnt[pre[i]]--;
    }
    dfs(0, 0);
    if(ans.size() != n) Kill(0);
    for(int x : ans)
        cout << x << ' ';
}