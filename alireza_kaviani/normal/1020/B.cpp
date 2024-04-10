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

const int MAXN = 1010;
vector<int> adj[MAXN];
bool mark[MAXN];

int dfs(int v)
{
    mark[v] = 1;
    for(int i = 0 ; i < adj[v].size() ; i++)
    {
        int u = adj[v][i];
        if(mark[u]) return u;
        else return dfs(u);
    }
    return v;
}

int main()
{
    fast_io;

    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++)
    {
        int p;
        cin >> p;
        adj[i].push_back(p);
    }

    for(int i = 1 ; i <= n ; i++)
    {
        fill(mark , mark + MAXN , 0);
        cout << dfs(i) << ends;
    }

    return 0;
}