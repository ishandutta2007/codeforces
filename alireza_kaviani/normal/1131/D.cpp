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

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

vector<ll> adj[MAXN];
ll n , m , par[MAXN] , inDeg[MAXN] , dis[MAXN];
string s[MAXN];

ll Find(ll v)
{
    return (par[v] == -1 ? v : par[v] = Find(par[v]));
}

void Union(ll v , ll u)
{
    ll pv = Find(v) , pu = Find(u);
    if(pv != pu)    par[pu] = pv;
}

ll toposort()
{
    ll sz = 0 , t = 0;
    queue<ll> q;
    for(ll i = 0 ; i < n + m ; i++)
    {
        if(i == Find(i))
        {
            sz++;
            if(inDeg[i] == 0)
            {
                dis[i] = 1;
                q.push(i);
            }
        }
    }

    while(!q.empty())
    {
        ll v = q.front();
        q.pop();
        t++;

        for(ll u : adj[v])
        {
            if(--inDeg[u] == 0)
            {
                dis[u] = dis[v] + 1;
                q.push(u);
            }
        }
    }
    return (sz == t);
}

int main()
{
    fast_io;
    fill(par , par + MAXN , -1);

    cin >> n >> m;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> s[i];
        for(ll j = 0 ; j < m ; j++)
        {
            if(s[i][j] == '=')
            {
                Union(i , j + n);
            }
        }
    }

    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            ll v = Find(i) , u = Find(j + n);
            if(s[i][j] == '=')  continue;
            if(s[i][j] == '<')  swap(v , u);
            adj[u].push_back(v);
            inDeg[v]++;
        }
    }

    if(!toposort()) return cout << "No" << endl , 0;

    cout << "Yes" << endl;
    for(ll i = 0 ; i < n ; i++) cout << dis[Find(i)] << sep;
    cout << endl;
    for(ll i = 0 ; i < m ; i++) cout << dis[Find(i + n)] << sep;

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