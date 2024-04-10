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

const ll MAXN = 100;
vector<ll> adj[MAXN];
ll n , m , ans = 1 , x , mark[MAXN];

void dfs(ll v)
{
    x++;
    mark[v] = 1;
    for(int u : adj[v])
        if(!mark[u])
            dfs(u);
}

int main()
{
    fast_io;

    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        ll v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(!mark[i])
        {
            x = 0;
            dfs(i);
            ans *= pw(2 , x - 1);
        }
    }
    cout << ans << endl;

    return 0;
}