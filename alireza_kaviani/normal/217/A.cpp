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

const int MAXN = 1e3 + 10;
bool mark[MAXN];
int x[MAXN] , y[MAXN] , n , ans = 0;

void dfs(int v)
{
    mark[v] = 1;
    for(int u = 1 ;u <= n ; u++)
    {
        if((x[u] == x[v] || y[u] == y[v]) && !mark[u])
        {
            dfs(u);
        }
    }
}

int main()
{
    fast_io;

    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> x[i] >> y[i];
    }

    for(int i = 1 ;i <= n ; i++)
    {
        if(!mark[i])
        {
            ans++;
            dfs(i);
        }
    }
    cout << ans - 1 << endl;

    return 0;
}