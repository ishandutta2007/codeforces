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

const ll MAXN = 110;
vector<pll> point[MAXN];
ll n , m , v , u , ind = 1 , mark[MAXN];

int main()
{
    fast_io;
    cin >> n >> m;

    for(ll i = 0 ; i < m; i++)
    {
        cin >> v >> u;
        point[v].push_back({ind , v});
        point[u].push_back({ind , u});
        ind++;
        mark[v] = mark[u] = 1;
    }

    for(ll i = 1 ; i <= n ; i++)
    {
        if(!mark[i])
        {
            point[i].push_back({ind , i});
            ind++;
        }
    }

    for(ll i = 1 ; i <= n ; i++)
    {
        cout << point[i].size() << endl;
        for(ll j = 0 ; j < point[i].size() ; j++)
        {
            cout << point[i][j].X << ends << point[i][j].Y << endl;
        }
    }

    return 0;
}