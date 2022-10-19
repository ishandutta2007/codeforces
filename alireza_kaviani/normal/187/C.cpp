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
//#define endl                        '\n'
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

vector<ll> adj[MAXN];
ll n , m , k , v , u , s , t , l , r , vol[MAXN] , dist[MAXN] , mark[MAXN] , par[MAXN];

ll Find(ll v)
{
    return (par[v] == -1 ? v : par[v] = Find(par[v]));
}

void Union(ll v , ll u)
{
    ll pv = Find(v) , pu = Find(u);
    if(pu != pv)    par[pu] = pv;
}

void bfs(ll x)
{
    queue<ll> q;
    for(ll i = 1 ; i <= n ; i++)
    {
        if(vol[i])
        {
            dist[i] = 0;
            mark[i] = 1;
            q.push(i);
        }
    }

    while(!q.empty())
    {
        ll v = q.front();
        q.pop();

        if(dist[v] >= x) continue;

        for(ll u : adj[v])
        {
            if(!mark[u])
            {
                dist[u] = dist[v] + 1;
                mark[u] = 1;
                q.push(u);
                Union(v , u);
            }
            else if(dist[v] + dist[u] < x)   Union(v , u);
        }
    }
}

ll check(ll x)
{
    fill(mark , mark + MAXN , 0);
    fill(dist , dist + MAXN , INF);
    fill(par , par + MAXN , -1);
    bfs(x);
    return (Find(s) == Find(t));
}

int main()
{
    fast_io;

    cin >> n >> m >> k;
    for(ll i = 0 ; i < k ; i++) vol[input()] = 1;

    for(ll i = 0 ; i < m ; i++)
    {
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    cin >> s >> t;
    vol[s] = vol[t] = 1;
    l = -1 , r = 1e9;
    while(r - l > 1)
    {
        ll mid = (l + r) / 2;
        if(check(mid))  r = mid;
        else            l = mid;
    }
    cout << (r == ll(1e9) ? -1 : r) << endl;

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