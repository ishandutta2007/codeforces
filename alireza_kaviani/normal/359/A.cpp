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
#define tab                         '\t'
#define sep                         ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 100;
ll n , m , ans = 2 , x[MAXN] , y[MAXN] , mp[MAXN][MAXN];

int main()
{
    fast_io;

    cin >> n >> m;
    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            cin >> mp[i][j];
            x[i] |= mp[i][j];
            y[j] |= mp[i][j];
        }
    }

    if(mp[0][0] || mp[0][m - 1] || mp[n - 1][0] || mp[n - 1][m - 1])    return cout << 1 << endl , 0;
    if((x[0] || x[n - 1]) || (y[0] || y[m - 1]))    return cout << 2 << endl , 0;
    cout << 4 << endl;

    return 0;
}