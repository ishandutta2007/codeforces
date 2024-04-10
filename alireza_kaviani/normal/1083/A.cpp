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
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 3e5 + 10;
vector<pll> adj[MAXN];
ll n , v , u , w , p[MAXN] , mark[MAXN] , dp1[MAXN] , dp2[MAXN] , dp3[MAXN];

void dfs(ll v , ll par = -1)
{
    mark[v] = 1;
    ll sum = 0 , leaf = 1;
    for(pll i : adj[v])
    {
        ll u = i.X , w = i.Y;
        if(!mark[u])
        {
            dfs(u , v);
            leaf = 0;
        }
    }

    if(leaf)
    {
        dp2[v] = p[v];
        return;
    }

    vector<ll> vec;
    for(pll i : adj[v])
    {
        ll u = i.X , w = i.Y;
        if(u != par)
        {
            dp1[v] = max({dp1[v] , dp1[u] , dp2[u] , dp3[u]});
            dp2[v] = max(dp2[v] , dp2[u] + p[v] + w);
            vec.push_back(dp2[u] + p[v] + w);
            sort(all(vec) , greater<ll>());
            if(vec.size() > 2)  vec.pop_back();
        }
    }

    sum = vec[0];
    for(ll i = 1 ; i < vec.size() ; i++)
    {
        sum = max(sum , sum + vec[i] - p[v]);
    }
    dp3[v] = max(dp3[v] , sum);
}

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/
    //file_io;

    cin >> n;
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> p[i];
        dp2[i] = p[i];
    }
    for(ll i = 1 ; i < n ; i++)
    {
        cin >> v >> u >> w;
        adj[v].push_back({u , -w});
        adj[u].push_back({v , -w});
    }

    dfs(1);
    cout << max({dp1[1] , dp2[1] , dp3[1]});

    return 0;
}