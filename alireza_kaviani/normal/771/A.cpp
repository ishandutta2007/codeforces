#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

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

const int MAXN = 150010;
vector<int> adj[MAXN];
ll V = 0 , E = 0;
bool mark[MAXN];

void dfs(int v)
{
    mark[v] = 1;
    V++;
    E += adj[v].size();
    for(int u : adj[v])
    {
        if(!mark[u])
            dfs(u);
    }
}

int main()
{
    fast_io;

    int n , m;
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++)
    {
        int u  , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0 ; i < n ; i++)
    {
        V = 0 ; E = 0 ;
        if(!mark[i])    dfs(i);

        if(V * (V - 1) != E)
        {
            return cout << "NO" << endl , 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}