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

const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
int par[MAXN] , cnt[MAXN] , mark[MAXN];

void bfs(int v)
{
    queue<int> q;
    mark[v] = 1;
    par[v] = 0;
    cnt[0]++;
    q.push(v);
    while(!q.empty())
    {
        v = q.front();
        q.pop();
        for(int u : adj[v])
        {
            if(!mark[u])
            {
                par[u] = v;
                cnt[par[u]]++;
                q.push(u);
                mark[u] = 1;
            }
        }
    }
}

int main()
{
    fast_io;

    int n , x = 1;
    cin >> n;

    for(int i = 0 ; i < n - 1 ; i++)
    {
        int v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    bfs(1);
    queue<int> q;
    q.push(0);
    for(int i = 0 ; i < n ; i++)
    {
        int t;
        cin >> t;
        if(par[t] != q.front())   return cout << "NO" << endl , 0;
        cnt[par[t]]--;
        q.push(t);
        while(!q.empty() && cnt[q.front()]==0)    q.pop();
    }
    cout << "YES" << endl;
    

    return 0;
}