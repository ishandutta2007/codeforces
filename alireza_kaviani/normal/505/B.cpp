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
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 110;
vector<ll> adj[MAXN][MAXN];
ll n , m , q , u , v , c , ans , ind , mark[MAXN * MAXN][MAXN];

void dfs(ll col , ll v)
{
    mark[ind][v] = 1;
    for(ll u : adj[col][v])
    {
        if(!mark[ind][u])
        {
            dfs(col , u);
        }
    }
}

int main()
{
    fast_io;

    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++)
    {
        cin >> u >> v >> c;
        adj[c][v].push_back(u);
        adj[c][u].push_back(v);
    }

    cin >> q;
    while(q--)
    {
        cin >> v >> u;
        ans = 0;
        for(ll i = 0 ; i <= 100 ; i++)
        {
            dfs(i , v);
            if(mark[ind][u])    ans++;
            ind++;
        }
        cout << ans << endl;
    }

    return 0;
}