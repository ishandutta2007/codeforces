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

const int MAXN = 2e5 + 100;
vector<int> adj[MAXN];
bool visited[MAXN];
bool cycle = false , adjs = true;

void dfs(int v , int p = -1)
{
    visited[v] = true;
    if(adj[v].size() != 2)
    {
        adjs = false;
    }

    for(int u : adj[v])
    {
        if(u != p)
        {
            if(visited[u])
            {
                cycle = true;
            }
            else
            {
                dfs(u , v);
            }
        }
    }
}

int main()
{
    fast_io;

    int n , k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0 ;i < n; i++)
    {
        cin >> a[i];
    }

    Sort(a);

    if(k == 0)
    {
        if(a[0] == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
        return 0;
    }

    if(k != n)
    {
        if(a[k] == a[k - 1])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << a[k - 1] << endl;

    return 0;
}