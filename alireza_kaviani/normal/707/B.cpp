#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MAXN = 1e5 + 10;
vector<pii> adj[MAXN];
bool mark[MAXN];

int main()
{
    fast_io;

    int n , m , k , ans = 2e9;
    cin >> n >> m >> k;

    for(int i = 0 ; i < m ; i++)
    {
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({v , w});
        adj[v].push_back({u , w});
    }

    int a[k];
    for(int i = 0; i < k ; i++)
    {
        cin >> a[i];
        mark[a[i]] = 1;
    }

    for(int i = 0 ;i < k ; i++)
    {
        for(int j = 0 ;j < adj[a[i]].size() ; j++)
        {
            if(mark[adj[a[i]][j].X] == 0)
            {
                ans = min(ans , adj[a[i]][j].Y);
            }
        }
    }

    cout << (ans == 2e9 ? -1 : ans) << endl;

    return 0;
}