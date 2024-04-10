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
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 1e3 + 10;
ll n , a[2] , b[2] , c[2] , mark[MAXN][MAXN] , dx[] = {1 , 1 , 1 , 0 , 0 , -1 , -1 , -1} , dy[] = {-1 , 0 , 1 , -1 , 1 , -1 , 0 , 1};

void dfs(ll x , ll y)
{
    mark[x][y] = 1;
    for(ll i = 0 ; i < 8 ; i++)
    {
        for(ll j = 0 ; j < 8 ; j++)
        {
            if(1 <= x + dx[i] && x + dx[i] <= n && 1 <= y + dy[j] && y + dy[j] <= n && !mark[x + dx[i]][y + dy[j]])
            {
                dfs(x + dx[i] , y + dy[j]);
            }
        }
    }
}


int main()
{
    fast_io;

    cin >> n >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
    for(ll i = 1 ; i <= n ; i++)
    {
        for(ll j = 1 ; j <= n ; j++)
        {
            if(i == a[0] || j == a[1] || abs(i - j) == abs(a[0] - a[1]))
            {
                mark[i][j] = 2;
            }
        }
    }
    dfs(b[0] , b[1]);
    cout << (mark[c[0]][c[1]] == 1 ? "YES" : "NO") << endl;

    return 0;
}