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

const ll MAXN = 1e5 + 10;
vector<ll> adj[MAXN];
ll start[MAXN];

void dfs(ll v , ll p = -1)
{
    start[v] = (p == -1 ? 1 : start[p] + 1);
    for(ll u : adj[v])
    {
        if(u != p)
        {
            dfs(u , v);
        }
    }
}

int main()
{
    fast_io;

    ll n , odd = 0 , even = 0;
    cin >> n;

    for(int i = 1 ; i < n ; i++)
    {
        ll v , u;
        cin >> v >> u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    for(int i = 1 ; i <= n ; i++)
    {
        if(start[i] & 1)    odd++;
        else    even++;
    }

    cout << odd * even - (n - 1);

    return 0;
}