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

const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
int  start[MAXN] , vet[MAXN] ,sz[MAXN] , t = 1;

void dfs(int v , int p = -1)
{
    start[v] = t;
    vet[t] = v;
    t++;

    sz[v] = 1;
    for(int i = 0 ; i < adj[v].size() ; i++)
    {
        int u = adj[v][i];
        if(u != p)
        {
            dfs(u , v);
            sz[v] += sz[u];
        }
    }
}

int main()
{
    fast_io;

    int n , q;
    cin >> n >> q;

    for(int i = 2 ; i <= n ; i++)
    {
        int p;cin >> p;
        adj[p].push_back(i);
    }
    dfs(1);

    for(int i = 0 ; i < q ; i++)
    {
        int u , k;
        cin >> u >> k;
        if(k > sz[u])   cout << -1 << endl;
        else
        {
            cout << vet[start[u] + k - 1] << endl;
        }
    }


    return 0;
}