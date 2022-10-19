#include <bits/stdc++.h>
#include <search.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pld;
typedef pair<string, string> pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll input() {
    ll n;
    cin >> n;
    return n;
}

ll pw(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % md, b / 2, md) % md : pw(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

vector<ll> adj[MAXN];
ll n , v , u , ans , sz[MAXN][2] , dp[MAXN][2];

ll getSize(ll v) {
    return sz[v][0] + sz[v][1];
}

void dfs(ll v , ll p = -1 , ll h = 0)
{
    sz[v][h] = 1;
    for(ll u : adj[v])
    {
        if(u != p)
        {
            dfs(u , v , 1 - h);
            sz[v][0] += sz[u][0];
            sz[v][1] += sz[u][1];
            dp[v][0] += dp[u][0] + sz[u][1 - h];
        }
    }

    ll sum = 0;
    for(ll u : adj[v])
    {
        if(u != p)
        {
            sum += getSize(u) * (getSize(v) - 1 - getSize(u)) - sz[u][h] * (sz[v][h] - 1 - sz[u][h]);
            dp[v][1] += dp[u][0] * (getSize(v) - 1 - getSize(u)) + dp[u][1] + dp[u][0];
        }
    }
    dp[v][1] += sum / 2;
}

int main() {
    fast_io;
    set_random;

    cin >> n;
    for(ll i = 1 ; i < n ; i++)
    {
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    dfs(1);
    cout << dp[1][0] + dp[1][1] << endl;

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