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
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

vector<ll> adj[MAXN];
ll n , ans , v , u , sum , cost , ind = 1 , val[MAXN] , p[MAXN] , sz[MAXN];

void DFS1(ll v , ll par = -1 , ll h = 0)
{
    cost += h * val[v];
    p[ind++] = val[v];
    sz[v] = 1;
    for(ll u : adj[v])
    {
        if(u != par)
        {
            DFS1(u , v , h + 1);
            sz[v] += sz[u];
        }
    }
}

void DFS2(ll v , ll par = -1 , ll t = 1)
{
    if(par != -1)   cost = cost - (p[t + sz[v] - 1] - p[t - 1]) * 2 + sum;
    ans = max(ans , cost);

    for(ll u : adj[v])
    {
        if(u != par)
        {
            DFS2(u , v , ++ind);
        }
    }

    if(par != -1)   cost = cost + (p[t + sz[v] - 1] - p[t - 1]) * 2 - sum;
}

int main()
{
    fast_io;
    set_random;

    cin >> n;
    for(ll i = 1 ; i <= n ; i++)    cin >> val[i];
    for(ll i = 1 ; i < n ; i++)
    {
        cin >> v >> u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS1(1);
    partial_sum(p , p + MAXN , p);
    sum = p[MAXN - 1];
    ind = 1;
    DFS2(1);
    cout << ans << endl;

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