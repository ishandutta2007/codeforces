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
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 2e5 + 10;
vector<ll> adj[MAXN];
ll n , sum , p[MAXN] , mark[MAXN] , s[MAXN] , a[MAXN];

void dfs(ll v , ll sum)
{
    if(s[v] != -1)
    {
        a[v] = s[v] - sum;
    }
    if(s[v] == -1)
    {
        ll mn = 8e18;
        for(ll u : adj[v])
        {
            if(!mark[u])    mn = min(mn , s[u]);
        }
        a[v] = (mn == 8e18 ? 0 : mn - sum);
    }
    mark[v] = 1;
    for(ll u : adj[v])
    {
        if(!mark[u])
        {
            dfs(u , sum + a[v]);
        }
    }
}

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> n;
    for(ll i = 2 ; i <= n ; i++)
    {
        cin >> p[i];
        adj[p[i]].push_back(i);
        adj[i].push_back(p[i]);
    }

    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> s[i];
        if(s[i] == -1)  a[i] = 0;
    }
    dfs(1 , 0);

    for(ll i = 1 ; i <= n ; i++)
    {
        if(a[i] < 0)    return cout << -1 << endl , 0;
        sum += a[i];
    }
    cout << sum << endl;

    return 0;
}