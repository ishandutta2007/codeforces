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
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 1e4 + 10;
vector<ll> adj[MAXN];
ll n , ans = 0 , c[MAXN];

void dfs(ll v , ll col)
{
    if(col != c[v]) ans++;
    for(ll u : adj[v])
    {
        dfs(u , c[v]);
    }
}

int main()
{
    fast_io;

    cin >> n;
    for(ll i = 2 ; i <= n ; i++)    adj[input()].push_back(i);
    for(ll i = 1 ; i <= n ; i++)    cin >> c[i];
    dfs(1 , -1);
    cout << ans << endl;

    return 0;
}