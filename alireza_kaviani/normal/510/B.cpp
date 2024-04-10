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

const int MAXN = 1e4 + 10 , MAXK = 50;
int n , m , dx[] = {1 , 0} , dy[] = {0 , 1};
string s[MAXK];
vector<int> adj[MAXN];
bool mark[MAXN];

int dfs(int v , int p = -1 , int sz = 1)
{
    int ans = 0;
    mark[v] = 1;
    for(int u : adj[v])
    {
        if(!mark[u])
        {
            ans |= dfs(u , v , sz + 1);
        }
        else if(u != p)
        {
            if(sz >= 4)
            {
                return 1;
            }
        }
    }
    return ans;
}

int main()
{
    fast_io;

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++)    cin >> s[i];

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            for(int k = 0 ; k < 2 ; k++)
            {
                int x = dx[k] + i , y = dy[k] + j;
                if(x < n && y < m && s[i][j] == s[x][y])
                {
                    adj[i * m + j].push_back(x * m + y);
                    adj[x * m + y].push_back(i * m + j);
                }
            }
        }
    }

    for(int i = 0 ; i < n * m ; i++)
    {
        if(!mark[i])
        {
            if(dfs(i))
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}