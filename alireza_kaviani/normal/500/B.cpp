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

const int MAXN = 310;
string s[MAXN];
int n , a[MAXN] , mark[MAXN] , ans[MAXN];
vector<int> pos , val , adj[MAXN];

void dfs(int v)
{
    mark[v] = 1;
    val.push_back(a[v]);
    pos.push_back(v);
    for(int i = 0 ; i < adj[v].size() ; i++)
    {
        int u = adj[v][i];
        if(!mark[u])    dfs(u);
    }
}

int main()
{
    fast_io;
    cin >> n;

    for(int i = 0 ; i < n ; i++)    cin >> a[i];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> s[i];
        for(int j = 0 ; j < n ; j++)
        {
            if(s[i][j] == '1')  adj[i].push_back(j);
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(!mark[i])
        {
            val.clear();
            pos.clear();
            dfs(i);
            Sort(val);
            Sort(pos);
            for(int j = 0 ; j < pos.size() ; j++)
            {
                ans[pos[j]] = val[j];
            }
        }
    }
    for(int i = 0 ; i < n ; i++)    cout << ans[i] << ends;
    return 0;
}