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
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const int MAXN = 26;
vector<int> adj[MAXN];
int p[MAXN] , sz = 0;
char ans[MAXN];
bool mark[MAXN];

void dfs(int v)
{
    mark[v] = 1;
    for(int u : adj[v])
    {
        if(!mark[u])
        {
            dfs(u);
        }
    }
    p[v] = sz;
    ans[26 - sz - 1] = v + 97;
    sz++;
}

int main()
{
    fast_io;

    int n;
    cin >> n;

    string s[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> s[i];
        if(i == 0)  continue;
        for(int j = 0 ; j < s[i - 1].size() ; j++)
        {
            if(s[i][j] != s[i - 1][j])
            {
                adj[s[i - 1][j] - 97].push_back(s[i][j] - 97);
                break;
            }
            if(j == s[i].size() - 1)   return cout << "Impossible" << endl , 0;
        }
    }

    for(int i = 0 ; i < MAXN ; i++)
    {
        if(!mark[i])    dfs(i);
    }

    for(int i = 0 ; i < MAXN ; i++)
    {
        for(int j : adj[i])
        {
            if(p[i] < p[j]) return cout << "Impossible" << endl , 0;
        }
    }

    for(int i = 0 ; i < MAXN ; i++) cout << ans[i];

    return 0;
}