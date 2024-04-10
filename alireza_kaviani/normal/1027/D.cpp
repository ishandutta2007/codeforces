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
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
int mark[MAXN] , c[MAXN] , p[MAXN] , ans = 0 , mn = 2e9;

void dfs(int v)
{
    mark[v] = 2;
    for(int u : adj[v])
    {
        if(mark[u] != 2)    dfs(u);
    }
}

int main()
{
    fast_io;

    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++)   cin >> c[i];
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }

    int t = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        if(mark[i] != 2)
        {
            int a = i;
            while(mark[a] == 0)  {mark[a] = 1 ; a = p[a];}
            int x = c[a] , y = a;
            a = p[a];
            while(a != y)   {x = min(x , c[a]) ; a = p[a] ;}
            ans += x;
            dfs(y);
        }
    }
    cout << ans << endl;

    return 0;
}