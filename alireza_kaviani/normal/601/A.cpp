#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const int MAXN = 410 , INF = 2e9;
int adj[MAXN][MAXN] , d[MAXN] , ans = 0 , n , m;

void bfs(int v , int t)
{
    fill(d , d + MAXN , INF);

    queue<int> q;
    q.push(v);
    d[v] = 0;

    while(!q.empty())
    {
        v = q.front();
        q.pop();

        for(int u = 1 ; u <= n ; u++)
        {
            if(adj[v][u] == t && d[u] == INF)
            {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    ans = max(ans , d[n]);
}

int main()
{
    fast_io;

    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        int v , u;
        cin >> v >> u;
        adj[v][u] = 1;
        adj[u][v] = 1;
    }

    bfs(1 , 0);
    bfs(1 , 1);
    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}