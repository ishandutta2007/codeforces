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
ll n , v , u , ans , p[MAXN] , pr[MAXN];

vector<ll> primeDivisor(ll x)
{
    vector<ll> res;
    for(ll i = 1 ; i * i <= x ; i++)
    {
        if(x % i == 0)
        {
            if(pr[i])   res.push_back(i);
            if(i * i != x && pr[x / i]) res.push_back(x / i);
        }
    }
    return res;
}

map<ll , ll> dfs(ll v , ll par = -1)
{
    map<ll , ll> res;
    for(ll u : adj[v])
    {
        if(u != par)
        {
            map<ll , ll> mp = dfs(u , v);
            ll x = __gcd(p[v] , p[u]);

            for(ll i : primeDivisor(x))
            {
                ans = max(ans , res[i] + mp[i] + 1);
                res[i] = max(res[i] , mp[i]);
            }
        }
    }

    for(ll i : primeDivisor(p[v]))
    {
        res[i]++;
        ans = max(ans , res[i]);
    }
    return res;
}

int main()
{
    fast_io;
    set_random;

    fill(pr , pr + MAXN , 1);
    pr[1] = 0;
    for(ll i = 2 ; i * i <= MAXN ; i++)
    {
        if(pr[i])
        {
            for(ll j = i * i ; j < MAXN ; j += i)
            {
                pr[j] = 0;
            }
        }
    }

    cin >> n;
    for(ll i = 1 ; i <= n ; i++)    cin >> p[i];
    for(ll i = 1 ; i < n ; i++)
    {
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    dfs(1);
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