#include <bits/stdc++.h>
using namespace std;

template<class t>
void operator >>(istream &in , vector<t> &vec)
{
    for(int i = 0 ; i < vec.size() ; i++)
    {
        cin >> vec[i];
    }
}
template<class t>
void operator << (ostream &out , vector<t> &vec)
{
    for(int i = 0 ; i < vec.size() ; i++)
    {
        cout << vec[i] << " ";
    }
}

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

const int MAXN = 500;
vector<int> adj[MAXN];
bool mark[MAXN];

void dfs(int v)
{
    mark[v] = 1;
    for(int u : adj[v])
    {
        if(mark[u] == 0)
        {
            dfs(u);
        }
    }
}

int main()
{
    fast_io;

    int n , m , ans = 0 , st = -1;
    cin >> n >> m;

    for(int i = 0 ;i < n ; i++)
    {
        int k;
        cin >> k;
        for(int j = 0 ;j < k ; j++)
        {
            int x;
            cin >> x;
            adj[i].push_back(x + 200);
            adj[x + 200].push_back(i);
        }
        (k != 0 ? st = i : st = st);
    }

    if(st != -1)
    {
        dfs(st);
    }
    for(int i = 0; i < n ; i++)
    {
        if(mark[i] == 0)
        {
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}