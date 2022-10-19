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
inline int input(){int n; cin >> n ; return n;}

const int MAXN = 1e5 + 100;
vector<int> adj[MAXN];
bool ok = true , mark[MAXN];
int cmp[MAXN];

void dfs(int v , int p = -1)
{
    mark[v] = 1;
    cmp[v] = (p == -1 ? 1 : cmp[p] * -1);

    for(int u : adj[v])
    {
        if(!mark[u])
        {
            dfs(u , v);
        }
        else
        {
            if(cmp[v] == cmp[u])
            {
                ok = false;
            }
        }
    }
}

int main()
{
    fast_io;

    int n , m;
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++)
    {
        int v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    for(int i = 1 ; i <= n ; i++)
    {
        if(!mark[i])
        {
            dfs(i);
        }
    }
    if(!ok)
    {
        cout << -1 << endl;
        return 0;
    }

    vector<int> c1 , c2;
    for(int i = 1 ; i <= n ; i++)
    {
        if(mark[i])
        {
            if(cmp[i] == 1)
            {
                c1.push_back(i);
            }
            else
            {
                c2.push_back(i);
            }
        }
    }

    cout << c1.size() << endl;
    for(int i : c1)     cout << i << ends;
    cout << endl << c2.size() << endl;
    for(int i : c2)     cout << i << ends;

    return 0;
}