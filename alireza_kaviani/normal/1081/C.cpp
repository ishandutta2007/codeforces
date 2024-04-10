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
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 2010 , MOD = 998244353;
ll n , m , k , c[MAXN][MAXN];

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/

    c[0][0] = 1;
    for(ll i = 1 ; i < MAXN ; i++)
    {
        c[i][0] = 1;
        for(ll j = 1 ; j < MAXN ; j++)
        {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }

    cin >> n >> m >> k;
    cout << (c[n - 1][k] * m % MOD * pw(m - 1 , k , MOD)) % MOD << endl;

    return 0;
}