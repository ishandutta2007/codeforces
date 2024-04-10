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

const ll MAXN = 510;
ll n , m , q , x , y , t , ans , cnt[MAXN] , p[MAXN][MAXN];

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/

    cin >> n >> m >> q;
    for(ll i = 1 ; i <= n ; i++)
    {
        t = 0;
        for(ll j = 1 ; j <= m ; j++) cin >> p[i][j];
        for(ll j = 1 ; j <= m ; j++)
        {
            if(p[i][j] == 0)    t = 0;
            else    t++;
            cnt[i] = max(cnt[i] , t);
        }
    }

    while(q--)
    {
        t = 0;
        ans = 0;
        cin >> x >> y;
        p[x][y] = 1 - p[x][y];
        cnt[x] = 0;
        for(ll i = 1 ; i <= m ; i++)
        {
            if(p[x][i] == 0)    t = 0;
            else    t++;
            cnt[x] = max(cnt[x] , t);
        }

        for(ll i = 0 ; i < MAXN ; i++)  ans = max(ans , cnt[i]);
        cout << ans << endl;
    }

    return 0;
}