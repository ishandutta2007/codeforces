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
#define tab                         '\t'
#define sep                         ' '
#define endl                        '\n'
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 1e4;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

vector<ll> adj[MAXN];
ll n , m , v , u , ans = INF , mark[MAXN];

void dfs(ll root , ll v , ll d = 0 , ll t = 0)
{
    mark[v] = 1;
    if(d == 3)
    {
        mark[v] = 0;
        return;
    }
    for(ll u : adj[v])
    {
        if(!mark[u])
        {
            dfs(root , u , d + 1 , t + adj[v].size());
        }
        if(d == 2 && u == root)
        {
            ans = min(ans , t + adj[v].size() - 6);
        }
    }
    mark[v] = 0;
}

int main()
{
    fast_io;

    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++)
    {
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    for(ll i = 1 ; i <= n ; i++)
    {
        fill(mark , mark + MAXN , 0);
        dfs(i , i);
    }
    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/