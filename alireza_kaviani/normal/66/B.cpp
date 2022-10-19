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

const ll MAXN = 1010;
vector<ll> adj[MAXN];
ll n , cnt , ans , p[MAXN] , mark[MAXN];

void dfs(ll v)
{
    cnt++;
    mark[v] = 1;
    for(ll u : adj[v])
    {
        if(!mark[u])
        {
            dfs(u);
        }
    }
}

int main()
{
    fast_io;

    cin >> n;
    for(ll i = 0 ; i < n ; i++) cin >> p[i];

    for(ll i = 0 ; i < n ; i++)
    {
        if(i != 0 && p[i] >= p[i - 1])
        {
            adj[i].push_back(i - 1);
        }
        if(i != n - 1 && p[i] >= p[i + 1])
        {
            adj[i].push_back(i + 1);
        }
    }

    for(ll i = 0 ; i < n ; i++)
    {
        cnt = 0;
        fill(mark , mark + MAXN , 0);
        dfs(i);
        ans = max(ans , cnt);
    }
    cout << ans << endl;

    return 0;
}