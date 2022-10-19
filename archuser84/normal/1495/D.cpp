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

const int N = 410;
int d[N][N]={};
vector<int> A[N];
int n, m;
ll ans[N][N]={};
const int mod = 998244353;

void bfs(int s)
{
    static bool vis[N];
    queue<int> q;
    q.push(s);
    d[s][s] = 0;
    memset(vis, 0, n);
    vis[s] = 1;
    while(q.size())
    {
        int u = q.front(); q.pop();
        for(int v : A[u])
        {
            if(!vis[v])
            {
                vis[v] = 1;
                d[s][v] = d[s][u] + 1;
                q.push(v);
            }
        }
    }
}

void calc_ans(int a, int b)
{
    static bool mark[N];
    memset(mark, 0, n);
    int cnt = 0;
    Loop(i,0,n)
    {
        if(d[a][i] + d[i][b] == d[a][b])
        {
            cnt++;
            mark[i] = 1;
        }
    }
    if(cnt != d[a][b]+1) return;
    ans[a][b] = 1;
    Loop(v,0,n)
    {
        if(mark[v]) continue;
        ll cnt = 0;
        for(int u : A[v]) // u is par
        {
            if(d[a][v] == d[a][u]+1 && d[b][v] == d[b][u]+1) ++cnt;
        }
        ans[a][b] = ans[a][b]*cnt % mod;
    }
    ans[b][a] = ans[a][b];
}

int main()
{
    FAST;
    cin >> n >> m;
    Loop(i,0,m)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    //bfs(2);
    Loop(i,0,n) bfs(i);
    //calc_ans(2, 2);
    Loop(i,0,n)
        Loop(j,i,n)
            calc_ans(i, j);

    Loop(i,0,n){
        Loop(j,0,n)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
}